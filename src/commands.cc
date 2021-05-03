#include "commands.hpp"

void exec(std::vector<std::string> commands)
{
    if (commands.size() == 2)
        system(commands[1].c_str());
    else
        console_log("Usage: exec <commands>");
}

void shell()
{
    system("/bin/sh -i");
}
