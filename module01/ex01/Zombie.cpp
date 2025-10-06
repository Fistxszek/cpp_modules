#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..\n";	
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie(){}

Zombie::~Zombie()
{
	std::cout << "Destroyed: " << name << "\n";
}

void Zombie::	setName (std::string name)
{
	this->name = name;
}
