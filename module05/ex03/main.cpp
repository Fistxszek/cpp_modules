#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat highLevel("Maciej", 5);

	Intern *intern = new Intern();
	Intern noName;

	std::cout << "\n======VALID PRESIDENTIAL FORM=======\n";
    AForm *form = intern->makeForm("presidential pardon", "target Ziom");	
	if (form)
	{
		highLevel.SignForm(*form);
		highLevel.executeForm(*form);
	}
	std::cout << "===================================\n";

	std::cout << "\n======INVALID FORM=======\n";
	AForm *f2 =	noName.makeForm("fail form", "other name");
	if (f2)
	{
		highLevel.SignForm(*f2);
		highLevel.executeForm(*f2);
	}
	std::cout << "===================================\n";

	std::cout << "\n======VALID ROBOTYOMY FORM=======\n";
	AForm *f3 = noName.makeForm("robotomy request", "michal");
	if (f3)
	{
		highLevel.SignForm(*f3);
		highLevel.executeForm(*f3);
	}
	std::cout << "===================================\n";

	std::cout << "\n======Destructors=======\n";
	delete intern;
	delete f2;
	delete f3;
	delete form;
}
