#ifndef __BUREAUCRAT___H__
# define __BUREAUCRAT___H__

#include <iostream>
#include "Form.hpp"

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
		void signForm(Form &form);

		// ---------------------- class excpecions ------------------------- 
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Grade is too high, 1 is the highest value possible";
				}
		};
		class GradeTooLowException
		{
			public:
				const char *what() const throw()
				{
					return "Grade is too low, it cannot be lower than 150";
				}
		};
};

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif