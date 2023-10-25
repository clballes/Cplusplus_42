#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(void) : _name("Default"), _ifSigned(false), _gradeToSign(0) , _gradeToExecute(0)
{
	std::cout << "Default constructor called Form" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _ifSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Constructor called Form: " << this->_name << " gradeToSign: " << this->_gradeToSign << " gradeToExceute: " << this->_gradeToExecute << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & src) : _name("Default"), _ifSigned("false"), _gradeToSign(getGradeSigned()) , _gradeToExecute(getGradeExecuted())
{
    std::cout << "Copy Constructor called Form" << std::endl;
	*this = src;
	return ;
}

Form & Form::operator=(Form const & rhs)
{
     std::cout << "Operator overload called Form";
	 if ( this != &rhs )
     {
        this->_ifSigned = false;
     }
	return *this;
}

Form::~Form()
{
	std::cout << "Destructor called Form" << std::endl;
}

//member functions

void Form::beSigned( Bureaucrat const & rhs)
{
	if (rhs.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
	{
		this->_ifSigned = true;
		std::cout << "BeSigned: Form is going to be signed" << std::endl;
	}
}

// getters member functions
std::string Form::getName() const
{
    return this->_name;
}

bool Form::getBool() const
{
    return this->_ifSigned;
}

int Form::getGradeExecuted() const
{
    return this->_gradeToExecute;
}

int Form::getGradeSigned() const
{
    return this->_gradeToSign;
}


std::ostream &	operator<<( std::ostream & o, Form const & rhs )
{
	o << "Form's name: " << rhs.getName() <<" || Grade required to sign form: " << rhs.getGradeSigned() << " || Grade required to execute the form: " << rhs.getGradeExecuted() 
    << " || Is it the form signed? " << std::boolalpha << rhs.getBool() << " ||" << std::endl;
	return o;
}

//exceptions

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high in form";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low in form";
}