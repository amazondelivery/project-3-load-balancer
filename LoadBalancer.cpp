#include <WebServer.h>
#include <RequestQueue.h>
#include <vector>
#include <Request.h>

using namespace std;

class LoadBalancer {    
public:
    LoadBalancer(RequestQueue* initialQueue, int initialServers) {
        queue = initialQueue;

        for (int i = 0; i < initialServers; i++) {
            servers.push_back(WebServer());
        }
    }

    void tick() {
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

private:
    RequestQueue* queue;
    vector<WebServer> servers;
    int time = 0;
};