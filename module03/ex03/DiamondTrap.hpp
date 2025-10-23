#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string Name;
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &cpyObj);
        DiamondTrap &operator=(const DiamondTrap &other);
		void whoAmI();
		using ScavTrap::attack;
		~DiamondTrap();
};
