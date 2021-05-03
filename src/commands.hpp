#ifndef _COMMANDS_HPP_
#define _COMMANDS_HPP_

#include "membrane.hpp"

void exec(std::vector<std::string>);
void cd(std::vector<std::string>);

void shell();
void pwd();
void whoami();
void hostname();
void getuid();
void getpid();
void getgid();
void uptime();
void procs();

static std::map<std::string, std::function<void(std::vector<std::string>)>> passCmds = {
    {"exec", exec}, {"cd": cd}
};

static std::map<std::string, std::function<void()>> nopassCmds = {
    {"shell", shell}, {"pwd", pwd}, {"whoami", whoami}, {"hostname", hostname},
    {"getuid", getuid}, {"getpid", getpid}, {"getgid", getgid}, {"uptime", uptime},
    {"procs", procs}, {""}
};

#endif // _COMMANDS_HPP_
