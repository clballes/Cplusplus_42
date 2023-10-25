
#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream> 

ShrubberyCreationForm::ShrubberyCreationForm(void)
{
	std::cout << "Default constructor called ShrubberyCreationForm" << std::endl;

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("shruberry creation", 145, 137), _target(target)
{
	std::cout << "Constructor called ShrubberyCreationForm target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
{
	std::cout << "Copy operator called for ShrubberyCreationForm" << std::endl;
	*this = src;
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	std::cout << "Operator called for ShrubberyCreationForm" << std::endl;
	(void)rhs;
	return *this;
}

//getters
std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
		AForm::execute(executor);
		std::ofstream outfile (this->_target + "_shrubbery.txt");
		outfile << "       _-_       " << std::endl;
		outfile << "    /~~   ~~\\   " << std::endl;
		outfile << " /~~         ~~\\" << std::endl;
		outfile << "{               }" << std::endl;
		outfile << " \\  _-     -_  /" << std::endl;
		outfile << "   ~  \\\\ //  ~ " << std::endl;
		outfile << "_- -   | | _- _  " << std::endl;
		outfile << "  _ -  | |   -_  " << std::endl;
		outfile << "      // \\\\    " << std::endl;
		outfile.close();
		return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Default destructor called for ShrubberyCreationForm" << std::endl;
}
