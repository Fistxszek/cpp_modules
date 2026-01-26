#include "ScalarConverter.hpp"
#include <cmath>

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	std::string abc = argv[1];
	ScalarConverter::convert(abc);
}
