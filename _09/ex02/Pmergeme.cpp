#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
    std::cout << "Constructor called" << std::endl;
	for (int i = 1; i < argc; i++)
    {
        int intValue = std::atoi(argv[i]);
        this->vector.push_back(intValue);
    }
	// constructVector(argc)
}

void 	PmergeMe::mergeSort()
{

}

void PmergeMe::mergeSort(int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(begin, mid);
    mergeSort(mid + 1, end);
    // merge(this->vector, begin, mid, end);
}




void 	PmergeMe::constructVector()
{
	int vec_size = vector.size();
    mergeSort(0, vec_size - 1);

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

void PmergeMe::printVector() 
{
        std::cout << "Vector contents: " << std::endl;
		std::vector<int>::const_iterator it = this->vector.begin();
        for (; it != this->vector.end(); ++it) {
            std::cout << *it << " " << std::endl;
        }
}