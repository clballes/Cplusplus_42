
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"




int main()
{
	Bureaucrat a("Advocat Santi", 150);
	ShrubberyCreationForm b("mica");
	RobotomyRequestForm c("xavi");
	PresidentialPardonForm p("andrea");
	c.beSigned(a);
	c.execute(a);
	b.beSigned(a);
	b.execute(a);
	p.beSigned(a);
	p.execute(a);

	return 0;
}