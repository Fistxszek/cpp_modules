#include "FragTrap.hpp"


FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->Name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "Constructor of FragTrap " << this->Name << " called!\n";
}

FragTrap::FragTrap(const FragTrap &cpyObj) : ClapTrap(cpyObj)
{
   std::cout << "Copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
   if (this != &other)
   {
       ClapTrap::operator=(other);
       std::cout << "Copy operator used\n";
   }
   return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->Name << " requests high-fives!\n";
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor of FragTrap " << this->Name << " called!\n";
}
