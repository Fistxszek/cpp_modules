#include "Zombie.hpp"

int main()
{
	Zombie *zombie = newZombie("Adam");	
	zombie->announce();
	delete zombie;

	randomChump("stefan");	

	return 0;
}
