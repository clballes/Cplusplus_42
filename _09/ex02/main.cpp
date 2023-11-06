#include "PmergeMe.hpp"

int main(int argc, char**argv)
{
    if (argc == 1)
    {
        std::cerr << "Error: too much argv" << std::endl;
        return 1;
    }
    PmergeMe me;
	try
	{
		me.parse_argv(argc, argv);
		me.constructVector(argc, argv);
		me.constructList(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}