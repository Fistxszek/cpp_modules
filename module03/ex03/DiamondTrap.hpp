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
		//tests
		std::string getDiamondName() const { return Name; }
		std::string getClapTrapName() const { return ClapTrap::Name; }
};
