#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

AForm::AForm(void) : _name(""), _ifSigned(false), _gradeToSign(0) , _gradeToExecute(0)
{
	std::cout << "Default constructor called AForm" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _ifSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Constructor called AForm: " << this->_name << " gradeToSign: " << this->_gradeToSign << " gradeToExceute: " << this->_gradeToExecute << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & src) : _name(src._name), _ifSigned(src._ifSigned), _gradeToSign(src._gradeToSign) , _gradeToExecute(src._gradeToExecute)
{
    std::cout << "Copy Constructor called AForm" << std::endl;
	*this = src;
	return ;
}

AForm & AForm::operator=(AForm const & rhs)
{
	std::cout << "Operator overload called AForm";
	if ( this != &rhs )
	{
		this->_ifSigned = false;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "Destructor called AForm" << std::endl;
}

//member functions
void AForm::beSigned( Bureaucrat const & rhs)
{
   if (rhs.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	else
	{
		this->_ifSigned = true;
		std::cout << "BeSigned: Form is going to be signed" << std::endl;
	}
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (this->_ifSigned == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
	else	
        std::cout << "Execute: The form is going to be execute" << std::endl;
}

// getters member functions
std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getBool() const
{
    return this->_ifSigned;
}

int AForm::getGradeExecuted() const
{
    return this->_gradeToExecute;
}

int AForm::getGradeSigned() const
{
    return this->_gradeToSign;
}


std::ostream &	operator<<( std::ostream & o, AForm const & rhs )
{
	o << "AForm's name: " << rhs.getName() <<" || Grade required to sign Aform: " << rhs.getGradeSigned() << " || Grade required to execute the Aform: " << rhs.getGradeExecuted() 
    << " || Is it the Aform signed? " << std::boolalpha << rhs.getBool() << " ||" << std::endl;
	return o;
}

// ---------- exceptions
const char *AForm:: GradeTooLowException::what() const throw()
{
	return "Grade is too low in form ";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high in form ";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form is not signed ";
}
