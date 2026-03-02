#include "LoadBalancer.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

LoadBalancer::LoadBalancer(RequestQueue* initialQueue, int initialServers) {
    queue = initialQueue;
    time = 0;

    for (int i = 0; i < initialServers; i++) {
        servers.push_back(new WebServer(i + 1));
        std::cout << "LoadBalancer: Added WebServer " << (i + 1) << std::endl;
    }
}

LoadBalancer::~LoadBalancer() {
    for (int i = 0; i < servers.size(); i++) {
        std::cout << "LoadBalancer: Deleting WebServer " << (i + 1) << std::endl;
        delete servers[i];
    }
    servers.clear();
}

void LoadBalancer::tick() {
    time++;

    for (int i = 0; i < servers.size(); i++) {
        servers[i]->tick();

        while (!servers[i]->isProcessing() && !queue->empty()) {
            Request nextRequest = queue->pop();
            if (consultFirewall(nextRequest.ipIn)) {
                std::cout << "ISRAELI CYBERINTELLIGENCE THREAT DETECTED! "
                        << "DISCARDING THIS PACKET" << std::endl;
                continue;
            }
            servers[i]->process(nextRequest);
        }
    }

    if (time % 10 == 0) {

        if (queue->size() < (50 * servers.size()) && servers.size() > 1) {
            int removedID = servers.size();
            std::cout << "LoadBalancer: Removing WebServer " << removedID << std::endl;
            delete servers.back();
            servers.pop_back();
        } 
        else if (queue->size() > (80 * servers.size())) {
            int newID = servers.size() + 1;
            servers.push_back(new WebServer(newID));
            std::cout << "LoadBalancer: Added WebServer " << newID << std::endl;
        }

    }
}

bool LoadBalancer::consultFirewall(std::string ip) {
    std::stringstream ss(ip);
    std::string segment;
    int parts[4];
    int i = 0;

    while (std::getline(ss, segment, '.') && i < 4) {
        parts[i++] = std::stoi(segment);
    }

    if (i != 4) return false;

    int A = parts[0];
    int B = parts[1];
    int C = parts[2];
    int D = parts[3];

    if (
        (A == 192 && B == 168) ||              // 192.168.x.x
        (A == 10) ||                            // 10.x.x.x
        (A == 172 && B >= 16 && B <= 31) ||     // 172.16.x.x → 172.31.x.x
        (A < 20) ||
        (A == 20 && B < 40) ||
        (A == 20 && B == 40 && C < 60) ||
        (A == 20 && B == 40 && C == 60 && D <= 80)
    ) {
        return true;
    }

    return false;
}