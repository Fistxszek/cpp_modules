#include "Harl.hpp"
#include <algorithm>


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Pass only ONE level argument\n";
		return 1;
	}
	Harl harl;
	std::string level = argv[1];
	to_upper(level);
	harl.complainFiler(level);
	return 0;
}
