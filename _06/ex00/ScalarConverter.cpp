#include "ScalarConverter.hpp"

// CANONICAL FORM
ScalarConverter::ScalarConverter(void) : _needp(false)
{
    std::cout << "Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
    std::cout << "Copy operator called" << std::endl;
	*this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
    std::cout << "Operation overload called" << std::endl;
	this->_literal = rhs._literal;
    this->_type = rhs._type;
	this->_charValue = rhs._charValue;
	this->_intValue = rhs._intValue;
	this->_floatValue = rhs._floatValue;
	this->_doubleValue = rhs._doubleValue;
	this->_needp = rhs._needp;
    return *this;
}

ScalarConverter::~ScalarConverter()
{  
    std::cout << "Destructor called" << std::endl;
}

//MEMBER FUNCTIONS

void ScalarConverter::print()
{
	if (this->_charValue == "N")
		std::cout << "char: " << " Non displayable " << std::endl;
	else if (this->_charValue == "I")
		std::cout << "char: " << " Non displayable " << std::endl;
	else
	{
		std::cout << "char: " << "'" << this->_literal << "'" << std::endl;
	}
    std::cout << "int: " << this->_intValue << std::endl;
	if (this->_needp)
	{
		std::cout << "float: " << this->_floatValue << ".0f" << std::endl;
    	std::cout << "double: " << this->_doubleValue << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << this->_floatValue << "f" << std::endl;
    	std::cout << "double: " << this->_doubleValue << std::endl;
	}
}

void ScalarConverter::printPesudo()
{
	std::cout << "char: impossible " << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (_floatValue > 0 && _doubleValue > 0)
	{
		std::cout << "float: +" << this->_floatValue << "f" << std::endl;
		std::cout << "double: +" << this->_doubleValue << std::endl;	
	}
	else{
		std::cout << "float: " << this->_floatValue << "f" << std::endl;
		std::cout << "double: " << this->_doubleValue << std::endl;
	}
}

void ScalarConverter::check_type()
{
    switch (this->_type)
    {
        case INT:
            convertToInt();
            break;
        case FLOAT:
            convertToFloat();
            break;
        case DOUBLE:
            convertToDouble();
            break;
		case CHAR:
            convertToChar();
            break; 
		case NONE:
            throw OutofBounds();
            break; 
        default:
            break;
    }
}

// FUNCTION TO CONVERT
void ScalarConverter::convertToChar()
{
	this->_charValue = this->_literal;
    this->_intValue =  static_cast<int>(this->_charValue[0]);
    this->_floatValue =  static_cast<float>(this->_charValue[0]);
    this->_doubleValue =  static_cast<double>(this->_charValue[0]);
	print();
}

void ScalarConverter::convertToInt()
{
	this->_charValue = "N";
	this->_intValue = std::stoi(this->_literal);
	this->_floatValue = static_cast<float>(this->_intValue);
	this->_doubleValue = static_cast<double>(this->_intValue);
	print();
}

void ScalarConverter::convertToFloat()
{
    this->_floatValue = std::stof(this->_literal);
    this->_doubleValue = static_cast<double>( this->_floatValue);
    if (std::isnan(this->_floatValue) || std::isinf(this->_floatValue)){
		printPesudo();
    }
    else{
		this->_intValue = static_cast<int>(this->_floatValue);
		this->_charValue = "N";
		print();
    }
}

void ScalarConverter::convertToDouble()
{
    this->_doubleValue = std::stod(this->_literal);
    this->_floatValue = static_cast<float>(this->_doubleValue);
    if (std::isnan(this->_floatValue) || std::isinf(this->_floatValue)){
		printPesudo();
    }
    else{
		this->_intValue = static_cast<int>(this->_doubleValue);
		this->_charValue = "N";
		print();
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
		if (this->_literal[i] == '.' && this->_literal[i + 1] == '0')
		{
			this->_needp = true;
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
	this->_needp = true;
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
