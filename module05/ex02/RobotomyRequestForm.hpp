#ifndef ROBOTO_HPP
#define ROBOTO_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public virtual AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		const std::string &GetTarget() const;
		void execute(Bureaucrat const & executor) const;
};
#endif
