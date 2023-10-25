
#include "Bureaucrat.hpp"

int main()
{
    try
	{
        Bureaucrat bureaucrat("clara", 150);

        std::cout << bureaucrat;

        bureaucrat.incrementGrade();
        std::cout << bureaucrat;

        bureaucrat.decrementGrade();
        std::cout << bureaucrat;

	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cout << e.what() << std::endl;
    }
	catch (Bureaucrat::GradeTooLowException &e)
	{
        std::cout << e.what() << std::endl;
	}
	return 0;
}