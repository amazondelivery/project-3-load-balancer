#include <iostream>
#include "RequestQueue.h"
#include "LoadBalancer.h"

using namespace std;

int main() {
    int numServers;
    int secondsRunningLoadBalancer;
    cout << "Enter number of servers: ";
    cin >> numServers;
    cout << "Enter amount of time (in clock cycles) to run load balancer: ";
    cin >> secondsRunningLoadBalancer;

    RequestQueue* queue = new RequestQueue(numServers * 100);
    LoadBalancer lb(queue, numServers);
    
    const string BLUE = "\033[34m";
    const string RESET = "\033[0m";

    for (int i = 0; i < secondsRunningLoadBalancer; i++) {
        cout << "" << endl;
        cout << BLUE 
             << "LOG: Clock Cycle #" << i + 1 
             << ". There are " << queue->size() 
             << " remaining Requests waiting to be processed"
             << RESET << endl;

        cout << BLUE
             << "--------------------------------------------------------------"
             << RESET << endl;
        lb.tick();
    }

    cout << "Remaining requests in queue: " << queue->size() << endl;

    delete queue;
    return 0;
}