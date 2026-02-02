#include "Array.hpp"
#include <iostream>
#include <stdexcept>
#include <utility>

class SomeClass
{
	public:
		SomeClass( void ) : _n( 0 ) { return; }
		int get( void ) const { return this->_n; }
		void set( int i ) {this->_n = i; }
	private:
		int _n;
};
std::ostream & operator<<( std::ostream & o, SomeClass const & rhs ) { o << rhs.get(); return o; }

int main()
{
	unsigned int len = 12;
	std::cout << "===Construction===\n";
	Array <SomeClass>LargeArray(len);
	Array <SomeClass>EmptyArray;
	for (unsigned int i = 0; i <= LargeArray.Size() - 1; ++i)
	{
		std::cout << i << ": " << LargeArray[i] << "\n";
	}
	std::cout << "===Modifying some elements===\n";
	LargeArray[2].set(2322);
	LargeArray[5].set(2);
	LargeArray[7].set(23);
	LargeArray[11].set(999);
	std::cout << "Large array\n";
	for (unsigned int i = 0; i <= LargeArray.Size() - 1; ++i)
	{
		std::cout << i << ": " << LargeArray[i] << "\n";
	}
	std::cout << "Empty array\n";
	std::cout << "===Getting elements===\n";
	try
	{
		std::cout << "Valid ones:\n";
		std::cout << "Large [2]: " << LargeArray[2] << "\n" << "Large [7]: " << LargeArray[7] << "\n" << "Lagre [11]: " << LargeArray[11] << "\n";
	}
	catch(std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Invalid ones:\n";
		std::cout << "Large [12] (too high index): " << LargeArray[12] << "\n";
	}
	catch(std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Empty [1]: " << EmptyArray[1] << "\n";
	}
	catch(std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "===Assingment operator===\n";
	std::cout << "BEFORE:\n";
	std::cout << "Large array\n";
	for (unsigned int i = 0; i <= LargeArray.Size() - 1; ++i)
	{
		std::cout << i << ": " << LargeArray[i] << "\n";
	}
	std::cout << "Empty array\n";
	EmptyArray = LargeArray;

	std::cout << "AFTER:\n";
	std::cout << "Large array\n";
	for (unsigned int i = 0; i <= LargeArray.Size() - 1; ++i)
	{
		std::cout << i << ": " << LargeArray[i] << "\n";
	}
	std::cout << "Empty array\n";
	for (unsigned int i = 0; i <= EmptyArray.Size() - 1; ++i)
	{
		std::cout << i << ": " << EmptyArray[i] << "\n";
	}
	Array <SomeClass>CopyArray(LargeArray);
	std::cout << "Copy constructor array\n";
	for (unsigned int i = 0; i <= CopyArray.Size() - 1; ++i)
	{
		std::cout << i << ": " << EmptyArray[i] << "\n";
	}
	return 0;
}
