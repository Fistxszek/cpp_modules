#include "Array.hpp"
#include <iostream>
#include <stdexcept>
#include <utility>

int main()
{
	unsigned int test = 12;
	std::cout << "===Construction===\n";
	Array <int>abc(test);
	Array <int>cba;
	for (unsigned int i = 0; i <= abc.Size() - 1; ++i)
	{
		std::cout << i << ": " << abc[i] << "\n";
	}
	std::cout << "===Modifying some elements===\n";
	abc[2] = 2322;
	abc[5] = 2;
	abc[7] = 42;
	abc[12] = -32;
	std::cout << "Large array\n";
	for (unsigned int i = 0; i <= abc.Size() - 1; ++i)
	{
		std::cout << i << ": " << abc[i] << "\n";
	}
	std::cout << "Empty array\n";
	std::cout << "===Getting elements===\n";
	try
	{
		std::cout << "Valid ones:\n";
		std::cout << "Large [2]: " << abc[2] << "\n" << "Large [7]: " << abc[7] << "\n" << "Lagre [12]: " << abc[12] << "\n";
	}
	catch(std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Invalid ones:\n";
		std::cout << "Large [12] (too high index): " << abc[12] << "\n";
	}
	catch(std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Empty [1]: " << cba[1] << "\n";
	}
	catch(std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "===Assingment operator===\n";
	std::cout << "BEFORE:\n";
	std::cout << "Large array\n";
	for (unsigned int i = 0; i <= abc.Size() - 1; ++i)
	{
		std::cout << i << ": " << abc[i] << "\n";
	}
	std::cout << "Empty array\n";
	cba = abc;

	std::cout << "AFTER:\n";
	std::cout << "Large array\n";
	for (unsigned int i = 0; i <= abc.Size() - 1; ++i)
	{
		std::cout << i << ": " << abc[i] << "\n";
	}
	std::cout << "Empty array\n";
	for (unsigned int i = 0; i < cba.Size() - 1; ++i)
	{
		std::cout << i << ": " << cba[i] << "\n";
	}
	return 0;
}
