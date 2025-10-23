#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->Name = name;
	this->AttackDamage = 0;
	this->EnergyPoints = 10;
	this->EnergyPoints = 10;
	std::cout << "Constructor of " << this->Name << " called!\n";
}

ClapTrap::ClapTrap(const ClapTrap &cpyObj)
{
	this->AttackDamage = cpyObj.AttackDamage;
	this->EnergyPoints = cpyObj.EnergyPoints;
	this->HitPoints = cpyObj.HitPoints;
	this->Name = cpyObj.Name;	
	std::cout << "Copy constructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this == &other)
		return *this;
	std::cout << "Copy operator used\n";
	this->AttackDamage = other.AttackDamage;
	this->EnergyPoints = other.EnergyPoints;
	this->HitPoints = other.HitPoints;
	this->Name = other.Name;	
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPoints <= 0)
	{
		std::cout << "You need at least one Energy point to repair!\n";
		return;
	}
	this->EnergyPoints -= 1;
	std::cout << "ClapTrap "<< this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!\n";
}
void ClapTrap::takeDamage(unsigned int amount)
{
	this->HitPoints -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoints <= 0)
	{
		std::cout << "You need at least one Energy point to repair!\n";
		return;
	}
	this->EnergyPoints -= 1;
	this->HitPoints += amount;
	std::cout << "Reapaired " << this->Name << " current energy points: " << this->EnergyPoints << "\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor of " << this->Name << " called!\n";
}
