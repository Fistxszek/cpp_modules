#include "Bureaucrat.hpp"
#include <ostream>

Bureaucrat::Bureaucrat(std::string Name, int Grade)
{
	this->Name = Name;
	this->Grade = Grade;
}
Bureaucrat::Bureaucrat()
{
	Name = "";
	Grade = 0;
}
Bureaucrat::Bureaucrat(const Bureaucrat &cpyObj)
{
	this->Name = cpyObj.GetName();
	this->Grade = cpyObj.GetGrade();
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (&other != this)
	{
		this->Name = other.GetName();
		this->Grade = other.GetGrade();
	}
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &other)
{
	std::string name = other.GetName();
	int grade = other.GetGrade();

	os << name << ", bureaucrat grade " << grade << "."<< std::endl;
	return os;
}

Bureaucrat::~Bureaucrat()
{

}

const std::string &Bureaucrat::GetName() const
{
	return (this->Name);
}
int Bureaucrat::GetGrade() const
{
	return (this->Grade);
}

void Bureaucrat::IncrementGrade()
{
	if (Grade == 1)
		throw Bureaucrat::GradeTooHighException(); //tofix
	Grade--;
}
void Bureaucrat::DecrementGrade()
{
	if (Grade == 150)
		throw Bureaucrat::GradeTooLowException(); //tofix
	Grade++;
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("to high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("to low");
}
