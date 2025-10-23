#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->Name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "Constructor of ScavTrap " << this->Name << " called!\n";
}

ScavTrap::ScavTrap(const ScavTrap &cpyObj) : ClapTrap(cpyObj)
{
   std::cout << "Copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
   if (this != &other)
   {
       ClapTrap::operator=(other);
       std::cout << "Copy operator used\n";
   }
   return *this;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap named: " << this->Name << " is now in gate keeper mode!\n";
}
ScavTrap::~ScavTrap()
{
	std::cout << "Destructor of ScavTrap " << this->Name << " called!\n";
}
