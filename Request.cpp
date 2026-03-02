#include <string>
#include <Request.h>
using namespace std;

struct Request {
    string ipIn;
    string ipOut;
    int time;
    char jobType; // P  or S

    Request() {
        ipIn = generateRandomIP();
        ipOut = generateRandomIP();
        time = generateRandomTime();
        jobType = generateRandomJobType();
    }

private:
    string generateRandomIP() {
        return to_string(rand() % 256) + "." +
               to_string(rand() % 256) + "." +
               to_string(rand() % 256) + "." +
               to_string(rand() % 256);
    }

    int generateRandomTime() {
        return (rand() % 10) + 1;
    }

    char generateRandomJobType() {
        int i = rand() % 2;
        if (i == 0) {
            return 'P';
        } else {
            return 'S';
        }
    }
};