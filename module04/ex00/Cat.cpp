#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat constructor called\n";
}
Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	std::cout << "Cat copy constructor called\n";
}
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy operator used\n";
	if (this != &other)
		this->type = other.type;
	return (*this);
}
Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}
void Cat::makeSound() const
{
	std::cout << "Meowww\n";
}
