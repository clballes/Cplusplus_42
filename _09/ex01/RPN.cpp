#include "RPN.hpp"

RPN::RPN( std::string argv ) : _result(0)
{
    //std::cout << "Default Constructor called RPN" << std::endl;
    int i = 1;
    while (argv[argv.size() - i] == ' ')
        i++;
    if(argv[argv.size() - i] != '+' && argv[argv.size() - i] != '-' && argv[argv.size() - i] != '*'  && argv[argv.size() - i] != '/')
    {
        throw ErrorSyntax();
    }
    for(unsigned long int i = 0; i < argv.size(); i++)
    {
        if (argv[i] != 32)
        {
            if (isdigit(argv[i]) && isdigit(argv[i + 1]))
            {
                throw ErrorNums();
            }
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
                throw ErrorNums();
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
        throw ErrorSyntax();
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
    //std::cout << "Default Destrcutor called RPN" << std::endl;
}

std::ostream &	operator<<( std::ostream & os, std::stack<int> my_stack )
{
    while(!my_stack.empty())
    {
        os << my_stack.top() << " ";
        my_stack.pop();
    }
    return os;
}

// ----------------------------- EXCEPTIONS --------------------------


const char * RPN::ErrorDivision::what() const throw()
{
    return "Error: cannot divide by 0";
}

const char * RPN::ErrorNums::what() const throw()
{
    return "Error: Digits from 0 to 9.";
}

const char * RPN::ErrorSyntax::what() const throw()
{
    return "Error: It is not the correct RPN format.";
}