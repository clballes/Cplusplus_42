#include "../inc/Bureaucrat.hpp"

#include <stdexcept>

Bureaucrat::Bureaucrat( void )
{
	std::cout << "Default constructor called Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Constructor called in Bureaucrat for name: " << this->_name << " and grade is : " << this ->_grade << std::endl;
	if (this->_grade > 150)
		throw GradeTooLowException();
	if (this->_grade < 1)
		throw GradeTooHighException();
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
	if (this->_grade < 1)
	{
		throw GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade()
{
	this->_grade++;
	if (this->_grade > 150)
	{
		throw GradeTooLowException();
	}
}


void Bureaucrat::signForm(AForm &Aform)
{
	try {
        Aform.beSigned( *this );
        std::cout << this->_name << " signed " << Aform.getName() << std::endl;
    } catch (AForm::GradeTooLowException &e) {
        std::cout << _name << " coulnd't sign " << Aform.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
	 try {
        form.execute( *this );
    } catch ( std::exception& e ) {
        std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
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
	o << "Name is: " << rhs.getName() <<": bureaucrat grade: " << rhs.getGrade() << std::endl;
	return o;
}

// ------------------------------ Exception messages --------------------------------

const char *Bureaucrat:: GradeTooLowException::what() const throw()
{
	return "Grade is too low, it cannot be lower than 150";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high, 1 is the highest value possible";
}