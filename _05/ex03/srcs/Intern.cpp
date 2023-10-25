#include "../inc/Intern.hpp"



Intern::Intern(void)
{
	std::cout << "Default constructor called Intern" << std::endl;
}

Intern::Intern(Intern const & src)
{
	*this = src;
	return ;
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Default destructor called Intern" << std::endl;
}

//member function
AForm* Intern::makeForm(std::string name, std::string target)
{
	ShrubberyCreationForm	shrubbery		= ShrubberyCreationForm(target);
	RobotomyRequestForm		robotomy		= RobotomyRequestForm(target);
	PresidentialPardonForm	presidential	= PresidentialPardonForm(target);

	AForm*	forms[] = {&shrubbery, &robotomy, &presidential};

	// AForm* forms[3] = {
	// 	new RobotomyRequestForm( target),
	// 	new PresidentialPardonForm(target),
	// 	new ShrubberyCreationForm(target)
	// };

	for(int i = 0; i < 3; i++)
	{
		if (forms[i]->getName() == name)
		{
			std::cout << " * Intern creates " << name << " *" << std::endl;
			return forms[i];
		}
	}
	std::cout << "* No match found for the intern *" << std::endl;
	return nullptr;
}