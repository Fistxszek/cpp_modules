#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("RobotomyRequestForm", false, 72, 45), _target("none")
{
	std::cout << "Empty RobotomyRequestForm constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm::AForm("RobotomyRequestForm", false, 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.GetName(), other.GetIsSigned(), other.GetGradeRequiredToSign(), other.GetGradeRequiredToExecute()), _target(other.GetTarget())
{
	std::cout << "Copy RobotomyRequestForm constructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "Copy RobotomyRequestForm operator called\n";
	if (this == &other)
		return *this;
	_target = other.GetTarget();
	AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called\n";
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << "DRRRRRRRDRRRRRRRR    BEEP BOPP TRRRRRRR... \n";
	std::srand(time(NULL)); // chaning random seed
	int number = rand();
	number %= 2;
	std::string result = (number == 1) ? "succeeded!" : "failed!";
	std::cout << this->GetTarget() << " robotomy " << result <<std::endl;
}

const std::string &RobotomyRequestForm::GetTarget() const
{
	return this->_target;
}
