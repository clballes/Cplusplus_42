#include "Pmergeme.hpp"

int main(int argc, char**argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: too much argv" << std::endl;
        return 1;
    }
    Pmergeme me(argv[1]);
}