#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
{
	std::cout << "Default constructor called PresidentialPardonForm" << std::endl;

}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("presidential pardon", 25, 5), _target(target)
{
	std::cout << "Constructor called PresidentialPardonForm target: " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
{
	std::cout << "Copy operator called for PresidentialPardonForm" << std::endl;
	*this = src;
	return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	std::cout << "Operator called for PresidentialPardonForm" << std::endl;
	(void)rhs;
	return *this;

}

//getters
std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << "Target: " << this->_target << " has been pardon by Zaphod Beeblebrox." << std::endl;		
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Default destructor called for PresidentialPardonForm" << std::endl;
}
