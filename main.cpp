#include <iostream>
#include <WebServer.h>
#include <RequestQueue.h>

using namespace std;

int main() {
    int numServers;
    int secondsRunningLoadBalancer;
    cout << "Enter number of servers: ";
    cin >> numServers;
    cout << "Enter amount of time (in seconds) to run load balancer: ";
    cin >> secondsRunningLoadBalancer;

    RequestQueue* queue = new RequestQueue(numServers * 100);
    WebServer* web_servers = new WebServer[numServers];
    for (int i = 0; i < numServers; i++) {
        web_servers[i] = WebServer();
    }
}