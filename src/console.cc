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
