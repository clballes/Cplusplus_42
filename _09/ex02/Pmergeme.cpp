#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
    std::cout << "Constructor called" << std::endl;
}


//Function for std::vector merge-sort algorithim
// Merges two subvectors of vector
void PmergeMe::merge(int left, int mid, int right)
{
    int subVectorOne = mid - left + 1;
    int subVectorTwo = right - mid;

    std::vector<int> leftVector(subVectorOne);
    std::vector<int> rightVector(subVectorTwo);

    for (int i = 0; i < subVectorOne; i++)
        leftVector[i] = this->vector[left + i];
    for (int j = 0; j < subVectorTwo; j++)
        rightVector[j] = this->vector[mid + 1 + j];

    int indexOfSubVectorOne = 0, indexOfSubVectorTwo = 0;
    int indexOfMergedVector = left;

    while (indexOfSubVectorOne < subVectorOne && indexOfSubVectorTwo < subVectorTwo)
    {
        if (leftVector[indexOfSubVectorOne] <= rightVector[indexOfSubVectorTwo])
        {
            this->vector[indexOfMergedVector] = leftVector[indexOfSubVectorOne];
            indexOfSubVectorOne++;
        }
        else
        {
            this->vector[indexOfMergedVector] = rightVector[indexOfSubVectorTwo];
            indexOfSubVectorTwo++;
        }
        indexOfMergedVector++;
    }

    while (indexOfSubVectorOne < subVectorOne)
    {
        this->vector[indexOfMergedVector] = leftVector[indexOfSubVectorOne];
        indexOfSubVectorOne++;
        indexOfMergedVector++;
    }

    while (indexOfSubVectorTwo < subVectorTwo)
    {
        this->vector[indexOfMergedVector] = rightVector[indexOfSubVectorTwo];
        indexOfSubVectorTwo++;
        indexOfMergedVector++;
    }
}

void PmergeMe::mergeSort(int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(begin, mid);
    mergeSort(mid + 1, end);
    merge(begin, mid, end);
}

void 	PmergeMe::constructVector(int argc, char **argv)
{
	this->_startTimeV = clock();
	for (int i = 1; i < argc; i++)
    {
        int intValue = std::atoi(argv[i]);
        this->vector.push_back(intValue);
    }
	std::cout << "Before: ";
	printVector();
	int vec_size = vector.size();
    mergeSort(0, vec_size - 1);
	std::cout << "After: ";
	printVector();
	this->_endTimeV = clock();
	double elapsedTime = (static_cast<double>(_endTimeV - _startTimeV)/ CLOCKS_PER_SEC) * 1000000;
    std::cout << "TTime to process a range of: " << vec_size << " with std::vector : " << elapsedTime << " us." << std::endl;

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
		std::vector<int>::const_iterator it = this->vector.begin();
        for (; it != this->vector.end(); ++it) {
            std::cout << *it << " ";
        }
		std::cout << std::endl;
}