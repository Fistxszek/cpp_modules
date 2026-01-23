#include "Intern.hpp"
#include "Bureaucrat.hpp"

Intern::Intern(void)
{
	std::cout << "Empty intern constructor called\n";
}
Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor called\n";
	*this = other;
}
Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern copy operator called\n";
	if (this == &other)
		return *this;
	return *this;
}
Intern::~Intern(void)
{
	std::cout << "Intern denstructor called\n";
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::map<std::string, Forms> formsTypes;
    formsTypes["shrubbery creation"] =  Shrubbery;
    formsTypes["robotomy request"] = Robotomy;
    formsTypes["presidential pardon"] = Presidential;

	Forms type;
	try
	{
		 type = formsTypes.at(formName);
	}
	catch (std::out_of_range& e)
	{
		std::cerr << RED << "ERROR: Form name '" << formName << "' doesn't exist." << std::endl << RESET;
		return NULL;
	}

	switch (type)
	{
		case (Shrubbery):
			return new ShrubberyCreationForm(formTarget);
			break;
		case (Robotomy):
			return new RobotomyRequestForm(formTarget);
			break;
		case (Presidential):
			return new PresidentialPardonForm(formTarget);
			break;
	}
	return NULL;
}
