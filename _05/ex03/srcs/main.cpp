
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"


int main()
{
	Intern  someRandomIntern;
    AForm*   rrf;
	// rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	// rrf = someRandomIntern.makeForm("shruberry creation", "Bender");
	std::cout << "A "<< rrf->getName() << std::endl;
	delete rrf;
	return 0;
}