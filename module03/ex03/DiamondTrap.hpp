#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string Name;
	public:
		DiamondTrap(std::string name);
		void whoAmI();
		using ScavTrap::attack;
		~DiamondTrap();
};
