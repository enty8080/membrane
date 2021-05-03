#include "membrane.hpp"

void repeater()
{
    while (1) {
        std::cout << "membrane% ";

        std::vector<std::string> commands = membrane_listen();
        if (commands.empty())
            continue;
        else {
            if (commands[0] == "exit" || commands[0] == "quit")
                break;

            int error_code = membrane_execute(commands);
            if (error_code == -1)
                std::cout << "Unrecognized command!" << std::endl;
            else if (error_code == -2)
                std::cout << "Failed to execute command!" << std::endl;
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
