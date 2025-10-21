#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called\n";
}
WrongCat::WrongCat(const WrongCat &cpy) : WrongAnimal(cpy)
{
	std::cout << "WrongCat copy constructor called\n";
}
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat copy operator used\n";
	if (this != &other)
		this->type = other.type;
	return (*this);
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}
void WrongCat::makeSound() const
{
	std::cout << "Meowww\n";
}
