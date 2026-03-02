#include "LoadBalancer.h"

LoadBalancer::LoadBalancer(RequestQueue* initialQueue, int initialServers) {
    queue = initialQueue;
    for (int i = 0; i < initialServers; i++) {
        servers.push_back(WebServer());
    }
    time = 0;
}

void LoadBalancer::tick() {
    for (int i = 0; i < servers.size(); i++) {
        servers[i].tick();
        if (!servers[i].isProcessing() && !queue->empty()) {
            Request nextRequest = queue->pop();
            servers[i].process(nextRequest);
        }
    }

    if (queue->size() < (50 * servers.size()) && !servers.empty()) {
        servers.pop_back();
    } else if (queue->size() > (80 * servers.size())) {
        servers.push_back(WebServer());
    }
}