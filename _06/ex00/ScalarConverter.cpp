#include "ScalarConverter.hpp"
#include <string.h>
#include <limits>
#include <cstdlib> // for atoi and atof
#include <cmath>

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
void ScalarConverter::convertToInt(std::string literal)
{
    int intValue = std::stoi(literal);
    std::cout << "char: Non displayable " << std::endl;
    std::cout << "int: " << intValue << std::endl;
    float floatValue = static_cast<float>(intValue);
    std::cout << "float: " << floatValue << "f" << std::endl;
    double doubleValue = static_cast<double>(intValue);
    std::cout << "double: " << doubleValue << ".0" << std::endl;
}

void ScalarConverter::convertToFloat(std::string literal)
{
    float floatValue = std::stof(literal);
    double doubleValue = static_cast<double>(floatValue);
    if (std::isnan(floatValue))
    {
        std::cout << "char: impossible " << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << floatValue << "f" << std::endl;
        std::cout << "double: " << doubleValue << std::endl;
    }
    else if (std::isinf(floatValue))
    {
        std::cout << "char: impossible " << std::endl;
        if (floatValue > 0) {
            int positiveInfinity = std::numeric_limits<int>::max();
            std::cout << "int: " << positiveInfinity << std::endl;
            std::cout << "float: +" << floatValue << "f" << std::endl;
            std::cout << "double: +" << doubleValue << std::endl;
        } else {
            int negativeInfinity = std::numeric_limits<int>::min();
            std::cout << "int: " << negativeInfinity << std::endl;
             std::cout << "float: " << floatValue << "f" << std::endl;
            std::cout << "double: " << doubleValue << std::endl;
        }
    }
    else{
        std::cout << "char: Non displayable " << std::endl;
        int intValue = static_cast<int>(floatValue);
        std::cout << "int: " << intValue << std::endl;
        std::cout << "float: " << floatValue << "f" << std::endl;
        double doubleValue = static_cast<double>(floatValue);
        if (this->_point)
            std::cout << "double: " << doubleValue << std::endl;
        else
        {
            std::cout << "double: " << doubleValue << ".0" << std::endl;

        }
    }
}

void ScalarConverter::convertToDouble(std::string literal)
{
    double doubleValue = std::stod(literal);
    float floatValue = static_cast<float>(doubleValue);
    if (std::isnan(doubleValue))
    {
        std::cout << "char: impossible " << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << floatValue << "f" << std::endl;
        std::cout << "double: " << doubleValue << std::endl;
    }
    else if (std::isinf(doubleValue))
    {
        std::cout << "char: impossible " << std::endl;
        if (doubleValue > 0) {
            int positiveInfinity = std::numeric_limits<int>::max();
            std::cout << "int: " << positiveInfinity << std::endl;
            std::cout << "float: +" << floatValue << "f" << std::endl;
            std::cout << "double: +" << std::numeric_limits<double>::infinity() << std::endl;
        } else {
            int negativeInfinity = std::numeric_limits<int>::min();
            std::cout << "int: " << negativeInfinity << std::endl;
            std::cout << "float: " << floatValue << "f" << std::endl;
            std::cout << "double: " << doubleValue << std::endl;
        }
    }
    else
    {
        std::cout << "char: Non displayable " << std::endl;
        int intValue = static_cast<int>(doubleValue);
        std::cout << "int: " << intValue << std::endl;
        float floatValue = static_cast<float>(doubleValue);
        std::cout << "float: " << floatValue << "f" << std::endl;
        std::cout << "double: " << doubleValue << std::endl;
    }
}

void ScalarConverter::check_type(std::string literal)
{
    switch (this->_type)
    {
        case INT:
            convertToInt(literal);
            break;
        case FLOAT:
            std::cout << "idk q fa el default" << std::endl;
            convertToFloat(literal);
            break;
        case DOUBLE:
            convertToDouble(literal);
            break;  
        default:
            throw OutofBounds();
            std::cout << "idk q fa el default" << std::endl;
            break;
    }
}

void ScalarConverter::setLiteral(std::string literal)
{
    this->_literal = literal;
    for(size_t i = 0; i < literal.length(); i++)
    {
        if(this->_literal == "-inff" || this->_literal == "nanf" || this->_literal == "+inff")
        {
            this->_type = FLOAT;
            break ;
        }
        if(this->_literal == "-inf" || this->_literal == "nan" || this->_literal == "+inf")
        {
            this->_type = DOUBLE;
            break ;
        }
        if (literal[i] < 32 || literal[i] > 126)
            throw OutofBounds();
        if (isalpha(literal[i]))
        {
            if (literal[i] == 'f')
            {
                this->_type = FLOAT;
                break;
            }
            else
            {
                this->_type = CHAR;
            }
        }
        else if (isdigit(literal[i]))
        {
            this->_type = INT;
            if(this->_point)
                this->_type = DOUBLE;
        }
        else if (literal[i] == '.')
        {
            this->_type = DOUBLE;
            this->_point = true;
        }
    }
    check_type(literal);
    return ;
}


const char *ScalarConverter::OutofBounds::what() const throw()
{
    return "Error: cannot convert non displayable characters";
}
