
#include "../inc/RobotomyRequestForm.hpp"
#include <fstream> 

RobotomyRequestForm::RobotomyRequestForm(void)
{
	std::cout << "Default constructor called RobotomyRequestForm" << std::endl;

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("default", 72, 45), _target(target)
{
	std::cout << "Constructor called RobotomyRequestForm target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
{
	std::cout << "Copy operator called for RobotomyRequestForm" << std::endl;
	*this = src;
	return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	std::cout << "Operator called for RobotomyRequestForm" << std::endl;
	if ( this != &rhs )
		*this = rhs.getTarget();
	return *this;

}

//getters
std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
    {
		AForm::execute(executor);
		std::cout << "DRILL NOISEEEEEEE PFPFPFPFPFPFPFP" << std::endl;		
		std::cout << "Target: " << this->_target << " has been robotomized successfully 50% of the time " << std::endl;		
    }
    catch(const AForm::GradeTooLowException& e)
    {
		std::cout << "Execution Robotomy exception: the robotomization has failed" << std::endl;
    }
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Default destructor called for RobotomyRequestForm" << std::endl;
}
