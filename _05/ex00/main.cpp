
#include "Bureaucrat.hpp"

int main()
{
	// Bureaucrat a("clara", 0);
	// std::cout << a;
    try {
        Bureaucrat bureaucrat("ash", 1);

        std::cout << bureaucrat;

        bureaucrat.incrementGrade();
        // bureaucrat.decrementGrade();
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
	// a.incrementGrade();
	// a.decrementGrade();
	
	return 0;
}