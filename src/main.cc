#include "crypto.hpp"

void repeater()
{
    console_log_information("membrane ¯\\(o_0)/¯ v0.0.1");
    while (1) {
        console_log("membrane% ", 0);

        std::vector<std::string> commands = membrane_listen();
        if (commands.empty())
            continue;
        else {
            if (commands[0] == "exit" || commands[0] == "quit")
                break;

            if (membrane_execute(commands) < 0)
                console_log_error("Unrecognized command!");
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc > 1) {
        if (argc >= 3) {
            std::string host = uncrypto(argv[1]);
            std::string port = uncrypto(argv[2]);
        } else {
            std::string host = "127.0.0.1";
            std::string port = uncrypto(argv[1]);
        }

        console_log(host);
        console_log(port);

        int sock = membrane_connect(host, std::stoi(port));
        if (sock >= 0)
            repeater();
        else
            console_log_error("Failed to connect!");
        close(sock);
    } else
        repeater();
    return 0;
}
