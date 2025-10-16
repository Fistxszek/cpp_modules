#include "DiamondTrap.hpp"

int main ()
{
	ScavTrap scavTrap("Klapek");
	ClapTrap clapTrap("Ballerina");
	FragTrap fragTrap("Jan Pawel II");
	DiamondTrap diamondTrap("Kilof");

	clapTrap.attack("Dupa!");
	clapTrap.beRepaired(15);	
	clapTrap.takeDamage(1);
	std::cout << "--------------------\n";
	scavTrap.attack("Sahur");
	scavTrap.beRepaired(15);	
	scavTrap.guardGate();
	scavTrap.takeDamage(30);
	std::cout << "--------------------\n";
	fragTrap.attack("Niewierni");
	fragTrap.takeDamage(44);
	fragTrap.beRepaired(100);
	fragTrap.highFivesGuys();
	std::cout << "--------------------\n";
	diamondTrap.attack("Wengiel");
	diamondTrap.whoAmI();
	diamondTrap.beRepaired(99);
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.takeDamage(100);
}
