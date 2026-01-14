#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		std::cout << "-------------Contruction-------------\n";
		Form *form = new Form("formularz", false, 50, 50);
		Form tmpForm("temporary form", false, 1, 1);
		Bureaucrat tomek("Ojciec Mateusz", 50);
		std::cout << "\n-------------Streaming form to cout-------------\n";
		std::cout << *form << std::endl;
		std::cout << tmpForm << std::endl;
		std::cout << tomek << std::endl;
		std::cout << "-------------Correct sign-------------\n";
		form->SignForm(tomek);
		std::cout << *form;
		std::cout << "\n-------------Dencrement grade-------------\n";
		tomek.DecrementGrade();
		std::cout << "\n-------------Incorrect sign-------------\n";
		form->SignForm(tomek);
		std::cout << "\n-------------Destruction-------------\n";
		delete form;
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
