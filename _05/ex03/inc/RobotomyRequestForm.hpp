#ifndef ___ROBOTOMYREQUESTFORM__H__
# define ___ROBOTOMYREQUESTFORM__H__

#include <iostream>
#include "../inc/AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string const	 _target;

	public:
		RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
        RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
		~RobotomyRequestForm();

		//getters
		std::string getTarget() const;

		//member functions
		void execute(Bureaucrat const & executor) const;
};

#endif
