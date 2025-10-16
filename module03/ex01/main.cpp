#include "ScavTrap.hpp"

int main ()
{
	ScavTrap scavTrap("Klapek");
	ClapTrap clapTrap("Ballerina");

	clapTrap.attack("Dupa!");
	clapTrap.beRepaired(15);	
	scavTrap.attack("Sahur");
	scavTrap.beRepaired(15);	
	scavTrap.guardGate();
	scavTrap.takeDamage(30);
}
