
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat a("Advocat Santi", 4);

	Form form("Alquiler casa", 2, 0);
	// Form form2("Advocat2", 5, 4);

	form.beSigned(a);
	// form.beSigned(a);
	a.signForm(form);
	// form2.beSigned(a);

	// std::cout << form;
	// std::cout << form2;

	// a.signForm(form);
	// a.incrementGrade();
	// a.decrementGrade();
	
	return 0;
}