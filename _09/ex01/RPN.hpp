#ifndef ____RPN__H___
#define ____RPN__H___

#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
#include <exception>
#include <sstream>

class RPN
{
        private:
                std::stack<int> stack;
                int _result;
        public:
                RPN(std::string argv); //charge the csvmap
                RPN(RPN const & src);
                RPN & operator=(RPN const & rhs);
                ~RPN();

                bool calculate(char op);
                void operations(char operand, int num1, int num2);

                class ErrorDivision : public std::exception
                {
                        public:
                                virtual const char *what() const throw();
                };
                class ErrorNums : public std::exception
                {
                        public:
                                virtual const char *what() const throw();
                };
                class ErrorSyntax : public std::exception
                {
                        public:
                                virtual const char *what() const throw();
                };

};
std::ostream & operator<<(std::ostream & os, std::stack<int> my_stack);
// std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif