#include "ScalarConverter.hpp"
#include <string.h>


ScalarConverter::ScalarConverter(void)
{
    std::cout << "Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
    std::cout << "Destructor called" << std::endl;
    (void)src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
    std::cout << "Destructor called" << std::endl;
    (void)rhs;
    return *this;
}

ScalarConverter::~ScalarConverter()
{  
    std::cout << "Destructor called" << std::endl;
}

//member funcitons
void ScalarConverter::setLiteral(std::string literal)
{
    this->_literal = literal;
    for(size_t i = 0; i < literal.length(); i++)
    {
       if (literal[0] == '-' || literal[0] == '+')
       {
            i++;
        }
        if (isalpha(literal[i]))
        {
            std::cout << "hoal " << literal[i] << std::endl;
            std::cout << "is not a letter, is a number" << std::endl;
        }
    }
    this->_type = INT;
    return ;
}