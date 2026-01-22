#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Intern *a = new Intern();
    AForm *form = a->makeForm("PresidentialPardonForm", "target Ziom");	
	delete a;
	delete form;
}
