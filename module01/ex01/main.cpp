#include "Zombie.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Provide N count\n";
		return 0;
	}
	int N = std::atoi(argv[1]);
	Zombie *horde = zombieHorde(N, "Stefan");

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
