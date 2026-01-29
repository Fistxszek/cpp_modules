#include <iostream>
#include "whatever.hpp"

int main()
{
	{
	std::cout << "=======Subject=======\n\n";
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	{
	std::cout << "\n=======Int=======\n\n";
	int a = 1;
	int b = 42;
	std::cout << "===Swap===\n";
	std::cout << a << " | " << b << std::endl;
	swap<int>(a, b);
	std::cout << a << " | " << b << std::endl;

	std::cout << "===Min===\n";
	std::cout << a << " | " << b << std::endl;
	std::cout << min<int>(a, b) << std::endl;

	std::cout << "===Max===\n";
	std::cout << a << " | " << b << std::endl;
	std::cout << max<int>(a, b) << std::endl;
	}

	{
	std::cout << "\n";
	std::cout << "=======Float=======\n";
	float a = 231.13f;
	float b = 4.2f;
	std::cout << "===Swap===\n";
	std::cout << a << " | " << b << std::endl;
	swap<float>(a, b);
	std::cout << a << " | " << b << std::endl;

	std::cout << "===Min===\n";
	std::cout << a << " | " << b << std::endl;
	std::cout << min<float>(a, b) << std::endl;

	std::cout << "===Max===\n";
	std::cout << a << " | " << b << std::endl;
	std::cout << max<float>(a, b) << std::endl;
	}

	{
	std::cout << "\n";
	std::cout << "=======Char=======\n";
	char a = '}';
	char b = '5';
	std::cout << "===Swap===\n";
	std::cout << a << " | " << b << std::endl;
	swap<char>(a, b);
	std::cout << a << " | " << b << std::endl;

	std::cout << "===Min===\n";
	std::cout << a << " | " << b << std::endl;
	std::cout << min<char>(a, b) << std::endl;

	std::cout << "===Max===\n";
	std::cout << a << " | " << b << std::endl;
	std::cout << max<char>(a, b) << std::endl;
	}
	return 0;
}
