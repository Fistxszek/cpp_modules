#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	setType(name);
}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}

const std::string &Weapon::getType(void) const
{
	return (type);
}
