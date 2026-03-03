#include "Request.h"
#include <string>
#include <cstdlib>
using namespace std;

/**
 * @brief Default constructor. Generates a Request with randomized fields.
 *
 * Randomly assigns:
 * - ipIn and ipOut as IPv4 address strings
 * - time as a processing duration in clock cycles
 * - jobType as either 'P' (processing) or 'S' (streaming)
 */
Request::Request() {
    ipIn = generateRandomIP();
    ipOut = generateRandomIP();
    time = generateRandomTime();
    jobType = generateRandomJobType();
}

/**
 * @brief Generates a random IPv4 address string.
 *
 * Each octet is a random integer in the range [0, 255].
 *
 * @return std::string A random IPv4 address (e.g. "172.24.53.101").
 */
string Request::generateRandomIP() {
    return to_string(rand() % 256) + "." +
           to_string(rand() % 256) + "." +
           to_string(rand() % 256) + "." +
           to_string(rand() % 256);
}

/**
 * @brief Generates a random processing time for the request.
 *
 * @return int A random duration in clock cycles in the range [1, 5].
 */
int Request::generateRandomTime() {
    return (rand() % 5) + 1;
}

/**
 * @brief Generates a random job type for the request.
 *
 * @return char 'P' for a processing job or 'S' for a streaming job.
 */
char Request::generateRandomJobType() {
    int i = rand() % 2;
    if (i == 0) {
        return 'P';
    } else {
        return 'S';
    }
}