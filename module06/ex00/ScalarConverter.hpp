#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter(void);
	public:
		static void convert(std::string input);
};
