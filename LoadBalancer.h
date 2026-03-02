#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include "WebServer.h"
#include "RequestQueue.h"
#include <string>

class LoadBalancer {
public:
    LoadBalancer(RequestQueue* initialQueue, int initialServers);
    ~LoadBalancer();

    void tick();
    bool consultFirewall(std::string ip);

private:
    RequestQueue* queue;
    std::vector<WebServer*> servers;
    int time;
};

#endif