#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &cpyObj);
        ScavTrap &operator=(const ScavTrap &other);
		void guardGate();
		~ScavTrap();
};
