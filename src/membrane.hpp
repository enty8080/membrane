#ifndef _MEMBRANE_HPP_
#define _MEMBRANE_HPP_

#include <algorithm>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <vector>
#include <sstream>
#include <iomanip>
#include <functional>
#include <map>

#include "console.hpp"

int membrane_connect(char*, char*);
std::vector<std::string> membrane_listen();
int membrane_execute(std::vector<std::string>);

#endif // _MEMBRANE_HPP_
