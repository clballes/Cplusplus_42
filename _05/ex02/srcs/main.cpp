
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"



int main()
{
	Bureaucrat a("Advocat Santi", 150);
	ShrubberyCreationForm b("mica");
	b.beSigned(a);
	b.execute(a);
	// b.execute
	return 0;
}