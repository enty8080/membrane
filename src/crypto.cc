#include "crypto.hpp"

std::string crypto(std::string string)
{
    std::string result = "";
    for (char& c : string)
        result += char(int(c) ^ string.length());
    return string;
}
