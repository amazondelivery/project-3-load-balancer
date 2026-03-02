#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include "WebServer.h"
#include "RequestQueue.h"

class LoadBalancer {
public:
    LoadBalancer(RequestQueue* initialQueue, int initialServers);
    void tick();

private:
    RequestQueue* queue;
    std::vector<WebServer> servers;
    int time;
};

#endif