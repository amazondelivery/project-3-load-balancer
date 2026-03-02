#ifndef SWITCH_H
#define SWITCH_H

#include <vector>
#include <string>
#include "WebServer.h"
#include "RequestQueue.h"

class Switch {
public:
    Switch(RequestQueue* initialQueue, int initialServers, char typeChar);
    ~Switch();
    void tick();
    bool consultFirewall(std::string ip);

private:
    RequestQueue* queue;
    std::vector<WebServer*> servers;
    int time;
    char type;
};

#endif