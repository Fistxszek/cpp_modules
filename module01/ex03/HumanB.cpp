#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
}

void HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << "\n";
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
