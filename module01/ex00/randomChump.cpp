#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie deadman(name);

	deadman.announce();
}
