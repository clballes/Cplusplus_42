#include "PmergeMe.hpp"

// ----------------------------- CANONICAL FORM --------------------------

PmergeMe::PmergeMe(void)
{
    //std::cout << "Constructor called" << std::endl;
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
    //std::cout << "Destructor called" << std::endl;
}

void PmergeMe::parse_argv(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
    {
		for (int j = 0; argv[i][j] != '\0'; j++)
        {
			if (!isdigit(argv[i][j]) || (j == 0 && argv[i][j] == '0'))
		   	{
                throw ErrorParse();
            }
        }
    }
}


// ----------------------------- MEMBER FUNCTIONS FOR VECTOR --------------------------

void PmergeMe::insertionSortVector(int p, int q)
{
	for (int i = p; i < q; i++) {
		int tempVal = this->vector[i + 1];
		int j = i + 1;
		while (j > p && this->vector[j - 1] > tempVal) {
			this->vector[j] = this->vector[j - 1];
			j--;
		}
		this->vector[j] = tempVal;
	}
}

void PmergeMe::mergeVector(int p, int q, int r)
 {
 int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<int> LA(this->vector.begin() + p, this->vector.begin() + q + 1);
    std::vector<int> RA(this->vector.begin() + q + 1, this->vector.begin() + r + 1);

    int RIDX = 0;
    int LIDX = 0;

    for (int i = p; i <= r; i++) {
        if (RIDX == n2) {
            this->vector[i] = LA[LIDX++];
        } else if (LIDX == n1) {
            this->vector[i] = RA[RIDX++];
        } else if (RA[RIDX] > LA[LIDX]) {
            this->vector[i] = LA[LIDX++];
        } else {
            this->vector[i] = RA[RIDX++];
        }
    }
}

void PmergeMe::sortVector(int begin, int end)
{
    if (end - begin > 5)
	{
        int q = (begin + end) / 2;
        sortVector(begin, q);
        sortVector(q + 1, end);
        mergeVector(begin, q, end);
    }
	else
	{
        insertionSortVector(begin, end);
    }
}

void PmergeMe::printVector() 
{
		std::vector<int>::const_iterator it = this->vector.begin();
        for (; it != this->vector.end(); ++it) {
            std::cout << *it << " ";
        }
		std::cout << std::endl;
}

void 	PmergeMe::constructVector(int argc, char **argv)
{
	clock_t startTimeV = clock();
	for (int i = 1; i < argc; i++)
    {
        int intValue = std::atoi(argv[i]);
        this->vector.push_back(intValue);
    }
	std::cout << "Before: ";
	printVector();
	int vec_size = vector.size();
    sortVector(0, vec_size - 1);
	std::cout << "After: ";
	printVector();
	clock_t endTimeV = clock();
	double elapsedTime = (static_cast<double>(endTimeV - startTimeV)/ CLOCKS_PER_SEC) * 1000000;
    std::cout << "Time to process a range of: " << vec_size << " with std::vector : " << elapsedTime << " us." << std::endl;
}

// ----------------------------- MEMBER FUNCTIONS FOR LIST --------------------------

void PmergeMe::mergeList(std::list<int>::iterator p, std::list<int>::iterator q, std::list<int>::iterator r)
{
    std::list<int> merged;
    std::list<int>::iterator LIDX = p;
    std::list<int>::iterator RIDX = q;

    while (LIDX != q && RIDX != r) {
        if (*LIDX < *RIDX) {
            merged.push_back(*LIDX);
            ++LIDX;
        } else {
            merged.push_back(*RIDX);
            ++RIDX;
        }
    }

    while (LIDX != q) {
        merged.push_back(*LIDX);
        ++LIDX;
    }

    while (RIDX != r) {
        merged.push_back(*RIDX);
        ++RIDX;
    }

    std::copy(merged.begin(), merged.end(), p);
}

void PmergeMe::sortList(std::list<int>::iterator begin, std::list<int>::iterator end)
{
    if (std::distance(begin, end) > 1) {
        std::list<int>::iterator q = std::next(begin, std::distance(begin, end) / 2);
        sortList(begin, q);
        sortList(q, end);
        mergeList(begin, q, end);
    }
}

void PmergeMe::printList()
{
    for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::constructList(int argc, char **argv)
{
    clock_t startTimeL = clock();
    for (int i = 1; i < argc; ++i) {
        int intValue = std::atoi(argv[i]);
        myList.push_back(intValue);
    }
    std::cout << "Before: ";
    printList();
    int list_size = myList.size();
    sortList(myList.begin(), myList.end());
    std::cout << "After: ";
    printList();
    clock_t endTimeL = clock();
    double elapsedTime = (static_cast<double>(endTimeL - startTimeL) / CLOCKS_PER_SEC) * 1000000;
    std::cout << "Time to process a range of: " << list_size << " with std::list : " << elapsedTime << " us." << std::endl;
}

void PmergeMe::insertionSortList(std::list<int>::iterator p, std::list<int>::iterator q)
{
    for (std::list<int>::iterator i = p; i != q; ++i) {
        int tempVal = *std::next(i);
        std::list<int>::iterator j = i;
        while (j != p && *std::prev(j) > tempVal) {
            *std::next(j) = *std::prev(j);
            --j;
        }
        *std::next(j) = tempVal;
    }
}

// ----------------------------- EXCEPTIONS --------------------------

const char * PmergeMe::ErrorParse::what() const throw()
{
    return "Error: Just positive digits.";
}