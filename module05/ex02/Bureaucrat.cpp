#include "Bureaucrat.hpp"
#include <iterator>

Bureaucrat::Bureaucrat(std::string Name, int Grade) : _name(Name)
{
	std::cout << "Bureaucrat constructor called\n";
	if (Grade > 150)
		throw Bureaucrat::GradeTooLowException("Constructor grade value of [" + this->GetName() +  "] is too low.");
	else if (Grade < 1)
		throw Bureaucrat::GradeTooHighException("Constructor grade value of [" + this->GetName() + "] is too high.");
	this->_grade = Grade;
}
Bureaucrat::Bureaucrat() : _name("")
{
	std::cout << "Empty Bureaucrat constructor called\n";
	_grade = 150;
}
Bureaucrat::Bureaucrat(const Bureaucrat &cpyObj) : _name(cpyObj.GetName())
{
	std::cout << "Copy Bureaucrat constructor called\n";
	*this = cpyObj;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Copy Bureaucrat operator called\n";
	if (&other != this)
	{
		this->_grade = other.GetGrade();
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
	std::cout << "Bureaucrat destructor called\n";
}

const std::string &Bureaucrat::GetName() const
{
	return (this->_name);
}
int Bureaucrat::GetGrade() const
{
	return (this->_grade);
}

void Bureaucrat::IncrementGrade()
{
	int startGrade = this->GetGrade();
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException("Incremention failed: [" + this->GetName() + "] grade is already highest possible.");
	_grade--;
	std::cout << this->GetName() << "'s grade" << " has been incremented from " << startGrade << " to " << this->GetGrade() << std::endl;
}
void Bureaucrat::DecrementGrade()
{
	int startGrade = this->GetGrade();
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException("Decremention failed: [" + this->GetName() + "] grade is already lowest possible.");
	_grade++;
	std::cout  << this->GetName() << "'s grade"<< " has been decremented from " << startGrade << " to " << this->GetGrade() << std::endl;
}
void Bureaucrat::SignForm(AForm &FormToSign)
{
	try
	{
		if (FormToSign.BeSigned(*this))
			std::cout << GREEN << this->GetName() << " signed " << FormToSign.GetName() << std::endl << RESET;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cout << RED << this->GetName() << " couldn't sign " << FormToSign.GetName() << " because " << e.what() << "." << std::endl <<  RESET;
	}
	catch (const AForm::GradeTooHighException &e)
	{
		std::cout << RED << this->GetName() << " couldn't sign " << FormToSign.GetName() << " because " << e.what() << "." << std::endl << RESET;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		if (!form.execute(*this))
			return ;
		std::cout << GREEN << this->GetName() << " executed " << form.GetName() << RESET << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << RED << e.what() << "." << std::endl << RESET;
	}
}

Bureaucrat::GradeTooLowException::GradeTooLowException() : _message("Grade too low"){}
Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &message) : _message(message){}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::GradeTooHighException::GradeTooHighException() : _message("Grade too high"){}
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &message) : _message(message){}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (_message.c_str());
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (_message.c_str());
}
