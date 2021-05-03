#include "commands.hpp"

void exec(std::vector<std::string> commands)
{
    if (commands.size() > 1)
        system(commands[1].c_str());
    else
        console_log("Usage: exec <commands>");
}

void cd(std::vector<std::string> commands)
{
    if (commands.size() > 1)
        chdir(commands[1].c_str());
    else
        console_log("Usage: cd <directory>");
}

void shell()
{
    system("/bin/sh -i");
}

void pwd()
{
    char directory[1024];
    getcwd(directory, sizeof(directory));
    console_log(std::string(directory));
}

void whoami()
{
    username = std::string(getlogin());
    console_log(username);
}

void hostname()
{
    char hostname[1024];
    gethostname(hostname, sizeof(hostname));
    console_log(std::string(hostname));
}

void uid()
{
    console_log(std::string(getuid()));
}

void pid()
{
    console_log(std::string(getpid()));
}

void gid()
{
    console_log(std::string(getgid()));
}
