#ifndef ___FORM_H___
# define ___FORM_H___

#include <iostream>

class Bureaucrat;

class Form 
{
    private:
        std::string const _name;
        bool _signed;
        int const _gradeSigned;
        int const _gradeExecute;

    public:
        Form(void);
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
		// Form(Form const & src);
        Form & operator=(Form const & rhs);
		~Form();

        //member function
        void beSigned( Bureaucrat const & rhs);

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

std::ostream &	operator<<( std::ostream & o, Form const & rhs );

#endif