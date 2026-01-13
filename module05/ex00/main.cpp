#include "Bureaucrat.hpp"

int main()
{

	try
	{
		std::cout << "Constructors:\n";
		Bureaucrat *test = new Bureaucrat("test", 10);
		Bureaucrat abc("abc", 3);

		
		std::cout << "\n<< operators:\n";
		std::cout << "Before incrementing: " << abc;
		std::cout << "Before decrementing: " << *test;

		std::cout << "\nIncrement and decrement:\n";
		abc.IncrementGrade();
		test->DecrementGrade();

		std::cout << "After incrementing: " << abc;
		std::cout << "After decrementing: " << *test;

		delete test;	
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << RED << e.what() << std::endl << RESET;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << RED << e.what() << std::endl << RESET;
	}
}
