#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <ostream>
#include <string>

class AForm;

static const std::string RED = "\033[0;31m";
static const std::string GREEN = "\033[0;32m";
static const std::string RESET = "\033[0m";

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(std::string Name, int Grade);
		Bureaucrat();
		Bureaucrat(const Bureaucrat &cpyObj);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		const std::string &GetName() const;
		int GetGrade() const ;
		void IncrementGrade();
		void DecrementGrade();

		void SignForm(AForm &FormToSign);

		void executeForm(AForm const & form) const;

		class GradeTooHighException : public std::exception
		{
			private:
				std::string _message;
			public:
				GradeTooHighException();
				GradeTooHighException(const std::string &message);
				virtual ~GradeTooHighException() throw();
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			private:
				std::string _message;
			public:
				GradeTooLowException();
				GradeTooLowException(const std::string &message);
				virtual ~GradeTooLowException() throw();
				const char* what() const throw();
		};

};
std::ostream& operator<<(std::ostream &os, const Bureaucrat &other);

#endif
