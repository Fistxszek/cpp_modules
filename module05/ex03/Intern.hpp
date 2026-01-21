#pragma once

#include "Bureaucrat.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		virtual ~Intern(void);
		void makeForm(std::string formName, std::string formTarget);
};
