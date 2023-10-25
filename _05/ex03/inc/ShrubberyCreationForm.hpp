#ifndef ___SHRUBBERYCREATIONFORM__H__
# define ___SHRUBBERYCREATIONFORM__H__

#include <iostream>
#include "../inc/AForm.hpp"


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
		void execute(Bureaucrat const & executor) const;
};

#endif
