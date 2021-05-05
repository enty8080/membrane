#include "crypto.hpp"

#ifndef KEY
#define KEY "alena"
#endif

std::string crypto(std::string string)
{
    size_t string_length = string.length();
    size_t key_length = std::string(KEY).length();

    for (char& c : string) {
        char magic = char(int(c) ^ key_length);
        std::replace(string.begin(), string.end(), c, magic);
    }

    return string;
}
