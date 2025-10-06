#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie	*deadmanl = new Zombie(name);

	return (deadmanl);
}
