#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc > 2 || argc < 2)
	{
		std::cout << "Error: Provide only one argument." << std::endl;
		return 1;
	}
	std::string csv = "data.csv";
	std::string input = argv[1];

	BitcoinExchange btE(csv, input);
}
