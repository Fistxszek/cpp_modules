#pragma once

#include "Bureaucrat.hpp"
#include <string>

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeRequiredToSign;
		const int _gradeRequiredToExecute;
	public:
		Form();
		Form(std::string Name, bool IsSigned, int GradeRequiredToSign, int GradeRequiredToExecute);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();
		const std::string &GetName() const;
		bool GetIsSigned() const;
		int GetGradeRequiredToSign() const;
		int GetGradeRequiredToExecute() const;

		bool BeSigned(Bureaucrat &SigningBureaucrat);
		void SignForm(Bureaucrat &SigningBureaucrat);

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

std::ostream& operator<<(std::ostream &os, const Form &other);
