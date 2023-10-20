#ifndef __SPAN__H__
#define __SPAN__H__

# include <algorithm>
# include <vector>
#include <iostream>
#include <exception>

class Span{
    public:
        Span( void );
        Span(unsigned int N);
        Span(Span const & src);
        Span & operator=(Span const & rhs);
        ~Span();

        //member function
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
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
        std::vector<int>_arr;
};

#endif