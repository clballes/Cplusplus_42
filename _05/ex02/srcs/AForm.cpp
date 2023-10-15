#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

AForm::AForm(void) : _name("Default"), _ifSigned("false"), _gradeToSign(0) , _gradeToExecute(0)
{
	std::cout << "Default constructor called AForm" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _ifSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Constructor called AForm: " << this->_name << " gradeToSign: " << this->_gradeToSign << " gradeToExceute: " << this->_gradeToExecute << std::endl;
	try
    {
        if (_gradeToSign < 1 || _gradeToExecute < 1)
        	throw AForm::GradeTooHighException();
    	if (_gradeToSign > 150 || _gradeToExecute > 150)
        	throw AForm::GradeTooLowException();
    }
    catch(const AForm::GradeTooLowException& e)
    {
		std::cout << "AForm exception: " << e.what() << ", try other numbers to initialize between 1 - 150" << std::endl;
    }
    catch(const AForm::GradeTooHighException& e)
	{
		std::cout << "AForm exception: " << e.what() << ", try other numbers to initialize between 1 - 150" << std::endl;
	}
}

AForm::AForm(AForm const & src) : _name("Default"), _ifSigned("false"), _gradeToSign(getGradeSigned()) , _gradeToExecute(getGradeExecuted())
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
    try
    {
        if (rhs.getGrade() >= this->_gradeToSign)
        {
            this->_ifSigned = true;
			std::cout << "BeSigned: AForm is going to be signed" << std::endl;
        }
        else
            throw AForm::GradeTooLowException();
    }
    catch(const AForm::GradeTooLowException& e)
    {
		std::cout << "BeSigned exception: " << e.what() << " to be signed" << std::endl;
    }
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (this->_ifSigned == true  && (executor.getGrade() >= this->_gradeToExecute))
    {
        std::cout << "Execute: The form is going to be execute" << std::endl;
    }
    else
    {
        throw AForm::GradeTooLowException();
    }
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