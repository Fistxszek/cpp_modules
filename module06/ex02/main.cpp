#include <cstdlib>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <typeinfo>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *Generate(void)
{
	srand(time(0));
	int r = rand() % 3;
	switch (r)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return NULL;
}

void Identify(Base *p)
{
	std::stringstream ss("");

	if (dynamic_cast<A*>(p))
		ss << "A";
	if (dynamic_cast<B*>(p))
		ss << "B";
	if (dynamic_cast<C*>(p))
		ss << "C";

	std::string str;
	ss >> str;
	std::cout << "Actual type of the *p is : " << str << std::endl;
}

void Identify(Base &p)
{
	std::stringstream ss("");
	std::string str;
	
	try
	{
		dynamic_cast<A&>(p);
		ss << "A";
	}
	catch (const std::bad_cast &e){  }

	try
	{
		dynamic_cast<B&>(p);
		ss << "B";
	}
	catch (const std::bad_cast &e){  }

	try
	{
		dynamic_cast<C&>(p);
		ss << "C";
	}
	catch (const std::bad_cast &e){  }

	ss >> str;
	std::cout << "Actual type of the &p is : " << str << std::endl;
}

int main()
{
	Base* b;
	std::cout << "====Type====\n";
	b = Generate();
	Identify(*b);
	Identify(b);

	delete b;
}
