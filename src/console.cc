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

#include "console.hpp"

void console_log(std::string message, bool newline)
{
    if (newline)
        std::cout << message << std::endl;
    else
        std::cout << message;
}

void console_log_error(std::string message, bool newline)
{
    console_log("[-] " + message, newline);
}

void console_log_process(std::string message, bool newline)
{
    console_log("[*] " + message, newline);
}

void console_log_success(std::string message, bool newline)
{
    console_log("[+] " + message, newline);
}

void console_log_warning(std::string message, bool newline)
{
    console_log("[!] " + message, newline);
}

void console_log_information(std::string message, bool newline)
{
    console_log("[i] " + message, newline);
}
