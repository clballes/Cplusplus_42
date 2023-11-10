#ifndef __SPAN__H__
#define __SPAN__H__

# include <algorithm>
# include <vector>
#include <list>
#include <iostream>
#include <exception>
#include <numeric>

class Span{
    public:
        Span( void );
        Span(unsigned int N);
        Span(Span const & src);
        Span & operator=(Span const & rhs);
        ~Span();

        //member function
        void addNumber(int num);
        long int shortestSpan();
        long int longestSpan();
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end );
        class NoMoreNums : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class OutBounds : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
    private:
        unsigned int _N;
        std::vector<long int>_arr;
};

#endif