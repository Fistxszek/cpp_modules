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
		Bureaucrat mateusz("Ojciec Mateusz", 50);
		{
		PresidentialPardonForm presidential("presidential");
		ShrubberyCreationForm kwiatki("kwiatki");
		RobotomyRequestForm roboto("roboto");
		std::cout << "-------------Correct exec-------------\n";
		adam.SignForm(presidential);
		adam.executeForm(presidential);
		adam.SignForm(kwiatki);
		mateusz.executeForm(kwiatki);
		adam.executeForm(roboto);
		}
		std::cout << "\n-------------Dencrement grade-------------\n";
		for (int i = 1; i < 150; i++)
			adam.DecrementGrade();

		PresidentialPardonForm presidential("presidential");
		ShrubberyCreationForm kwiatki("kwiatki");
		RobotomyRequestForm roboto("roboto");
		std::cout << "\n-------------Incorrect sign-------------\n";
		adam.SignForm(presidential);
		adam.executeForm(presidential);
		adam.SignForm(kwiatki);
		mateusz.executeForm(kwiatki);
		adam.executeForm(roboto);
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
