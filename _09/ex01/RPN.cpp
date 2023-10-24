#include "RPN.hpp"
#include <stdlib.h>
#include <sstream>


RPN::RPN( std::string argv ) : _result(0)
{
    std::cout << "Default Constructor called RPN" << std::endl;
    for(unsigned long int i = 0; i < argv.size(); i++)
    {
        if (argv[i] != 32)
        {
            if (isdigit(argv[i]))
            {
                this->stack.push(argv[i] - '0');
            }
            else if(argv[i] == '+' || argv[i] == '-' || argv[i] == '*'  || argv[i] == '/')
            {
                if (calculate(argv[i]) == false)
                    return ;
            }
            else
            {
                std::cerr << "Error" << std::endl;
                return ;
            }
        }
    }
    std::cout << "Result: " << this->_result << std::endl;

}

RPN::RPN(RPN const & src)
{
    *this = src;
    return ;
}

RPN & RPN::operator=(RPN const & rhs)
{
    (void)rhs;
    return *this;
}

bool RPN::calculate(char op)
{
    if (stack.size() < 2)
    {
        std::cerr << "Error size stack too small" << std::endl;
        return false;
    }
    int num1 = stack.top();
    stack.pop();
    int num2 = stack.top();
    stack.pop();
    operations(op, num2, num1);
    stack.push(this->_result);
    return true;
}


void RPN::operations(char op, int num1, int num2)
{
    switch (op) {
    case '+':
        this->_result = num1 + num2;
        break;
    case '-':
    {
        this->_result = num1 - num2;   
        break;
    }
    case '*':
        this->_result = num1 * num2;
        break;
    case '/':
        this->_result = num1 / num2;
        if (num2 == 0)
        {
            throw ErrorDivision();
        }
        break;
    default:
        std::cerr << "Error: Unknown operand." << std::endl;
        return ;
    }
}

RPN::~RPN()
{
    std::cout << "Default Destrcutor called RPN" << std::endl;
}

const char * RPN::ErrorDivision::what() const throw()
{
    return "cannot divide by 0";
}