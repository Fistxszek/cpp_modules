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
	std::cout << "Destructor called\n";
}

bool CheckPseudoLiterals(std::string input, float *f, double *d)
{
	if (input == "nanf")
		*f = std::numeric_limits<float>::quiet_NaN();
	else if (input == "-inff")
		*f = -std::numeric_limits<float>::infinity();
	else if (input == "+inff" || input == "inff")
		*f = std::numeric_limits<float>::infinity();
	if (*f)
		*d = static_cast<double>(*f);	

	if (input == "nan")
		*d = std::numeric_limits<double>::quiet_NaN();
	else if (input == "-inf")
		*d = -std::numeric_limits<double>::infinity();
	else if (input == "+inf" || input == "inf")
		*d = std::numeric_limits<double>::infinity();
	if (*d)
		*f = static_cast<float>(*d);	
	if (*d || *f)
		return true;
	return false;
}

bool AreEqual(double a, double b)
{
	return std::abs(a - b) < std::numeric_limits<double>::epsilon();
}

bool CheckType(std::string input, char *c, int *i, float *f, double *d)
{
	std::stringstream ss(input);

	if (CheckPseudoLiterals(input, f, d))
		return false;

	int charPos = input.find(".");
	if (charPos == -1)
	{
		//int
		ss >> *i;
		if (ss.fail())
			return false;
		*f = static_cast<float>(*i);
		*d = static_cast<double>(*i);
		if (*i >= 0 && *i <= 127)
			*c = static_cast<char>(*i);
	}
	else 
	{
		int charPos = input.find("f");
		if (charPos == -1)
		{
			//double
			ss >> *d;
			if (ss.fail())
			{
				*d = 0;
				return false;
			}
			if (*d <= static_cast<double>(std::numeric_limits<int>::max()) && *d >= static_cast<double>(std::numeric_limits<int>::min()))
				*i = static_cast<int>(*d);
			if (*d <= static_cast<double>(std::numeric_limits<float>::max()) && *d >= -static_cast<double>(std::numeric_limits<float>::max()))
				*f = static_cast<float>(*d);
		}
		else
		{
			//float
			ss >> *f;
			if (ss.fail())
			{
				*f = 0;
				return false;
			}
			if (*f <= static_cast<float>(std::numeric_limits<int>::max()) && *f >= static_cast<float>(std::numeric_limits<int>::min()))
				*i = static_cast<int>(*f);
			*d = static_cast<double>(*f);
		}
	}
	return true;
}

void ScalarConverter::convert(std::string input)
{
	char c = 0;
	int i = 0;
	float f = 0;
	double d = 0;
	
	if (!CheckType(input, &c, &i, &f, &d))
	{
		std::cout << "char: " << "impossible" << std::endl;	
		std::cout << "int: " << "impossible" << std::endl;	
		if (f)
			std::cout << "float: " << f << "f" << std::endl;	
		else
			std::cout << "float: " << "impossible" << std::endl;	
		if (d)
			std::cout << "double: " << d << std::endl;	
		else
			std::cout << "double: " << "impossible" << std::endl;	
		return;
	}

	if (!c)
		std::cout << "char: " << "impossible" << std::endl;	
	else if (c > 32 && c < 126)
		std::cout << "char: " << c << std::endl;	
	else
		std::cout << "char: " << "Non displayable" << std::endl;	

	if (i || (i == f && i == d))
		std::cout << "int: " << i << std::endl;	
	else 
		std::cout << "int: " << "impossible" << std::endl;	

	double moduloVal = std::fmod(d, 2);
	int	charPos = input.find(".");

	if (charPos == -1 || (moduloVal == 0 && moduloVal == 1))
	{
		if (f || f == d)
			std::cout << "float: "<< f << ".0f" << std::endl;	
		else
			std::cout << "float: " << "impossible" << std::endl;	
		std::cout << "double: "<< d << ".0" << std::endl;	
	}
	else
	{
		if (f || f == d)
			std::cout << "float: "<< f << "f" << std::endl;	
		else
			std::cout << "float: " << "impossible" << std::endl;	
		std::cout << "double: "<< d<< std::endl;	
	}
}
