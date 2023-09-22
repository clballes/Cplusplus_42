#include "Harl.hpp"

void Harl::info()
{
    std::cout << "this is info message" << std::endl;
}

void Harl::warning()
{
    std::cout << "this is warning message" << std::endl;
}

void Harl::error()
{
    std::cout << "this is error message" << std::endl;
}

void Harl::debug()
{
    std::cout << "this is debug message" << std::endl;
}

void Harl::complain( std::string level )
{
    std::map<std::string, MemberFunction>::iterator it = levelToFunction.find(level);
    if (it != levelToFunction.end())
    {
        MemberFunction func = it->second;
        (this->*func)();
    } 
    else {
        std::cout << "Unknown complaint level: " << level << std::endl;
    }
}
Harl::Harl() {
        levelToFunction["debug"] = &Harl::debug;
        levelToFunction["info"] = &Harl::info;
        levelToFunction["warning"] = &Harl::warning;
        levelToFunction["error"] = &Harl::error;
    }

// Harl::Harl() destructor
