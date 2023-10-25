#ifndef __BUREAUCRAT___H__
# define __BUREAUCRAT___H__

#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		//canonical form 
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
        Bureaucrat & operator=(Bureaucrat const & rhs);
		~Bureaucrat();
		
		//getters
		std::string getName() const;
		int getGrade() const;

		//methods function
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const & form);

		// ---------------------- class excpecions ------------------------- 
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif