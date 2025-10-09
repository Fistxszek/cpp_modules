#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "\033[1;31m" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << "\033[0m" << std::endl;
}

void Harl::info( void )
{
	std::cout << "\033[1;31m" << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more! " << "\033[0m" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "\033[1;31m" << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << "\033[0m" << std::endl;
}

void Harl::error( void )
{
	std::cout << "\033[1;31m" << "This is unacceptable! I want to speak to the manager now." << "\033[0m" << std::endl;
}

void Harl::complain( std::string level )
{
	int size = sizeof(Levels) / sizeof(Levels[0]);
	for (int i = 0; i < size; ++i)
	{
		if (Levels[i] == level)
		{
			std::cout << "\033[1;31m" << std::endl <<"Harl: " << "\033[0m" << std::endl;
			(this->*Functions[i])();
			std::cout << std::endl;
			return;
		}
	}
	std::cout << "\033[1;1m" << std::endl <<"Invalid level!\n" << "\033[0m" << std::endl;
}

Harl::Harl()
{
	Functions[0] = &Harl::debug;
	Functions[1] = &Harl::info;
	Functions[2] = &Harl::warning;
	Functions[3] = &Harl::error;

	Levels[0] = "DEBUG";
	Levels[1] = "INFO";
	Levels[2] = "WARNING";
	Levels[3] = "ERROR";
}
