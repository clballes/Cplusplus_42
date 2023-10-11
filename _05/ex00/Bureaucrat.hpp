#ifndef __BUREAUCRAT___H__
# define __BUREAUCRAT___H__

#include <iostream>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		//canonical form 
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

		//class too high nested 
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					// std::cout << "estic en gradeeeee" << std::endl;
					return "Grade is too high";
				}
		};

		class GradeTooLowException
		{
			public:
				const char *what() const throw()
				{
					return "Grade is low high";
				}
		};
};

// std::ostream operator<<(std::ostream & o, Bureaucrat const & rhs);



#endif