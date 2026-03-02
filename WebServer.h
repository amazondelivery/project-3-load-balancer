#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"

class WebServer {
private:
    int remainingTime;
    int serverID;
    char type;

public:
    WebServer(int id);
    WebServer(int id, char type);
    void process(Request req);
    void tick();
    bool isProcessing();
};

#endif