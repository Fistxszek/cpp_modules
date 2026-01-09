#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	// std::cout << "------------------------------------\n";
	// const Animal* meta = new Animal();
	// std::cout << "------------------------------------\n";
	// const Animal* normalDog = new Dog();
	// std::cout << "------------------------------------\n";
	// const WrongAnimal* wrongCat1 = new WrongCat();
	// std::cout << "------------------------------------\n";
	// Dog dog1;	
	// std::cout << "------------------------------------\n";
	// Dog dog2;
	// std::cout << "------------------------------------\n";
	// dog2 = dog1;
	// std::cout << "------------------------------------\n";
	// std::cout << normalDog->getType() << " " << std::endl;
	// std::cout << wrongCat1->getType() << " " << std::endl;
	// std::cout << dog1.getType() << " " << std::endl;
	// std::cout << dog2.getType() << " " << std::endl;
	// std::cout << "------------------------------------\n";

	// wrongCat1->makeSound(); //will output the cat sound!
	// normalDog->makeSound();
	// dog1.makeSound();
	// dog2.makeSound();
	// meta->makeSound();
	// std::cout << "------------------------------------\n";
	// delete meta;
	// std::cout << "------------------------------------\n";
	// delete normalDog;
	// std::cout << "------------------------------------\n";
	// delete wrongCat1;
	// std::cout << "------------------------------------\n";
	// return 0;

	Dog *doggers = new Dog();
	delete doggers;
	return 0;
}
