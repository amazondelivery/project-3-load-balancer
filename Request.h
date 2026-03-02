#ifndef REQUEST_H
#define REQUEST_H

#include <string>

struct Request {
    std::string ipIn;
    std::string ipOut;
    int time;
    char jobType;

    Request();

private:
    std::string generateRandomIP();
    int generateRandomTime();
    char generateRandomJobType();
};

#endif