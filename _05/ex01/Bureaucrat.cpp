#include "Bureaucrat.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat( void )
{
	std::cout << "Default constructor called Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Constructor called in Bureaucrat for name: " << this->_name << " and grade is : " << this ->_grade << std::endl;
	try
	{
		if (this->_grade > 150)
		{
			throw GradeTooLowException();
		}
	}
	catch(GradeTooLowException& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try
	{
		if (this->_grade < 1)
		{
			throw GradeTooHighException();
		}
	}
	catch(GradeTooHighException& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
    std::cout << "Copy Constructor called Bureaucrat" << std::endl;
	*this = src;
	return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
    std::cout << "Operator overload called Bureaucrat";
	 if ( this != &rhs )
       this->_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called in Bureaucrat" << std::endl;
}




//member functions
void Bureaucrat::incrementGrade()
{
	this->_grade--;
	try
	{
		if (this->_grade < 1)
		{
			throw GradeTooHighException();
		}
	}
	catch(GradeTooHighException& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	this->_grade++;
	try
	{
		if (this->_grade > 150)
		{
			throw GradeTooLowException();
		}
	}
	catch(GradeTooLowException& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}


void Bureaucrat::signForm(Form &form)
{
	try
	{
    	if (form.getBool() == true)
		{
        	std::cout << "Bureaucrat's name: " << getName() << " signed " << "Form name: " << form.getName() << std::endl;
		}
		else
			throw Form::GradeTooLowException();

	}
    catch(const Form::GradeTooLowException& e)
	{
        std::cout << "Bureaucrat's name: " << getName()  << " couldn't sign " << form.getName() << " because "<< e.what() << std::endl;
	}
}


//getters

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs )
{
	o << rhs.getName() <<": bureaucrat grade: " << rhs.getGrade() << std::endl;
	return o;
}