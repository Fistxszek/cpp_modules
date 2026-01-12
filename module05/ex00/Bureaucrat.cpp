#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string Name)
{

}
Bureaucrat::Bureaucrat()
{

}
Bureaucrat::Bureaucrat(const Bureaucrat &cpyObj)
{

}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{

}

Bureaucrat::~Bureaucrat()
{

}

const std::string &Bureaucrat::GetName() const
{
	return (this->Name);
}
const int Bureaucrat::GetGrade() const
{
	return (this->Grade);
}

void Bureaucrat::IncrementGrade()
{
	if (Grade == 1)
		throw ThrowExepction(); //tofix
	Grade--;
}
void Bureaucrat::DecrementGrade()
{
	if (Grade == 150)
		ThrowExepction(); //tofix
	Grade++;
}
