#include "membrane.hpp"

class Commands {
public:
    void doit(std::vector<std::string>)
        std::cout << "..all systems go.." << std::endl;

    std::map<std::string,std::function<void(std::vector<std::string>)>> commandsMap = {
        {"doit", doit}
    };
};
