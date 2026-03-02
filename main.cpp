#include <iostream>
#include "RequestQueue.h"
#include "LoadBalancer.h"
#include "Switch.h"

using namespace std;

/*
int main() {
    const string PURPLE = "\033[35m";
    const string GREEN = "\033[32m";
    const string RESET = "\033[0m";
    const string BLUE = "\033[34m";

    cout << PURPLE << "Time per task ranges from 1-5 clock cycles" << RESET << endl;
    int numServers;
    int secondsRunningLoadBalancer;

    cout << GREEN << "Enter number of servers: " << RESET;
    cin >> numServers;
    cout << GREEN << "Enter amount of time (in clock cycles) to run load balancer: " << RESET;
    cin >> secondsRunningLoadBalancer;

    RequestQueue* queue = new RequestQueue(numServers * 100);
    LoadBalancer lb(queue, numServers);

    cout << PURPLE << "We will be starting with " << numServers * 100 << " requests" << RESET << endl;
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
*/

int main() {
    const string PURPLE = "\033[35m";
    const string GREEN = "\033[32m";
    const string RESET = "\033[0m";
    const string BLUE = "\033[34m";

    cout << PURPLE << "Time per task ranges from 1-5 clock cycles" << RESET << endl;
    int numServers;
    int secondsRunningSwitches;

    cout << GREEN << "Enter number of servers for each switch: " << RESET;
    cin >> numServers;
    cout << GREEN << "Enter amount of time (in clock cycles) to run switches: " << RESET;
    cin >> secondsRunningSwitches;

    RequestQueue* queue = new RequestQueue(numServers * 100);
    Switch streamingSwitch(queue, numServers, 'S');
    Switch processingSwitch(queue, numServers, 'P');

    cout << PURPLE << "We will be starting with " << numServers * 100 << " requests" << RESET << endl;

    for (int i = 0; i < secondsRunningSwitches; i++) {
        cout << endl;
        cout << BLUE
             << "LOG: Clock Cycle #" << i + 1
             << ". Remaining Requests in Queue: " << queue->size()
             << RESET << endl;
        cout << BLUE << "--------------------------------------------------------------" << RESET << endl;

        cout << BLUE << "STREAMING SWITCH (S) Tick:" << RESET << endl;
        streamingSwitch.tick();
        cout << BLUE << "--------------------------------------------------------------" << RESET << endl;

        cout << BLUE << "PROCESSING SWITCH (P) Tick:" << RESET << endl;
        processingSwitch.tick();
        cout << BLUE << "==============================================================" << RESET << endl;
    }

    cout << "Remaining requests in queue: " << queue->size() << endl;

    delete queue;
    return 0;
}