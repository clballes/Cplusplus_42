#include "Bureaucrat.hpp"
#include <stdexcept>


Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Constructor called in Bureaucrat for name: " << this->_name << " and grade is : " << this ->_grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
    std::cout << "Copy Constructor called Bureaucrat" << std::endl;
	*this = src;
	return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
    std::cout << "Operator overload called Bureaucrat" << std::endl;
	// this->_name = _name;
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
			std::cout << "estic en increment" << std::endl;
			throw std::exception();
		}
	}
	catch(GradeTooHighException& e)
	{
		std::cout << "estic en catch" << std::endl;
		// Bureaucrat::GradeTooHighException();
	}
}
void Bureaucrat::decrementGrade()
{
	this->_grade++;
	// if (grade > 150)
	// {

	// }
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

// std::ostream operator<<(std::ostream & o, Bureaucrat const & rhs)
// {
// 	o << rhs.getName();
// 	return o;
// }

