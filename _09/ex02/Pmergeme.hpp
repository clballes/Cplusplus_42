#ifndef ____PMERGEME__H___
#define ____PMERGEME__H___

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>


class PmergeMe
{
	private:
		std::list<int> myList;
		std::vector<int>vector;

    public:
        PmergeMe(void);
        PmergeMe(PmergeMe const & src);
        PmergeMe & operator=(PmergeMe const & rhs);
        ~PmergeMe();


		void parse_argv(int argc, char **argv);
		//member functions for std::vector
		void constructVector(int argc, char **argv);
		void sortVector(int begin, int end);
		void insertionSortVector(int p, int q);
		void mergeVector(int left, int mid, int right);
		void printVector();

		//memebr functions for std::list
		void constructList(int argc, char **argv);
		void sortList(std::list<int>::iterator begin, std::list<int>::iterator end);
  		void insertionSortList(std::list<int>::iterator p, std::list<int>::iterator q);
		void mergeList(std::list<int>::iterator p, std::list<int>::iterator q, std::list<int>::iterator r);
		void printList();

		//exceptions

		class ErrorParse : public std::exception
		{
				public:
						virtual const char *what() const throw();
		};

};
#endif