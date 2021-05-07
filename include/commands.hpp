/*
* MIT License
*
* Copyright (c) 2020-2021 EntySec
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

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
void cmd_help();

/* Apple built-ins */

#ifdef __APPLE__ /* Apple built-ins */

void cmd_osascript(std::vector<std::string>);
void cmd_setvol(std::vector<std::string>);
void cmd_say(std::vector<std::string>);

void cmd_getvol();
void cmd_prompt();

#endif /* Apple built-ins */

#ifndef __APPLE__

static std::map<std::string, std::function<void(std::vector<std::string>)>> passCmds = {
    {"rm", cmd_rm}, {"rmdir", cmd_rmdir}, {"mkdir", cmd_mkdir}, {"exec", cmd_exec},
    {"cd", cmd_cd}, {"touch", cmd_touch}, {"chmod", cmd_chmod}, {"chroot", cmd_chroot},
    {"ls", cmd_ls}, {"kill", cmd_kill}, {"cat", cmd_cat}
};

static std::map<std::string, std::function<void()>> nopassCmds = {
    {"shell", cmd_shell}, {"pwd", cmd_pwd}, {"whoami", cmd_whoami}, {"hostname", cmd_hostname},
    {"getuid", cmd_getuid}, {"getpid", cmd_getpid}, {"getgid", cmd_getgid}, {"ps", cmd_ps},
    {"reboot", cmd_reboot}, {"help", cmd_help}
};

#else

static std::map<std::string, std::function<void(std::vector<std::string>)>> passCmds = {
    {"rm", cmd_rm}, {"rmdir", cmd_rmdir}, {"mkdir", cmd_mkdir}, {"exec", cmd_exec},
    {"cd", cmd_cd}, {"touch", cmd_touch}, {"chmod", cmd_chmod}, {"chroot", cmd_chroot},
    {"ls", cmd_ls}, {"kill", cmd_kill}, {"cat", cmd_cat}, {"osascript", cmd_osascript},
    {"setvol", cmd_setvol}, {"say", cmd_say}
};

static std::map<std::string, std::function<void()>> nopassCmds = {
    {"shell", cmd_shell}, {"pwd", cmd_pwd}, {"whoami", cmd_whoami}, {"hostname", cmd_hostname},
    {"getuid", cmd_getuid}, {"getpid", cmd_getpid}, {"getgid", cmd_getgid}, {"ps", cmd_ps},
    {"reboot", cmd_reboot}, {"help", cmd_help}, {"getvol", cmd_getvol}, {"prompt", cmd_prompt}
};

#endif

#endif // _COMMANDS_HPP_
