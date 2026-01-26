#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Empty constructor called\n";
}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "Copy operator called\n";
	if (&other != this)
		return *this;
	return *this;
}
ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Copy destructor called\n";

}


void CheckType(std::string input, char *c, int *i, float *f, double *d)
{
	std::stringstream ss(input);

	int charPos = input.find(".");
	if (charPos == -1)
	{
		ss >> *i;
		*f = static_cast<float>(*i);
		*d = static_cast<double>(*i);
		*c = static_cast<char>(*i);
	}
	else 
	{
		int charPos = input.find("f");
		if (charPos == -1)
		{
			ss >> *d;
			*i = static_cast<int>(*d);
			*f = static_cast<float>(*d);
			*c = static_cast<char>(*d);
		}
		else
		{
			ss >> *f;
			*i = static_cast<int>(*f);
			*d = static_cast<double>(*f);
			*c = static_cast<char>(*f);
		}
	}
}

void ScalarConverter::convert(std::string input)
{
	char c = 0;
	int i = 0;
	float f = 0;
	double d = 0;
	
	CheckType(input, &c, &i, &f, &d);

	int	charPos = input.find(".");

	if (c > 32 && c < 126)
	{
		std::cout << "char: " << c << std::endl;	
	}
	else
	{
		std::cout << "char: " << "impossible" << std::endl;	
	}

	std::cout << "int: " << i << std::endl;	

	double moduloVal = std::fmod(d, 2);
	if (charPos == -1 || (moduloVal == 0 && moduloVal == 1))
	{
		std::cout << "float: "<< f << ".0f" << std::endl;	
		std::cout << "double: "<< d << ".0" << std::endl;	
	}
	else
	{
		std::cout << "float: "<< f << "f" << std::endl;	
		std::cout << "double: "<< d<< std::endl;	
	}
}
