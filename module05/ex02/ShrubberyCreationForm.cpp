#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm("ShrubberyCreationForm", false, 25, 5), _target("none")
{
	std::cout << "Empty ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm::AForm("ShrubberyCreationForm", false, 25, 5), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.GetName(), other.GetIsSigned(), other.GetGradeRequiredToSign(), other.GetGradeRequiredToExecute()), _target(other.GetTarget())
{
	std::cout << "Copy ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "Copy ShrubberyCreationForm operator called\n";
	if (this == &other)
		return *this;
	_target = other.GetTarget();
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->GetGradeRequiredToExecute() < executor.GetGrade())
	{
		std::stringstream ss;
		ss << "Execution failed due to " << executor.GetName() << "'s insufficient grade (" << executor.GetGrade() << ") while required grade is: " << this->GetGradeRequiredToExecute();
		throw AForm::GradeTooLowException(ss.str());
	}
	std::cout << "ShrubberyCreationForm EXECUTED by: "<< executor.GetName() << " on " + this->GetTarget() + "\n";
}

const std::string &ShrubberyCreationForm::GetTarget() const
{
	return this->_target;
}
