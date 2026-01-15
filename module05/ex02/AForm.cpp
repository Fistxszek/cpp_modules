#include "AForm.hpp"

AForm::AForm() : _name(""), _isSigned(false), _gradeRequiredToSign(150) ,_gradeRequiredToExecute(150) 
{
	std::cout << "Empty AForm Constructor called\n";
}

AForm::AForm(std::string Name, bool IsSigned, int GradeRequiredToSign, int GradeRequiredToExecute) :_name(Name), _isSigned(IsSigned), _gradeRequiredToSign(GradeRequiredToSign), _gradeRequiredToExecute(GradeRequiredToExecute)
{
	std::cout << "AForm Constructor called\n";
}

AForm::AForm(const AForm &other) : _name(other.GetName()), _gradeRequiredToSign(other.GetGradeRequiredToSign()), _gradeRequiredToExecute(other.GetGradeRequiredToExecute())
{
	std::cout << "AForm Constructor called\n";

	*this = other;
}

AForm& AForm::operator=(const AForm &other)
{
	std::cout << "Copy operator called\n";
	if (this != &other)
	{
		this->_isSigned = other.GetIsSigned();	
	}
	return *this;
}

std::ostream& operator<<(std::ostream &os, const AForm &other)
{
	os << "AForm: " << other.GetName()
		<< ", signed status: " << (other.GetIsSigned() == 1 ? "true" : "false")
		<< ", grade to sign: " << other.GetGradeRequiredToSign()
		<< ", grade to execute: "
		<< other.GetGradeRequiredToExecute() << "."<< std::endl;
	return os;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called\n";
}

const std::string &AForm::GetName() const
{
	return this->_name;
}

bool AForm::GetIsSigned() const
{
	return this->_isSigned;
}

int AForm::GetGradeRequiredToSign() const
{
	return this->_gradeRequiredToSign;	
}

int AForm::GetGradeRequiredToExecute() const
{
	return this->_gradeRequiredToExecute;	
}

bool AForm::BeSigned(Bureaucrat &SigningBureaucrat)
{
	int requiredToSign = this->GetGradeRequiredToSign();
	
	if (SigningBureaucrat.GetGrade() <= requiredToSign)
		this->_isSigned = true;
	else
	{
		std::stringstream ss;
		ss << "required grade to sign is: " << requiredToSign << ", but " << SigningBureaucrat.GetName() << " has only grade " << SigningBureaucrat.GetGrade();
		throw AForm::GradeTooLowException(ss.str());
	}
	return this->GetIsSigned();
}

void AForm::SignAForm(Bureaucrat &SigningBureaucrat)
{
	try
	{
		if (AForm::BeSigned(SigningBureaucrat))
			std::cout << GREEN << SigningBureaucrat.GetName() << " signed " << this->GetName() << std::endl << RESET;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cout << RED << SigningBureaucrat.GetName() << " couldn't sign " << this->GetName() << " because " << e.what() << "." << std::endl <<  RESET;
	}
	catch (const AForm::GradeTooHighException &e)
	{
		std::cout << RED << SigningBureaucrat.GetName() << " couldn't sign " << this->GetName() << " because " << e.what() << "." << std::endl << RESET;
	}
}

AForm::GradeTooLowException::GradeTooLowException() : _message("Grade too low"){}
AForm::GradeTooLowException::GradeTooLowException(const std::string &message) : _message(message){}
AForm::GradeTooLowException::~GradeTooLowException() throw() {}

AForm::GradeTooHighException::GradeTooHighException() : _message("Grade too high"){}
AForm::GradeTooHighException::GradeTooHighException(const std::string &message) : _message(message){}
AForm::GradeTooHighException::~GradeTooHighException() throw() {}

const char* AForm::GradeTooHighException::what() const throw()
{
	return (_message.c_str());
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return (_message.c_str());
}
