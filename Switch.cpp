#include "Switch.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

Switch::Switch(RequestQueue* initialQueue, int initialServers, char typeChar) {
    queue = initialQueue;
    time = 0;
    type = typeChar;

    for (int i = 0; i < initialServers; i++) {
        servers.push_back(new WebServer(i + 1, type));
        cout << "Switch (" << type << "): Added WebServer " << (i + 1) << endl;
    }
}

Switch::~Switch() {
    for (int i = 0; i < servers.size(); i++) {
        cout << "Switch (" << type << "): Deleting WebServer " << (i + 1) << endl;
        delete servers[i];
    }
    servers.clear();
}

void Switch::tick() {
    time++;

    for (int i = 0; i < servers.size(); i++) {
        servers[i]->tick();

        while (!servers[i]->isProcessing() && !queue->empty()) {
            Request nextRequest = queue->peek();
            if (consultFirewall(nextRequest.ipIn)) {
                cout << "ISRAELI CYBERINTELLIGENCE THREAT DETECTED! DISCARDING THIS PACKET" << endl;
                queue->pop();
                continue;
            }

            if (nextRequest.jobType == type) {
                queue->pop();
                servers[i]->process(nextRequest);
            } else {
                break;
            }
        }
    }

    if (time % 10 == 0) {
        if (queue->size() < (50 * servers.size()) && servers.size() > 1) {
            int removedID = servers.size();
            cout << "Switch (" << type << "): Removing WebServer " << removedID << endl;
            delete servers.back();
            servers.pop_back();
        } 
        else if (queue->size() > (80 * servers.size())) {
            int newID = servers.size() + 1;
            servers.push_back(new WebServer(newID, type));
            cout << "Switch (" << type << "): Added WebServer " << newID << endl;
        }
    }
}

bool Switch::consultFirewall(std::string ip) {
    stringstream ss(ip);
    string segment;
    int parts[4];
    int i = 0;

    while (getline(ss, segment, '.') && i < 4) {
        parts[i++] = stoi(segment);
    }

    if (i != 4) return false;

    int A = parts[0];
    int B = parts[1];
    int C = parts[2];
    int D = parts[3];

    if ((A == 192 && B == 168) || (A == 10) || (A == 172 && B >= 16 && B <= 31) ||
        (A < 20) || (A == 20 && B < 40) || (A == 20 && B == 40 && C < 60) ||
        (A == 20 && B == 40 && C == 60 && D <= 80)) {
        return true;
    }

    return false;
}