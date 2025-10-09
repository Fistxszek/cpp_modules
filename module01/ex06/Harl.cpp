#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "\033[1;31m" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << "\033[0m" << std::endl;
}

void Harl::info( void )
{
	std::cout << "\033[1;31m" << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more! " << "\033[0m" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "\033[1;31m" << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month." << "\033[0m" << std::endl;
}

void Harl::error( void )
{
	std::cout << "\033[1;31m" << "This is unacceptable! I want to speak to the manager now." << "\033[0m" << std::endl;
}

Level getLevel(const std::string& level)
{
    if (level == "DEBUG")
		return DEBUG;
    if (level == "INFO")
		return INFO;
    if (level == "WARNING")
		return WARNING;
    if (level == "ERROR")
		return ERROR;
    return UNKNOWN;
}

void Harl::complainFiler( std::string level )
{
	Level lvl = getLevel(level);
	int j = 0;
	switch(lvl)
	{
		case DEBUG:
			j = 0;
			break;
		case INFO:
			j = 1;
			break;
		case WARNING:
			j = 2;
			break;
		case ERROR:
			j = 3;
			break;
		case UNKNOWN:
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			return;
	}
	int size = sizeof(Levels) / sizeof(Levels[0]);
	for(int i = j; i < size; ++i)
	{
		std::string upp = Levels[i];
		to_upper(upp);
		std::cout << "[ " << upp << " ]\n";
		(this->*Functions[i])();
		std::cout << std::endl;
	}
	return;
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

void to_upper(std::string &str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		str[i] = std::toupper(str[i]);
	}	
}
