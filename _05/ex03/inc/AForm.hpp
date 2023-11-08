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
		//pure virtual function = 0
		virtual void execute(Bureaucrat const & executor) const = 0;
		virtual AForm *clone( )const = 0;

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
		class NotSignedException : public std::exception
		{
        	public:
            	virtual const char* what() const throw();
    };
};

std::ostream &	operator<<( std::ostream & o, AForm const & rhs );

#endif