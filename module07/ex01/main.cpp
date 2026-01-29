#include <iostream>
#include <utility>
#include "iter.hpp"

template <typename T>
void func(const T &i)
{
	std::cout << "element: " << i << "\n";	
}

class testClass{
	private:
		int _i;
	public:
		testClass(void) : _i(11) {return;};
		int getI()const {return _i;};
};
std::ostream &operator<<(std::ostream &o, testClass const &other)
{
	o << "testClass: " << other.getI();
	return o;
}

int main()
{
	std::string a[] = {"123", "555", "222", "111"};
	const int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	testClass c[3];
	iter(c, 3, func<testClass>);
	iter(a, 4, func<std::string>);
	iter(b, 10, func<int>);

	return 0;
}
