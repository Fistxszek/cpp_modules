#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &cpyObj);
        FragTrap &operator=(const FragTrap &other);
		void highFivesGuys(void);
		~FragTrap();
};
