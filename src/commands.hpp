#ifndef _COMMANDS_HPP_
#define _COMMANDS_HPP_

#include "membrane.hpp"

class Command
{
    virtual void doit(std::vector<std::string>) = 0;
};

class test : public Command
{
    void doit(std::vector<std::string> commands)
    {
        console_log("..all systems go..");
    }
};

std::map<std::string, Command> cmds = {
    {"test", test()}
};

#endif // _COMMANDS_HPP_
