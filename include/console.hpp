#ifndef _CONSOLE_HPP_
#define _CONSOLE_HPP_

#include <iostream>
#include <string>

void console_log(std::string, bool = 1);
void console_log_error(std::string, bool = 1);
void console_log_process(std::string, bool = 1);
void console_log_success(std::string, bool = 1);
void console_log_warning(std::string, bool = 1);
void console_log_information(std::string, bool = 1);

#endif // _CONSOLE_HPP_
