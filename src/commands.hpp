#ifndef _COMMANDS_HPP_
#define _COMMANDS_HPP_

#include <cstdio>
#include <fstream>

#include "membrane.hpp"

void rm(std::vector<std::string>);
void exec(std::vector<std::string>);
void cd(std::vector<std::string>);
void touch(std::vector<std::string>);

void shell();
void pwd();
void whoami();
void hostname();
void uid();
void pid();
void gid();

static std::map<std::string, std::function<void(std::vector<std::string>)>> passCmds = {
    {"rm", rm}, {"exec", exec}, {"cd": cd}, {"touch": touch}
};

static std::map<std::string, std::function<void()>> nopassCmds = {
    {"shell", shell}, {"pwd", pwd}, {"whoami", whoami}, {"hostname", hostname},
    {"uid", uid}, {"pid", pid}, {"gid", gid}
};

#endif // _COMMANDS_HPP_
