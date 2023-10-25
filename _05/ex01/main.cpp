
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
       Bureaucrat a("Advocat Santi", 4);
	   
	   Form form("Alquiler casa", 5, 1);
	   
	   a.signForm(form);
	}
	catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
    }

	return 0;
}