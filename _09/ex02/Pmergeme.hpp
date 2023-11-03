#ifndef ____PMERGEME__H___
#define ____PMERGEME__H___

#include <iostream>
#include <vector>

class PmergeMe
{
	private:
		std::vector<int>vector;

    public:
        PmergeMe(int argc, char **argv);
        PmergeMe(PmergeMe const & src);
        PmergeMe & operator=(PmergeMe const & rhs);
        ~PmergeMe();

		//member functions
		void printVector();
		void constructVector();
		// void mergeSort();
	void mergeSort(int const begin, int const end);

};
#endif