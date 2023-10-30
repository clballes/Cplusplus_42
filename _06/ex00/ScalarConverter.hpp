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
        std::string _literal;
        e_type      _type;
        bool      _point;
        
    public:
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const & src);
        ScalarConverter & operator=(ScalarConverter const & rhs);
        ~ScalarConverter();

        //member funcitons
        void setLiteral(std::string literal);
        void check_type(std::string literal);
        void convertToInt(std::string literal);
        void convertToFloat(std::string literal);
        void convertToDouble(std::string literal);
        void convertToPseudo(std::string literal);

        class OutofBounds : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
