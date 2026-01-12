#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *test = new Bureaucrat("test", 150);

	try
	{
		std::cout << test;
		test->DecrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Low: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "High: " << e.what() << std::endl;
	}
	delete test;	
}
