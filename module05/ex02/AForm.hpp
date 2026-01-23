#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <sstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeRequiredToSign;
		const int _gradeRequiredToExecute;
	protected:
		AForm();
		AForm(std::string Name, bool IsSigned, int GradeRequiredToSign, int GradeRequiredToExecute);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
	public:
		virtual ~AForm();
		const std::string &GetName() const;
		bool GetIsSigned() const;
		int GetGradeRequiredToSign() const;
		int GetGradeRequiredToExecute() const;

		bool BeSigned(Bureaucrat &SigningBureaucrat);

		virtual	void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			private:
				std::string _message;
			public:
				GradeTooHighException();
				GradeTooHighException(const std::string &message);
				~GradeTooHighException() throw();
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			private:
				std::string _message;
			public:
				GradeTooLowException();
				GradeTooLowException(const std::string &message);
				~GradeTooLowException() throw();
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const AForm &other);
#endif
