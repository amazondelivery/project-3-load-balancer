#include "Request.h"
#include <string>
#include <cstdlib>
using namespace std;

Request::Request() {
    ipIn = generateRandomIP();
    ipOut = generateRandomIP();
    time = generateRandomTime();
    jobType = generateRandomJobType();
}

string Request::generateRandomIP() {
    return to_string(rand() % 256) + "." +
           to_string(rand() % 256) + "." +
           to_string(rand() % 256) + "." +
           to_string(rand() % 256);
}

int Request::generateRandomTime() {
    return (rand() % 5) + 1;
}

char Request::generateRandomJobType() {
    int i = rand() % 2;
    if (i == 0) {
        return 'P';
    } else {
        return 'S';
    }
}