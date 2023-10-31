#ifndef __SCALARCONVERTER___H__
# define __SCALARCONVERTER___H__

#include <iostream>
#include <string.h>
#include <limits>
#include <cstdlib>
#include <cmath>

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
		std::string	_charValue;
		int 		_intValue;
		float		_floatValue;
		double		_doubleValue;
		bool 		_needp;
        
    public:
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const & src);
        ScalarConverter & operator=(ScalarConverter const & rhs);
        ~ScalarConverter();

        //member funcitons
        void setLiteral(std::string literal);
        void check_type();
		void print();
		void printPesudo();
        void convertToInt();
		void convertToChar();
        void convertToFloat();
        void convertToDouble();

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
