#ifndef _COMMANDS_HPP_
#define _COMMANDS_HPP_

#include <cstdio>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/reboot.h>
#include <dirent.h>
#include <signal.h>

#include "membrane.hpp"

/* Cross-platform built-ins */

void cmd_rm(std::vector<std::string>);
void cmd_rmdir(std::vector<std::string>);
void cmd_mkdir(std::vector<std::string>);
void cmd_exec(std::vector<std::string>);
void cmd_cd(std::vector<std::string>);
void cmd_touch(std::vector<std::string>);
void cmd_chmod(std::vector<std::string>);
void cmd_chroot(std::vector<std::string>);
void cmd_ls(std::vector<std::string>);
void cmd_kill(std::vector<std::string>);
void cmd_cat(std::vector<std::string>);

void cmd_shell();
void cmd_pwd();
void cmd_whoami();
void cmd_hostname();
void cmd_getuid();
void cmd_getpid();
void cmd_getgid();
void cmd_ps();
void cmd_reboot();
void cmd_shutdown();

/* Apple built-ins */

#ifdef __APPLE__ /* Apple built-ins */

void cmd_osascript(std::vector<std::string>);
void cmd_setvol(std::vector<std::string>);
void cmd_say(std::vector<std::string>);

void cmd_getvol();

#endif /* Apple built-ins */

static std::map<std::string, std::function<void(std::vector<std::string>)>> passCmds = {
    {"rm", cmd_rm}, {"rmdir", cmd_rmdir}, {"mkdir", cmd_mkdir}, {"exec", cmd_exec},
    {"cd", cmd_cd}, {"touch", cmd_touch}, {"chmod", cmd_chmod}, {"chroot", cmd_chroot},
    {"ls", cmd_ls}, {"kill", cmd_kill}, {"cat", cmd_cat}
};

static std::map<std::string, std::function<void()>> nopassCmds = {
    {"shell", cmd_shell}, {"pwd", cmd_pwd}, {"whoami", cmd_whoami}, {"hostname", cmd_hostname},
    {"getuid", cmd_getuid}, {"getpid", cmd_getpid}, {"getgid", cmd_getgid}, {"ps", cmd_ps},
    {"reboot", cmd_reboot}, {"shutdown", cmd_shutdown}
};

#ifdef __APPLE__ /* Apple built-ins */

passCmds["osascript"] = cmd_osascript;
passCmds["setvol"] = cmd_setvol;
passCmds["say"] cmd_say;

nopassCmds["getvol"] = cmd_getvol;

#endif /* Apple built-ins */

#endif // _COMMANDS_HPP_
