#include "RPN.hpp"

int main(int argc, char**argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: it must be one argument!" << std::endl;
        return 1;
    }
    try
    {
        RPN rpn(argv[1]);
    }
    catch(const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}