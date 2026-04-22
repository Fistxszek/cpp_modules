#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || !argv || !argv[1][0])
	{
		std::cerr << "Error: Invalid arguments count!" << std::endl;
		return 1;
	}	
	char *s = argv[1];
	try
	{
		RPN a(s);
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
