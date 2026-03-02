#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include "WebServer.h"
#include "RequestQueue.h"
#include "Request.h"

using namespace std;

class LoadBalancer {
public:
    LoadBalancer(RequestQueue* initialQueue, int initialServers);
    void tick();

private:
    RequestQueue* queue;
    vector<WebServer> servers;
};

#endif