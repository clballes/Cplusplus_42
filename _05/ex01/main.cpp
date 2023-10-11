
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat a("clara", 100);
	// std::cout << a;
	Form form;
	// form.beSigned(a);
	a.signForm(form);
	// a.incrementGrade();
	// a.decrementGrade();
	
	return 0;
}