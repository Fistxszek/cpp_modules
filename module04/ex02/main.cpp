#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "------------------------------------\n";
	std::cout << "------------------------------------\n";
	const Animal* j = new Dog();
	std::cout << "------------------------------------\n";
	const WrongAnimal* i = new WrongCat();
	std::cout << "------------------------------------\n";
	Dog dog1;	
	std::cout << "------------------------------------\n";
	Dog dog2;
	std::cout << "------------------------------------\n";
	dog2 = dog1;
	std::cout << "------------------------------------\n";
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << dog1.getType() << " " << std::endl;
	std::cout << dog2.getType() << " " << std::endl;
	std::cout << "------------------------------------\n";

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	dog1.makeSound();
	dog2.makeSound();
	std::cout << "------------------------------------\n";
	std::cout << "------------------------------------\n";
	delete j;
	std::cout << "------------------------------------\n";
	delete i;
	std::cout << "------------------------------------\n";
	return 0;
}
