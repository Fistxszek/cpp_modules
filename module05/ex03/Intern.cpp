#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

Intern::Intern(void)
{
	std::cout << "Empty intern constructor called\n";
}
Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor called\n";
}
Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern copy operator called\n";
	//if (*this != other)
		//something
	return *this;
}
Intern::~Intern(void)
{
	std::cout << "Intern denstructor called\n";
}
#include <map>
void Intern::makeForm(std::string formName, std::string formTarget)
{

	std::map<std::string, AForm> formsTypes = {{"ShrubberyCreationForm", ShrubberyCreationForm}, {"RobotomyRequestForm", RobotomyRequestForm}, {"PresidentialPardonForm", PresidentialPardonForm}};
	AForm res = formsTypes[formName];

	switch (res)
	{
		case (0)://shrubbery creation form
			break;
		case (1)://robotomy request form
			break;
		case (2)://presidentail pardon
			break;
	}
}
