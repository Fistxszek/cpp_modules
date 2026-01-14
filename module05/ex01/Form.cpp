#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <sstream>


Form::Form() : _name(""), _isSigned(false), _gradeRequiredToSign(150) ,_gradeRequiredToExecute(150) 
{
	std::cout << "Empty Form Constructor called\n";
}

Form::Form(std::string Name, bool IsSigned, int GradeRequiredToSign, int GradeRequiredToExecute) :_name(Name), _isSigned(IsSigned), _gradeRequiredToSign(GradeRequiredToSign), _gradeRequiredToExecute(GradeRequiredToExecute)
{
	std::cout << "Form Constructor called\n";
}

Form::Form(const Form &other) : _name(other.GetName()), _gradeRequiredToSign(other.GetGradeRequiredToSign()), _gradeRequiredToExecute(other.GetGradeRequiredToExecute())
{
	std::cout << "Form Constructor called\n";

	*this = other;
}

Form& Form::operator=(const Form &other)
{
	std::cout << "Copy operator called\n";
	if (this != &other)
	{
		this->_isSigned = other.GetIsSigned();	
	}
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Form &other)
{
	os << "Form: " << other.GetName()
		<< ", signed status: " << (other.GetIsSigned() == 1 ? "true" : "false")
		<< ", grade to sign: " << other.GetGradeRequiredToSign()
		<< ", grade to execute: "
		<< other.GetGradeRequiredToExecute() << "."<< std::endl;
	return os;
}

Form::~Form()
{
	std::cout << "Form destructor called\n";
}

const std::string &Form::GetName() const
{
	return this->_name;
}

bool Form::GetIsSigned() const
{
	return this->_isSigned;
}

int Form::GetGradeRequiredToSign() const
{
	return this->_gradeRequiredToSign;	
}

int Form::GetGradeRequiredToExecute() const
{
	return this->_gradeRequiredToExecute;	
}

bool Form::BeSigned(Bureaucrat &SigningBureaucrat)
{
	int requiredToSign = this->GetGradeRequiredToSign();
	
	if (SigningBureaucrat.GetGrade() <= requiredToSign)
		this->_isSigned = true;
	else
	{
		std::stringstream ss;
		ss << "required grade to sign is: " << requiredToSign << ", but " << SigningBureaucrat.GetName() << " has only grade " << SigningBureaucrat.GetGrade();
		throw Form::GradeTooLowException(ss.str());
	}
	return this->GetIsSigned();
}

void Form::SignForm(Bureaucrat &SigningBureaucrat)
{
	try
	{
		if (Form::BeSigned(SigningBureaucrat))
			std::cout << GREEN << SigningBureaucrat.GetName() << " signed " << this->GetName() << std::endl << RESET;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << RED << SigningBureaucrat.GetName() << " couldn't sign " << this->GetName() << " because " << e.what() << "." << std::endl <<  RESET;
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cout << RED << SigningBureaucrat.GetName() << " couldn't sign " << this->GetName() << " because " << e.what() << "." << std::endl << RESET;
	}
}

Form::GradeTooLowException::GradeTooLowException() : _message("Grade too low"){}
Form::GradeTooLowException::GradeTooLowException(const std::string &message) : _message(message){}
Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::GradeTooHighException::GradeTooHighException() : _message("Grade too high"){}
Form::GradeTooHighException::GradeTooHighException(const std::string &message) : _message(message){}
Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Form::GradeTooHighException::what() const throw()
{
	return (_message.c_str());
}

const char* Form::GradeTooLowException::what() const throw()
{
	return (_message.c_str());
}
