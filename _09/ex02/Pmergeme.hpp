#ifndef ____PMERGEME__H___
#define ____PMERGEME__H___

#include <iostream>
#include <vector>

class PmergeMe
{
	private:
		std::vector<char>vector;

    public:
        PmergeMe(int argc, char **argv);
        PmergeMe(PmergeMe const & src);
        PmergeMe & operator=(PmergeMe const & rhs);
        ~PmergeMe();

		// void printVector();

};
#endif