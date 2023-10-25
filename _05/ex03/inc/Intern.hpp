#ifndef __INTERN___H__
# define __INTERN___H__

#include <iostream>
#include "AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

class Intern
{
	public:
		//canonical form 
		Intern(void);
		Intern(Intern const & src);
        Intern & operator=(Intern const & rhs);
		~Intern();

	//member functions
	AForm* makeForm(std::string name, std::string target) ;
};

#endif