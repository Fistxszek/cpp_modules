#include "Span.hpp"
#include <exception>
#include <stdexcept>
#include <vector>
#include <list>
#include <iostream>

int main()
{
	Span span(120);

	try
	{
		std::cout << "Trying to check shortesSpan() but Span instance has no elements, should fail.\n";
		std::cout << "shortest: " << span.shortestSpan() << std::endl;
		std::cout << "longest: " << span.longestSpan()<< std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Fail; " << e.what() << std::endl;
	}

	try
	{
		span.addNumber(88);	
		std::cout << "added number 88 with addNumber()\n";

		std::vector<int> vecc(119, 22);
		//std::list<int> vecc(119, 66);
		span.addNumber(vecc);	
		//std::cout << "added range of 119 integers with value 22, with addNumber()\n";
		std::cout << "added range of 119 integers with value 66, with addNumber()\n";

		std::cout << "shortest: " << span.shortestSpan()<< std::endl;
		std::cout << "longest: " << span.longestSpan()<< std::endl;


		std::cout << "Trying to add value 999 with addNumber(), it should fail due to exceeding the max capacity.\n";
		span.addNumber(999);	
		std::cout << "shortest: " << span.shortestSpan()<< std::endl;
		std::cout << "longest: " << span.longestSpan()<< std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Fail; " << e.what() << std::endl;
	}
}
