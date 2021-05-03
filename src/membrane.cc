#include "membrane.hpp"
#include "commands.hpp"

int membrane_connect(char *host, char *port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        return -1;
    }

    int portAddr = std::atoi(port);
    std::string hostAddr(host);

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(portAddr);
    inet_pton(AF_INET, hostAddr.c_str(), &hint.sin_addr);

    if (connect(sock, (sockaddr*)&hint, sizeof(hint)) == -1) {
        return -2;
    }

    dup2(sock, 0);
    dup2(sock, 1);
    dup2(sock, 3);

    return sock;
}

std::vector<std::string> membrane_listen()
{
    std::string command;
    std::getline(std::cin, command);

    std::vector<std::string> commands;
    if (!command.empty()) {
        std::replace(command.begin(), command.end(), '\'', '"');

        std::istringstream iss(command);
        std::string s;

        while (iss >> std::quoted(s)) {
            commands.push_back(s);
        }
    }

    return commands;
}

int membrane_execute(std::vector<std::string> commands)
{
    Commands commander;
    if (commander.commandsMap.count(commands[0]) <= 0)
        return -1;
    commands = commander.commandsMap[commands[0]](commands);
    return 0;
}
