#ifndef ____PMERGEME__H___
#define ____PMERGEME__H___

#include <iostream>
#include <vector>
#include <ctime>


class PmergeMe
{
	private:
		std::vector<int>vector;
		clock_t _startTimeV;
		clock_t _endTimeV;

    public:
        PmergeMe(void);
        PmergeMe(PmergeMe const & src);
        PmergeMe & operator=(PmergeMe const & rhs);
        ~PmergeMe();

		//member functions for std::vector
		void printVector();
		void constructVector(int argc, char **argv);
		void mergeSort(int const begin, int const end);
		void merge(int left, int mid, int right);

		//memebr functions for std::list

};
#endif