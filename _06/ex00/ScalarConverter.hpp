#ifndef __SCALARCONVERTER___H__
# define __SCALARCONVERTER___H__

#include <iostream>
enum e_type {
    NONE,
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
    LITERALS
};


class ScalarConverter
{
    private:
        std::string _literal;
        e_type      _type;
        
    public:
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const & src);
        ScalarConverter & operator=(ScalarConverter const & rhs);
        ~ScalarConverter();

        //member funcitons
        // static void convert(std::string literal, std::string param);
        void setLiteral(std::string literal);
        // static void convert(std::string literal, int param);
        // static void convert(std::string literal, float param);
        // static void convert(std::string literal, double param);

};

#endif
