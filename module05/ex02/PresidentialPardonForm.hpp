#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public virtual AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		const std::string &GetTarget() const;
		void execute(Bureaucrat const & executor) const;
};
#endif
