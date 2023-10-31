#ifndef __SCALARCONVERTER___H__
# define __SCALARCONVERTER___H__

#include <iostream>
enum e_type {
    NONE,
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
};


class ScalarConverter
{
    private:
        std::string	_literal;
        e_type		_type;
        
    public:
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const & src);
        ScalarConverter & operator=(ScalarConverter const & rhs);
        ~ScalarConverter();

        //member funcitons
        void setLiteral(std::string literal);
        void check_type();
        void convertToInt();
        void convertToFloat(std::string literal);
        void convertToDouble(std::string literal);

		//parsing
		bool isFloat();
		bool isInt();
		bool isDouble();
		bool isChar();
		// bool isImpo();

        class OutofBounds : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
