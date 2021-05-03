#include "commands.hpp"

void rm(std::vector<std::string> commands)
{
    if (commands.size() == 2)
        if (std::remove(commands[1].c_str()) < 0)
            console_log_error("No such file!");
    else if (commands.size() > 2 && (commands[1] == '-d' || commands[1] == '--directory'))
        if (rmdir(commands[2].c_str()) < 0)
            console_log_error("No such directory!");
    else {
        console_log("Usage: rm [options] <path>\n");
        console_log("  -d, --directory  Remove specified directory instead of file.\n");
    }
}

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
