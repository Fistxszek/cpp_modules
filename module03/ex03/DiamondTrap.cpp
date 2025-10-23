#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), Name(name)
{
	//this->Name = name;
	this->HitPoints = FragTrap::HitPoints;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttackDamage = FragTrap::AttackDamage;
	std::cout << "Constructor of DiamondTrap " << this->Name << " called!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpyObj) : ClapTrap(cpyObj), ScavTrap(cpyObj), FragTrap(cpyObj)
{
	std::cout << "Copy constructor for Diamond Trap used\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{    
		ClapTrap::operator=(other);
		std::cout << "Copy operator used\n";
	}    
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->Name <<  " Clap Trap name is " << ClapTrap::Name << "\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor of DiamondTrap " << this->Name << " called!\n";
}
