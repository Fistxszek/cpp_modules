#include "Animal.hpp"
Animal::Animal()
{
	std::cout << "Base animal constructor called\n";
}

Animal::Animal(const Animal &cpy)
{
	this->type = cpy.type;
	std::cout << "Base animal copy constructor called\n";
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Base animal copy operator used\n";
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Base animal destructor called\n";
}


void Animal::makeSound() const 
{
	std::cout << "Animal wrr\n";
}


std::string Animal::getType() const 
{
	return this->type;
}
