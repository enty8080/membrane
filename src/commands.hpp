#ifndef _COMMANDS_HPP_
#define _COMMANDS_HPP_

#include "membrane.hpp"

class Commands {
public:
    static std::vector<std::string> doit(std::vector<std::string> commands)
    {
        std::cout << "..all systems go.." << std::endl;
        return commands;
    }

    std::map<std::string, std::function<
        std::vector<std::string>(std::vector<std::string>)
    >> commandsMap = {
        {"doit", doit}
    };
};

#endif // _COMMANDS_HPP_