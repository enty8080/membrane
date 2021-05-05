#include "utils.hpp"

std::string exec(std::string command) {
    char buffer[128];
    std::string result = "";

    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        return "[-] Failed to obtain command output!";
    }

    while (!feof(pipe)) {
      if (fgets(buffer, sizeof(buffer), pipe) != NULL)
         result += buffer;
    }

    pclose(pipe);
    return result;
}

void erase(std::string& mainStr, const std::string& toErase)
{
    size_t pos = std::string::npos;
    while ((pos  = mainStr.find(toErase)) != std::string::npos)
        mainStr.erase(pos, toErase.length());
}
