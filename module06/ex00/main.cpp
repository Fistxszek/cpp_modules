#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Provide one argument to convert.\n";
		return 1;
	}
	std::string abc = argv[1];
	ScalarConverter::convert(abc);
}
