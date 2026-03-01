#include <iostream>
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
}