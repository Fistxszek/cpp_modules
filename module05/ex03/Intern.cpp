#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

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
	FormPair pairs[3] = 
	{
		{"shrubbery creation", Shrubbery},
		{"robotomy request", Robotomy},
		{"presidential pardon", Presidential}	
	};
	Forms type = None;
	for (int i = 0; i < 3; i++)
	{
		if (pairs[i]._name == formName)
		{
			type = pairs[i]._type;
			break;
		}
	}

	switch (type)
	{
		case (None):
			std::cerr << RED << "ERROR: Form name '" << formName << "' doesn't exist." << std::endl << RESET;
			return NULL;
			break;
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
