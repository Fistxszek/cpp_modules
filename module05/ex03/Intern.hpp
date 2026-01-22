#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		virtual ~Intern(void);
		AForm *makeForm(std::string formName, std::string formTarget);
};

enum Forms
{
	Shrubbery,
	Robotomy,
	Presidential
};
