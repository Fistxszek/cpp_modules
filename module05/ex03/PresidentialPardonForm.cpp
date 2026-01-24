#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <sstream>

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("PresidentialPardonForm", false, 25, 5), _target("none")
{
	std::cout << "Empty PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm::AForm("PresidentialPardonForm", false, 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.GetName(), other.GetIsSigned(), other.GetGradeRequiredToSign(), other.GetGradeRequiredToExecute()), _target(other.GetTarget())
{
	std::cout << "Copy PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "Copy PresidentialPardonForm operator called\n";
	if (this == &other)
		return *this;
	_target = other.GetTarget();
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called\n";
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!AForm::execute(executor))
		return false;

	std::cout << "The " << this->GetTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
	return true;
}

const std::string &PresidentialPardonForm::GetTarget() const
{
	return this->_target;
}
