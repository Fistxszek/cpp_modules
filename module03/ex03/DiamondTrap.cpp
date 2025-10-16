#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), Name(name)
{
	//this->Name = name;
	this->HitPoints = FragTrap::HitPoints;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttackDamage = FragTrap::AttackDamage;
	std::cout << "Constructor of DiamondTrap " << this->Name << " called!\n";
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->Name <<  " Clap Trap name is " << ClapTrap::Name << "\n";

}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor of DiamondTrap " << this->Name << " called!\n";
}
