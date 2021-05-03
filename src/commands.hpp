#ifndef _COMMANDS_HPP_
#define _COMMANDS_HPP_

#include "membrane.hpp"

void exec(std::vector<std::string>);
void shell();

std::map<std::string, std::function<void(std::vector<std::string>)>> passCmds = {
    {"exec", exec}
};

std::map<std::string, std::function<void()>> nopassCmds = {
    {"shell", shell}
};

#endif // _COMMANDS_HPP_
