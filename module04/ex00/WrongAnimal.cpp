#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Base wrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
	this->type = cpy.type;
	std::cout << "Base wrongAnimal copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "Base wrongAnimal copy operator used\n";
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Base wrongAnimal destructor called\n";
}


void WrongAnimal::makeSound() const 
{
	std::cout << "WrongAnimal wrr\n";
}


std::string WrongAnimal::getType() const 
{
	return this->type;
}
