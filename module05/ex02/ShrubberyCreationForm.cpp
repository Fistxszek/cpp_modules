#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm("ShrubberyCreationForm", false, 145, 137), _target("none")
{
	std::cout << "Empty ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm::AForm("ShrubberyCreationForm", false, 145, 137), _target(target)
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

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!AForm::execute(executor))
		return false;

	std::string fileName = this->GetTarget() + "_shrubbery";
	std::ofstream shrubberyFile(fileName.c_str());

	shrubberyFile << "     *            *     " << std::endl;
	shrubberyFile << "    ***          ***    " << std::endl;
	shrubberyFile << "   *****        *****   " << std::endl;
	shrubberyFile << "  *******      *******  " << std::endl;
	shrubberyFile << " *********    ********* " << std::endl;
	shrubberyFile << "***********  ***********" << std::endl;
	shrubberyFile.close();
	std::cout << "Created a file named " << fileName << " in working directiory.\n";
	return true;
}

const std::string &ShrubberyCreationForm::GetTarget() const
{
	return this->_target;
}
