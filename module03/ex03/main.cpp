#include "DiamondTrap.hpp"

int main ()
{
	DiamondTrap diamondTrap("Kilof");

	std::cout << "--------------------\n";
	diamondTrap.attack("Wengiel");
	diamondTrap.whoAmI();
	diamondTrap.beRepaired(99);
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.takeDamage(100);
	std::cout << "--------------------\n";
}
