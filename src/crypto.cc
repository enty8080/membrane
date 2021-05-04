#include "crypto.hpp"

#ifndef KEY
#define KEY "alena"
#endif

std::string crypto(std::string string)
{
    size_t string_length = string.length();
    size_t key_length = std::string(KEY).length();

    for (char& c : string) {
        int some_magic = c ^ key_length * (string_length ^ key_length);
        std::replace(string.begin(), string.end(), c, (char)some_magic);
    }

    return string;
}
