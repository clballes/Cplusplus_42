#include "ScalarConverter.hpp"

//defintion for static members
std::string ScalarConverter::_literal;
e_type ScalarConverter::_type;
std::string ScalarConverter::_charValue;
int ScalarConverter::_intValue;
float ScalarConverter::_floatValue;
double ScalarConverter::_doubleValue;
bool ScalarConverter::_needp = false;

// CANONICAL FORM
// bool ScalarConverter::_needp = false;

ScalarConverter::ScalarConverter(void)
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
	if (_charValue == "N")
		std::cout << "char: " << " Non displayable " << std::endl;
	else if (_charValue == "I")
		std::cout << "char: " << " Non displayable " << std::endl;
	else
	{
		std::cout << "char: " << "'" << _literal << "'" << std::endl;
	}
    std::cout << "int: " << _intValue << std::endl;
	if (_needp)
	{
		std::cout << "float: " << _floatValue << ".0f" << std::endl;
    	std::cout << "double: " << _doubleValue << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << _floatValue << "f" << std::endl;
    	std::cout << "double: " << _doubleValue << std::endl;
	}
}

void ScalarConverter::printPesudo()
{
	std::cout << "char: impossible " << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (_floatValue > 0 && _doubleValue > 0)
	{
		std::cout << "float: +" << _floatValue << "f" << std::endl;
		std::cout << "double: +" << _doubleValue << std::endl;	
	}
	else{
		std::cout << "float: " << _floatValue << "f" << std::endl;
		std::cout << "double: " << _doubleValue << std::endl;
	}
}

void ScalarConverter::check_type()
{
    switch (_type)
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
            throw Unknown();
            break; 
        default:
            break;
    }
}

// FUNCTION TO CONVERT
void ScalarConverter::convertToChar()
{
	try
	{
		_charValue = _literal;
	}
	catch(const OutofBounds& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
    _intValue =  static_cast<int>(_charValue[0]);
    _floatValue =  static_cast<float>(_charValue[0]);
    _doubleValue =  static_cast<double>(_charValue[0]);
	_needp = true;
	print();
}

void ScalarConverter::convertToInt()
{
	_charValue = "N";
	try
	{
		_intValue = std::stoi(_literal);
	}
	catch(const OutofBounds& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	_floatValue = static_cast<float>(_intValue);
	_doubleValue = static_cast<double>(_intValue);
	print();
}

void ScalarConverter::convertToFloat()
{
	try
	{
    	_floatValue = std::stof(_literal);
	}
	catch(const OutofBounds& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
    _doubleValue = static_cast<double>( _floatValue);
    if (std::isnan(_floatValue) || std::isinf(_floatValue)){
		printPesudo();
    }
    else{
		_intValue = static_cast<int>(_floatValue);
		_charValue = "N";
		print();
    }
}

void ScalarConverter::convertToDouble()
{
	try
	{
    	_doubleValue = std::stod(_literal);
	}
	catch(const OutofBounds& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
    _floatValue = static_cast<float>(_doubleValue);
    if (std::isnan(_floatValue) || std::isinf(_floatValue)){
		printPesudo();
    }
    else{
		_intValue = static_cast<int>(_doubleValue);
		_charValue = "N";
		print();
    }
}

//PARSING FUNCTIONS

bool ScalarConverter::isFloat()
{
	if(_literal == "-inff" || _literal == "nanf" || _literal == "+inff")
	 	return true;
	for(size_t i = 0; i < _literal.length(); i++)
	{
		if (!isdigit(_literal[i]) && (_literal[i] != 'f' && _literal[i] != '.') && _literal[i] != '-')
		{
			return false;
		}
		if (_literal[i] == '.' && _literal[i + 1] == '0')
		{
			_needp = true;
		}
	}
	size_t found = _literal.find("f");
	size_t foundp = _literal.find(".");
	if (found != std::string::npos && (found + 1 == _literal.length())
		&& foundp != std::string::npos && foundp + 1 != found)
	{
		return true;
	}
	return false;	
}

bool ScalarConverter::isInt()
{
	for(size_t i = 0; i < _literal.length(); i++)
	{
		if (!isdigit(_literal[i]) && _literal[i] != '-')
		{
			return false;
		}
	}
	_needp = true;
	return true;
}

bool ScalarConverter::isDouble()
{
	if(_literal == "-inf" || _literal == "nan" || _literal == "+inf")
		return true;
	size_t foundf = _literal.find("f");
	size_t foundp = _literal.find(".");
	for(size_t i = 0; i < _literal.length(); i++)
	{
		if (!isdigit(_literal[i]) && ( _literal[i] != '.') && _literal[i] != '-')
		{
			return false;
		}
	}
	if (foundf == std::string::npos && foundp != std::string::npos && isdigit(_literal[foundp + 1]))
	{
		return true;
	}
	return false;
	
}

bool ScalarConverter::isChar()
{
	if (_literal.length() != 1)
	{
		return false;
	}
	if (_literal[0] < 32 || _literal[0] > 126)
		throw OutofBounds();
	if (!isalpha(_literal[0]))
	{
		return false;
	}
	return true;
}



void ScalarConverter::setLiteral(std::string literal)
{
    ScalarConverter::_literal = literal;
	if (isFloat())
		_type = FLOAT;
	else if (isInt())
		_type = INT;
	else if (isDouble())
		_type = DOUBLE;
	else if (isChar())
		_type = CHAR;
	else
		_type = NONE;
    check_type();
    return ;
}


const char *ScalarConverter::Unknown::what() const throw()
{
    return "Error: Unknown type, write it correctly.";
}


const char *ScalarConverter::OutofBounds::what() const throw()
{
    return "Error: Cannot convert, number incompatible";
}
