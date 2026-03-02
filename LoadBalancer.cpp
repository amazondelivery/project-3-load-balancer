#include "LoadBalancer.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

/**
 * @brief Constructs a LoadBalancer and initializes its pool of WebServers.
 *
 * @param initialQueue Pointer to the RequestQueue this LoadBalancer will draw from.
 * @param initialServers int Number of WebServers to create on startup.
 */
LoadBalancer::LoadBalancer(RequestQueue* initialQueue, int initialServers) {
    queue = initialQueue;
    time = 0;
    for (int i = 0; i < initialServers; i++) {
        servers.push_back(new WebServer(i + 1));
        std::cout << "LoadBalancer: Added WebServer " << (i + 1) << std::endl;
    }
}

/**
 * @brief Destructor. Frees all dynamically allocated WebServer instances.
 */
LoadBalancer::~LoadBalancer() {
    for (int i = 0; i < servers.size(); i++) {
        std::cout << "LoadBalancer: Deleting WebServer " << (i + 1) << std::endl;
        delete servers[i];
    }
    servers.clear();
}

/**
 * @brief Advances the LoadBalancer by one clock cycle.
 *
 * On each tick:
 * -Each WebServer is ticked.
 * -Idle servers pull the next Request from the queue (firewall-checked)
 * -Every 10 cycles, servers are added or removed based on queue size.
 */
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
        } else if (queue->size() > (80 * servers.size())) {
            int newID = servers.size() + 1;
            servers.push_back(new WebServer(newID));
            std::cout << "LoadBalancer: Added WebServer " << newID << std::endl;
        }
    }
}

/**
 * @brief Checks whether an IP address should be blocked by the firewall.
 *
 * Blocks the following ranges:
 * - 192.168.x.x
 * - 10.x.x.x 
 * - 172.16.x.x through 172.31.x.x 
 * - Any IP below or equal to 20.40.60.80
 *
 * @param ip std::string The IPv4 address to evaluate (e.g. "192.168.1.1").
 * @return bool true if the IP is blocked, false if it is allowed.
 */
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
        (A == 192 && B == 168) ||
        (A == 10) ||
        (A == 172 && B >= 16 && B <= 31) ||
        (A < 20) ||
        (A == 20 && B < 40) ||
        (A == 20 && B == 40 && C < 60) ||
        (A == 20 && B == 40 && C == 60 && D <= 80)
    ) {
        return true;
    }
    return false;
}