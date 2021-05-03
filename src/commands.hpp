#ifndef _COMMANDS_HPP_
#define _COMMANDS_HPP_

#include "membrane.hpp"

void exec(std::vector<std::string>);
void cd(std::vector<std::string>);

void shell();
void pwd();
void whoami();
void hostname();
void uid();
void pid();
void gid();

static std::map<std::string, std::function<void(std::vector<std::string>)>> passCmds = {
    {"exec", exec}, {"cd": cd}
};

static std::map<std::string, std::function<void()>> nopassCmds = {
    {"shell", shell}, {"pwd", pwd}, {"whoami", whoami}, {"hostname", hostname},
    {"uid", uid}, {"pid", pid}, {"gid", gid}
};

#endif // _COMMANDS_HPP_
