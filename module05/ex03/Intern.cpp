#include "Intern.hpp"

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
void Intern::makeForm(std::string formName, std::string formTarget)
{
	
}
