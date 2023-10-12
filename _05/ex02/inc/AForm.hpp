#ifndef ___FORM_H___
# define ___FORM_H___

#include <iostream>

class Bureaucrat;

class AForm 
{
    private:
        std::string const	 _name;
        bool 				_ifSigned;
        int const 			_gradeToSign;
        int const 			_gradeToExecute;

    public:
        AForm(void);
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(AForm const & src);
        AForm & operator=(AForm const & rhs);
		~AForm();

        //member function
        void beSigned( Bureaucrat const & rhs);
		virtual void execute(Bureaucrat const & executor) const = 0;

        // getters
        std::string getName() const;
        bool getBool() const;
		int getGradeExecuted() const;
		int getGradeSigned() const;

        // ---------------------- class excpecions ------------------------- 
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Grade is too high";
				}
		};
		class GradeTooLowException
		{
			public:
				const char *what() const throw()
				{
					return "Grade is too low";
				}
		};

};

std::ostream &	operator<<( std::ostream & o, AForm const & rhs );

#endif