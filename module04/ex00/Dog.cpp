#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog constructor called\n";
}
Dog::Dog(const Dog &cpy) :Animal(cpy)
{
	//this->type = cpy.type;
	std::cout << "Dog copy constructor called\n";
}
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy operator used\n";
	if (this != &other)
		this->type = other.type;
	return (*this);
}
Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}
void Dog::makeSound() const
{
	std::cout << "Woff\n";
}
