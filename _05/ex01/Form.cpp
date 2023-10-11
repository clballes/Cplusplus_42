#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("Default"), _signed("false"), _gradeSigned(8) , _gradeExecute(3)
{
	std::cout << "Default constructor called Form" << std::endl;
    this->_signed = false;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeSigned(gradeToSign), _gradeExecute(gradeToExecute)
{
    if (_gradeSigned < 1 || _gradeExecute < 1)
        throw Form::GradeTooHighException();
    if (_gradeSigned > 150 || _gradeExecute > 150)
        throw Form::GradeTooLowException();
}

// Form::Form(Form const & src)
// {
//     std::cout << "Copy Constructor called Form" << std::endl;
// 	*this = src;
// 	return ;
// }

Form & Form::operator=(Form const & rhs)
{
     std::cout << "Operator overload called Form";
	 if ( this != &rhs )
     {
        this->_signed = false;
     }
	return *this;
}

Form::~Form()
{
	std::cout << "Destructor called Form" << std::endl;
}

//member fcuntions

void Form::beSigned( Bureaucrat const & rhs)
{
    try
    {
        if (rhs.getGrade() < this->_gradeSigned)
        {
            this->_signed = true;
        }
        else
            throw GradeTooLowException();
    }
    catch(const GradeTooLowException& e)
    {
		std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

// getters member functions
std::string Form::getName() const
{
    return this->_name;
}

bool Form::getBool() const
{
    return this->_signed;
}

int Form::getGradeExecuted() const
{
    return this->_gradeExecute;
}

int Form::getGradeSigned() const
{
    return this->_gradeSigned;
}


std::ostream &	operator<<( std::ostream & o, Form const & rhs )
{
	o << rhs.getName() <<": Form grade: " << rhs.getGradeSigned() << "Form grede executed: " << rhs.getGradeExecuted() 
    << "Boolean grade signed: " << rhs.getBool() << std::endl;
	return o;
}