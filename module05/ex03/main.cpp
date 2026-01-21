#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		std::cout << "-------------Contruction-------------\n";
		Bureaucrat adam("Adam", 1);
		PresidentialPardonForm test("dupa");
		ShrubberyCreationForm a("kwiatki");
		RobotomyRequestForm b("okok");
		Bureaucrat tomek("Ojciec Mateusz", 50);
		std::cout << "-------------Correct exec-------------\n";
		adam.executeForm(test);
		tomek.executeForm(a);
		adam.executeForm(b);
		std::cout << "\n-------------Dencrement grade-------------\n";
		for (int i = 1; i < 150; i++)
			adam.DecrementGrade();
		std::cout << "\n-------------Incorrect sign-------------\n";
		adam.executeForm(test);
		adam.executeForm(a);
		adam.executeForm(b);
		std::cout << "\n-------------Destruction-------------\n";
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
