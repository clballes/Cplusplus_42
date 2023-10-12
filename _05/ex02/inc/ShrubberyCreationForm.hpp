#ifndef ___SHRUBBERYCREATIONFORM__H__
# define ___SHRUBBERYCREATIONFORM__H__

#include <iostream>
#include "../inc/AForm.hpp"

// class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string const	 _target;

	public:
		ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
		~ShrubberyCreationForm();

		//getters
		std::string getTarget() const;

		//member functions
		void executeS(Bureaucrat const & executor) const;
};

// std::ostream &	operator<<( std::ostream & o, ShrubberyCreationForm const & rhs );

#endif

// ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.