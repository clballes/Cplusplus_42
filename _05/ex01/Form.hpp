#ifndef ___FORM_H___
# define ___FORM_H___

#include <iostream>

class Bureaucrat;

class Form 
{
    private:
        std::string const	 _name;
        bool 				_ifSigned;
        int const 			_gradeToSign;
        int const 			_gradeToExecute;

    public:
        Form(void);
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(Form const & src);
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
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

std::ostream &	operator<<( std::ostream & o, Form const & rhs );

#endif