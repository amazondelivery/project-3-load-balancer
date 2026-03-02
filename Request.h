#ifndef REQUEST_H
#define REQUEST_H

#include <string>
using namespace std;

struct Request {
    string ipIn;
    string ipOut;
    int time;
    char jobType;

    Request();

private:
    string generateRandomIP();
    int generateRandomTime();
    char generateRandomJobType();
};

#endif