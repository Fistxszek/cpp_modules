#include "Harl.hpp"

void to_upper(std::string &str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		str[i] = std::toupper(str[i]);
	}	
}

int main()
{
	Harl harl;
	std::string line;
	while (line != "EXIT")
	{
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Type a level: (DEBUG, INFO, WARNING, ERROR or EXIT to close)" << std::endl;
		std::getline(std::cin, line);
		to_upper(line);
		if (line == "EXIT")
			break;
		harl.complain(line);
	}
	return 0;
}
