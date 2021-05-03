#ifndef _COMMANDS_HPP_
#define _COMMANDS_HPP_

#include <cstdio>
#include <fstream>

#include "membrane.hpp"

void _rm(std::vector<std::string>);
void _rmdir(std::vector<std::string>);
void _mkdir(std::vector<std::string>);
void _exec(std::vector<std::string>);
void _cd(std::vector<std::string>);
void _touch(std::vector<std::string>);

void _shell();
void _pwd();
void _whoami();
void _hostname();
void _getuid();
void _getpid();
void _getgid();

static std::map<std::string, std::function<void(std::vector<std::string>)>> passCmds = {
    {"rm", _rm}, {"rmdir", _rmdir}, {"mkdir", _mkdir}, {"exec", _exec}, {"cd": _cd}, {"touch": _touch}
};

static std::map<std::string, std::function<void()>> nopassCmds = {
    {"shell", _shell}, {"pwd", _pwd}, {"whoami", _whoami}, {"hostname", _hostname},
    {"getuid", _getuid}, {"getpid", _getpid}, {"getgid", _getgid}
};

#endif // _COMMANDS_HPP_
