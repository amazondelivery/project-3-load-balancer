#include "LoadBalancer.h"
#include <iostream>
#include <string>

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
        if (!servers[i]->isProcessing() && !queue->empty()) {
            Request nextRequest = queue->pop();
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

bool LoadBalancer::consultFirewall(string ip) {

}