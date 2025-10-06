#include <iostream>
#include <string>

int main ()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "Memory:\n";
	std::cout << "String variable: " << &str << "\n";
	std::cout << "String pointer: " << strPTR << "\n";
	std::cout << "String reference: " << &strREF << "\n";


	std::cout << "Value:\n";
	std::cout << "String variable: " << str << "\n";
	std::cout << "String pointer: " << *strPTR << "\n";
	std::cout << "String reference: " << strREF << "\n";
}
