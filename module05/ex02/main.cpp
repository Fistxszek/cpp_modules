#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat adam("Adam", 1);
	PresidentialPardonForm test("dupa");
	ShrubberyCreationForm a("kwiatki");
	RobotomyRequestForm b("okok");
	adam.executeForm(test);
	adam.executeForm(a);
	adam.executeForm(b);
}
