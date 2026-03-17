#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main(void)
{
	std::vector<int> interail(10, 23);
	interail[2] = 99;
	interail[4] = 3;
	interail[6] = 62;
	interail[7] = 991;

	std::list<int> testList;
	testList.push_front(99);
	testList.push_front(3);
	testList.push_front(62);
	testList.push_front(991);

	try 
	{
		std::cout << "Vector: " <<*easyfind(interail, 3).base() << std::endl;
		std::cout << "List: " << *easyfind(testList, 22) << std::endl;
	}
	catch(...)
	{
		std::cout << "Fail;\n";
	}

	try 
	{
		std::cout << "Vector: " << *easyfind(interail, 62).base() << std::endl;
		std::cout << "List: " << *easyfind(testList, 966) << std::endl;
	}
	catch(...)
	{
		std::cout << "Fail;\n";
	}
}
