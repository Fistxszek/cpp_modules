#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "------------------------------------\n";
	const Animal* meta = new Animal();
	std::cout << "------------------------------------\n";
	const Animal* j = new Dog();
	std::cout << "------------------------------------\n";
	const WrongAnimal* i = new WrongCat();
	std::cout << "------------------------------------\n";
	Dog cat;	
	std::cout << "------------------------------------\n";
	Dog dupa;
	std::cout << "------------------------------------\n";
	dupa = cat;
	std::cout << "------------------------------------\n";
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << cat.getType() << " " << std::endl;
	std::cout << dupa.getType() << " " << std::endl;
	std::cout << "------------------------------------\n";

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	cat.makeSound();
	dupa.makeSound();
	meta->makeSound();
	std::cout << "------------------------------------\n";
	delete meta;
	std::cout << "------------------------------------\n";
	delete j;
	std::cout << "------------------------------------\n";
	delete i;
	std::cout << "------------------------------------\n";
	return 0;
}
