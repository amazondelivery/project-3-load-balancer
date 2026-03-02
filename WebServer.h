#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"

class WebServer {
private:
    int remainingTime;
    int serverID;

public:
    WebServer(int id);
    void process(Request req);
    void tick();
    bool isProcessing();
};

#endif