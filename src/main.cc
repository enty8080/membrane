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
                console_log_error("Unrecognized command!");
            else if (error_code == -2)
                console_log_error("Failed to execute command!");
        }
    }
}

int main(int argc, char *argv[])
{
    console_log("membrane _/(o_0)\_ v0.0.1");
    if (argc == 3) {
        int sock = membrane_connect(argv[1], argv[2]);
        if (sock >= 0)
            repeater();
        else
            console_log_error("Failed to connect!");
        close(sock);
    } else
        repeater();
    return 0;
}
