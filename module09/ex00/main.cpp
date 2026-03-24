#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file";
	}
	std::string csv = "data.csv";
	std::string input = argv[1];

	BitcoinExchange btE(csv, input);
}
