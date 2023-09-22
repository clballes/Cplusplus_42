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

void    Harl::switchCase()
{
    std::string str = argv[1];
    std::cout << str << std::endl;
    switch()
    {
        case 1:
            std::cout << "str" << std::endl;
            break ;
        case 2:
            std::cout << "str 2" << std::endl;
            break ;
    }
}
// Harl::Harl() destructor
void    Harl::cutString(std::string& str)
{
   std::string messages[] = {
    "[ DEBUG ] Harl is debugging something.",
    "[ INFO ] I just wanted to let you know that everything is going smoothly.",
    "[ WARNING ] I think I deserve to have some extra bacon for free.\n"
    "I've been coming for years whereas you started working here since last month.",
    "[ ERROR ] This is unacceptable, I want to speak to the manager now."
    };

    for (const std::string& message : messages) {
        std::string smslevel = message.substr(message.find("[") + 2, message.find("]") - 2);
        std::cout << smslevel << std::endl;

    }



}
