
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
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
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cout << e.what() << std::endl;
    }
	catch (Bureaucrat::GradeTooLowException &e)
	{
        std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
        std::cout << e.what() << std::endl;
    }
	catch (Form::GradeTooLowException &e)
	{
        std::cout << e.what() << std::endl;
	}
	return 0;
}