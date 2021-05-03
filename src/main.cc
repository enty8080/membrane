#include "membrane.hpp"

void repeater()
{
    while (1) {
        std::cout << "membrane% ";

        std::vector<std::string> commands = membrane_listen();
        if (commands.empty())
            continue;
        else {
            if (commands[0] == "exit")
                break;
            if (membrane_execute(commands) < 0)
                std::cout << "Unrecognized command!" << std::endl;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc == 3) {
        int sock = membrane_connect(argv[1], argv[2]);
        if (sock >= 0)
            repeater();
        else
            std::cout << "Failed to connect!" << std::endl;
        close(sock);
    } else
        repeater();
    return 0;
}
