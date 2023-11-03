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
        static std::string	_literal;
        static e_type		_type;
		static std::string	_charValue;
		static int			_intValue;
		static float		_floatValue;
		static double		_doubleValue;
		static bool 		_needp;

		// canonical form
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const & src);
        ScalarConverter & operator=(ScalarConverter const & rhs);

		//member functions
        static void check_type();
		static void print();
		static void printPesudo();
        static void convertToInt();
		static void convertToChar();
        static void convertToFloat();
        static void convertToDouble();

		//parsing
		static bool isFloat();
		static bool isInt();
		static bool isDouble();
		static bool isChar();
        
    public:
        ~ScalarConverter();

        //member funcitons
        static void setLiteral(std::string literal);

        class Unknown : public std::exception
		{
			public:
				const char *what() const throw();
		};
		
		class OutofBounds : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
