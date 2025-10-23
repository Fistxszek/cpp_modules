#include "FragTrap.hpp"

int main ()
{
	ScavTrap scavTrap("Klapek");
	ClapTrap clapTrap("Ballerina");
	FragTrap fragTrap("Jan Pawel II");

	std::cout <<"\n";
	FragTrap lll(fragTrap);
	FragTrap dokopii("dokopppi");

	dokopii = lll;
	lll.attack("abc");
	dokopii.attack("ddd");
	std::cout <<"\n";
	clapTrap.beRepaired(15);	
	clapTrap.takeDamage(1);
	scavTrap.attack("Sahur");
	scavTrap.beRepaired(15);	
	scavTrap.guardGate();
	scavTrap.takeDamage(30);
	fragTrap.attack("Niewierni");
	fragTrap.takeDamage(44);
	fragTrap.beRepaired(100);
	fragTrap.highFivesGuys();
}
