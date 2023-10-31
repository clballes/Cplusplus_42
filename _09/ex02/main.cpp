#include "PmergeMe.hpp"

int main(int argc, char**argv)
{
    if (argc == 1)
    {
        std::cerr << "Error: too much argv" << std::endl;
        return 1;
    }
    PmergeMe me(argc, argv);
	// me.printVector();
}