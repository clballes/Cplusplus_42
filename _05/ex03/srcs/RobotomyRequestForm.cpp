
#include "../inc/RobotomyRequestForm.hpp"
#include <fstream> 

RobotomyRequestForm::RobotomyRequestForm(void)
{
	std::cout << "Default constructor called RobotomyRequestForm" << std::endl;

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("robotomy request", 72, 45), _target(target)
{
	std::cout << "Constructor called RobotomyRequestForm target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src)
{
	std::cout << "Copy operator called for RobotomyRequestForm" << std::endl;
	*this = src;
	return ;
}

AForm *	RobotomyRequestForm::clone( void ) const
{
	AForm* clone = new RobotomyRequestForm(*this);
	return (clone);
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	std::cout << "Operator called for RobotomyRequestForm" << std::endl;
	(void)rhs;
	return *this;

}

//getters
std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
		AForm::execute(executor);

        static int  i;
        if ( i % 2 == 0 )
            std::cout << "BZZZZZT! " << this->_target << " has been robotomized!" << std::endl;
        else
            std::cout << this->_target << ": robotomization failed! " << std::endl;
        i++;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Default destructor called for RobotomyRequestForm" << std::endl;
}
