#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called\n";
}
Dog::Dog(const Dog &cpy) :Animal(cpy)
{
	this->brain = new Brain(*cpy.brain);
	std::cout << "Dog copy constructor called\n";
}
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy operator used\n";
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}
Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called\n";
}
void Dog::makeSound() const
{
	std::cout << "Woff\n";
}

void Dog::setBrainIdea(int index, std::string idea)
{
	this->brain->setIdea(idea, index);
}

std::string Dog::getBrainIdea(int index)
{
	return this->brain->getIdea(index);
}
