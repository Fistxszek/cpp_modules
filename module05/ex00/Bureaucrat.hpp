#include <exception>
#include <stdexcept>
#include <iostream>

class Bureaucrat
{
	private:
		std::string Name;
		int Grade;
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

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();

		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();

		};

};
std::ostream& operator<<(std::ostream &os, const Bureaucrat &other);
