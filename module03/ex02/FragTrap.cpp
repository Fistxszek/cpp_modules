#include "FragTrap.hpp"


FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->Name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "Constructor of FragTrap " << this->Name << " called!\n";
}
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->Name << " requests high-fives!\n";
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor of FragTrap " << this->Name << " called!\n";
}
