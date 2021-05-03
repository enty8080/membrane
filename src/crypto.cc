#include "crypto.hpp"

/* VKS cipher here */

std::string crypto(char *string)
{
    std::string message(string);
    std::map<char, std::string> numsMap =
    {
        {'0', "v"}, {'1', "k"}, {'2', "s"}, {'3', "h"},
        {'4', "g"}, {'5', "f"}, {'6', "c"}, {'7', "z"}, {'8', "o"},
        {'9', "x"}, {':', "d"}
    };
  
    for(char& c : message) {
        if (numsMap.count(c) > 0) {
            std::replace(message.begin(), message.end(), c, numsMap[c]);
        }
    }
    
    return message;
}

std::string uncrypto(char *string)
{
    std::string message(string);
    std::map<char, std::string> numsMap =
    {
        {'v', "0"}, {'k', "1"}, {'s', "2"}, {'h', "3"},
        {'g', "4"}, {'f', "5"}, {'c', "6"}, {'z', "7"}, {'o', "8"},
        {'x', "9"}, {'d', ":"}
    };
  
    for(char& c : message) {
        if (numsMap.count(c) > 0) {
            std::replace(message.begin(), message.end(), c, numsMap[c]);
        }
    }
    
    return message;
}
