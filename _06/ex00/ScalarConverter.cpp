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

//MEMBER FUNCTIONS
void ScalarConverter::convertToInt()
{
    int intValue = std::stoi(this->_literal);
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

void ScalarConverter::check_type()
{
    switch (this->_type)
    {
        case INT:
            convertToInt(this->_literal);
            break;
        case FLOAT:
            convertToFloat(this->_literal);
            break;
        case DOUBLE:
            convertToDouble(this->_literal);
            break; 
		case NONE:
            throw OutofBounds();
            break; 
        default:
            // std::cout << "idk q fa el default" << std::endl;
            break;
    }
}


//PARSING FUNCTIONS

bool ScalarConverter::isFloat()
{
	if(this->_literal == "-inff" || this->_literal == "nanf" || this->_literal == "+inff")
	 	return true;
	for(size_t i = 0; i < this->_literal.length(); i++)
	{
		if (!isdigit(this->_literal[i]) && (_literal[i] != 'f' && _literal[i] != '.'))
		{
			return false;
		}
	}
	size_t found = this->_literal.find("f");
	if (found != std::string::npos && (found + 1 == this->_literal.length()))
	{
		return true;
	}
	return false;	
}

bool ScalarConverter::isInt()
{
	for(size_t i = 0; i < this->_literal.length(); i++)
	{
		if (!isdigit(this->_literal[i]))
		{
			return false;
		}
	}
	return true;
}

bool ScalarConverter::isDouble()
{
	if(this->_literal == "-inf" || this->_literal == "nan" || this->_literal == "+inf")
		return true;
	size_t foundf = this->_literal.find("f");
	size_t foundp = this->_literal.find(".");
	for(size_t i = 0; i < this->_literal.length(); i++)
	{
		if (!isdigit(this->_literal[i]) && ( _literal[i] != '.'))
		{
			return false;
		}
	}
	if (foundf == std::string::npos && foundp != std::string::npos && isdigit(this->_literal[foundp + 1]))
	{
		std::cout << "double" << std::endl;
		return true;
	}
	return false;
	
}

bool ScalarConverter::isChar()
{
	if (this->_literal.length() != 1)
	{
		return false;
	}
	if (this->_literal[0] < 32 || this->_literal[0] > 126)
		throw OutofBounds();
	if (!isalpha(this->_literal[0]))
	{
		return false;
	}
	return true;
}



void ScalarConverter::setLiteral(std::string literal)
{
    this->_literal = literal;
	if (isFloat())
		this->_type = FLOAT;
	else if (isInt())
		this->_type = INT;
	else if (isDouble())
		this->_type = DOUBLE;
	else if (isChar())
		this->_type = CHAR;
	else
		this->_type = NONE;
    check_type();
    return ;
}


const char *ScalarConverter::OutofBounds::what() const throw()
{
    return "Error: Unknown type";
}
