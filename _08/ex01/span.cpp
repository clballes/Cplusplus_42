#include "span.hpp"

Span::Span( void )
{
    std::cout << "Default constructor Span called" << std::endl;
}
Span::Span(unsigned int N) : _N(N)
{
    std::cout << "Default constructor Span called" << std::endl;
}

Span::Span(Span const & src)
{
    *this = src;
}

Span & Span::operator=(Span const & rhs)
{
    this->_N = rhs._N;
    this->_arr = rhs._arr;
    return *this;
}

Span::~Span()
{
    std::cout << "Default Destructor Span called" << std::endl;
}

void Span::addNumber(int num)
{
    if (!this->_arr.empty() && this->_arr.size() >= this->_N)
    {
        throw NoMoreNums();
        return;
    }
    this->_arr.push_back(num);
}

int Span::shortestSpan()
{
    if (this->_arr.size() <= 1)
        throw OutBounds();
    
    std::sort(this->_arr.begin(), this->_arr.end());

    int minSpan = this->_arr[1] - this->_arr[0];
    for (size_t i = 2; i < this->_arr.size(); ++i)
    {
        int span = this->_arr[i] - this->_arr[i - 1];
        if (span < minSpan)
        {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (this->_arr.size() <= 1)
        throw OutBounds();
    std::sort(this->_arr.begin(), this->_arr.end());
    int maxSpan = this->_arr[this->_arr.size() - 1] - this->_arr[0];

    return maxSpan;
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>::iterator it = begin;
    for (; it != end; ++it)
    {
        addNumber(*it);
    }
}


const char * Span::NoMoreNums::what() const throw()
{
    return "Exception max min: cannot add more numbers, array full";
}

const char * Span::OutBounds::what() const throw()
{
    return "Exception: There is just one number or zero in the array to perfom the operation";
}