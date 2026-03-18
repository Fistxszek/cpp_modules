#include "MutantStack.hpp"
#include <iostream>
#include <list>

// int main()
// {
// }

#include <list>
int main()
{
	{
	std::cout << "Subject test\n";
	MutantStack<int> mstack;
	mstack.push(5); mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	}

	{
	std::cout << "\nSubject test changed to list\n";
	std::list<int> mstack2;
	mstack2.push_back(5);
	mstack2.push_back(17);
	std::cout << mstack2.back() << std::endl;
	mstack2.pop_back();
	std::cout << mstack2.size() << std::endl;
	mstack2.push_back(3);
	mstack2.push_back(5);
	mstack2.push_back(737);
	//[...]
	mstack2.push_back(0);
	std::list<int>::iterator it = mstack2.begin();
	std::list<int>::iterator ite = mstack2.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	}

	{
	std::cout << "\nMy test\n";

	std::cout << "\nMutant:\n";
	MutantStack<int> mstack;
	
	mstack.push(1123);
	mstack.push(23);
	mstack.push(2);

	for(MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << std::endl;
	}


	std::cout << "\nList:\n";
	std::list<int> lst;
	
	lst.push_back(1123);
	lst.push_back(23);
	lst.push_back(2);

	for(std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	
	std::cout << "\nCopy stuff (gdb to show and explain)\n";
	std::stack<int> test1;
	test1.push(42);
	test1.push(111);
	test1.push(989);

	MutantStack<int> mutantTest1(mstack);
	MutantStack<int> mutantTest2(test1);
	std::stack<int> test2(mstack);

	MutantStack<int> mutantTest3;
	std::stack<int> test3;
	mutantTest3 = mstack;
	mutantTest3 = test1;
	test3 = mstack;
	}
	return 0;
}