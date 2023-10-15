#ifndef ___PRESIDENTIALPARDONFORM__H__
# define ___PRESIDENTIALPARDONFORM__H__

#include <iostream>
#include "../inc/AForm.hpp"

// class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private:
        std::string const	 _target;

	public:
		PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
        PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
		~PresidentialPardonForm();

		//getters
		std::string getTarget() const;

		//member functions
		void execute(Bureaucrat const & executor) const;
};
#endif
//  Required grades: sign 25, exec 5 Informs that <target> has been pardoned by Zaphod Beeblebrox.