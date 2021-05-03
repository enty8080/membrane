#include "console.hpp"

void console_log(std::string message)
{
    std::cout << message << std::endl;
}

void console_log_error(std::string message)
{
    console_log("[-] " + message);
}

void console_log_process(std::string message)
{
    console_log("[*] " + message);
}

void console_log_success(std::string message)
{
    console_log("[+] " + message);
}

void console_log_warning(std::string message)
{
    console_log("[!] " + message);
}
