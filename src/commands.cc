#include "commands.hpp"

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
    char directory[1024];
    DIR *dir;

    if (commands.size() > 1)
        dir = opendir(commands[1].c_str());
    else
        getcwd(directory, sizeof(directory));
        dir = opendir(directory);

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
    system("/bin/sh -i");
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
    std::map<int, int> m;
    int counter;
    for (std::map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
        if (counter % 6 == 0)
            console_log("");
        console_log((it->first + " "), 0);
        counter++;
    }
}

void osascript(std::vector<std::string> commands)
{
    if (commands.size() > 1)
        system(("osascript -e '" + commands[1] + "'").c_str());
    else
        console_log("Usage: osascript <script>");
}

void setvol(std::vector<std::string> commands)
{
    if (commands.size() > 1)
        system(("osascript -e 'set volume output volume " + commands[1] + "'").c_str());
    else
        console_log("Usage: setvol <percentage>");
}

void say(std::vector<std::string> commands)
{
    if (commands.size() > 1)
        system(("say " + commands[1]).c_str());
    else
        console_log("Usage: say <message>");
}

void getvol()
{
    console_log_information("Current volume level: ", 0);
    system("osascript -e 'output volume of (get volume settings)'");
}
