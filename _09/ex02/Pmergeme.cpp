#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
    std::cout << "Constructor called" << std::endl;
	for (int i = 1; i < argc; i++)
	{
		this->vector.push_back(argv[i][0]);
	}
}
PmergeMe::PmergeMe(PmergeMe const & src)
{  
    *this = src;
}
PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
    (void)rhs;
    return *this;
}
PmergeMe::~PmergeMe()
{
    std::cout << "Destructor called" << std::endl;
}

// void PmergeMe::printVector() 
// {
//         std::cout << "Vector contents: ";
// 		std::vector<char>::const_iterator it = this->vector.begin();
//         for (; it != this->vector.end(); ++it) {
//             std::cout << *it << " ";
//         }
//         std::cout << std::endl;
// }