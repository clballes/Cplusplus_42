#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        Harl harl;
        std::string str = argv[1];
        harl.cutString(str);

        // harl.complain("debug");
        // harl.complain("info");
        // harl.complain("warning");
        harl.complain("error");

    }
    return 0;
}