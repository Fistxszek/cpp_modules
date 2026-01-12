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
		const int GetGrade() const ;
		void IncrementGrade();
		void DecrementGrade();
};
