#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
{
	this->brain = new Brain();
	this->type = "Cat";
	std::cout << "Cat constructor called\n";
}
Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	std::cout << "Cat copy constructor called\n";
	this->brain = new Brain(*cpy.brain);
}
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy operator used\n";
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}
Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called\n";
}
void Cat::makeSound() const
{
	std::cout << "Meowww\n";
}

void Cat::setBrainIdea(int index, std::string idea)
{
	this->brain->setIdea(idea, index);
}

std::string Cat::getBrainIdea(int index)
{
	return this->brain->getIdea(index);
}
