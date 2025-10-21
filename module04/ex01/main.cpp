#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

int main() {
    const int N = 6;
    Animal* animals[N];

    std::cout << CYAN << "=== Constructing Animals ===" << RESET << std::endl;
    for (int i = 0; i < N; ++i) {
        if (i < N / 2) {
            animals[i] = new(std::nothrow) Dog();
            if (!animals[i]) {
                std::cout << RED << "Failed to allocate Dog at index " << i << RESET << std::endl;
                return 1;
            }
        } else {
            animals[i] = new(std::nothrow) Cat();
            if (!animals[i]) {
                std::cout << RED << "Failed to allocate Cat at index " << i << RESET << std::endl;
                return 1;
            }
        }
    }

    std::cout << CYAN << "\n--- Testing makeSound and getType ---" << RESET << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << GREEN << animals[i]->getType() << ": " << RESET;
        animals[i]->makeSound();
    }

    std::cout << CYAN << "\n--- Testing deep copy for Dog ---" << RESET << std::endl;
    Dog* originalDog = new(std::nothrow) Dog();
    if (!originalDog) {
        std::cout << RED << "Failed to allocate original Dog" << RESET << std::endl;
        return 1;
    }
    originalDog->setBrainIdea(0, "Chase the cat");
    Dog* copiedDog = new(std::nothrow) Dog(*originalDog); // Copy constructor
    if (!copiedDog) {
        std::cout << RED << "Failed to allocate copied Dog" << RESET << std::endl;
        delete originalDog;
        return 1;
    }
    originalDog->setBrainIdea(0, "Eat food");
    std::cout << YELLOW << "Original Dog idea: " << RESET << originalDog->getBrainIdea(0) << std::endl;
    std::cout << YELLOW << "Copied Dog idea:   " << RESET << copiedDog->getBrainIdea(0) << std::endl;
    delete originalDog;
    delete copiedDog;

    std::cout << CYAN << "\n--- Testing deep copy for Cat ---" << RESET << std::endl;
    Cat* originalCat = new(std::nothrow) Cat();
    if (!originalCat) {
        std::cout << RED << "Failed to allocate original Cat" << RESET << std::endl;
        return 1;
    }
    originalCat->setBrainIdea(0, "Sleep on keyboard");
    Cat* copiedCat = new(std::nothrow) Cat(*originalCat); // Copy constructor
    if (!copiedCat) {
        std::cout << RED << "Failed to allocate copied Cat" << RESET << std::endl;
        delete originalCat;
        return 1;
    }
    originalCat->setBrainIdea(0, "Knock over glass");
    std::cout << YELLOW << "Original Cat idea: " << RESET << originalCat->getBrainIdea(0) << std::endl;
    std::cout << YELLOW << "Copied Cat idea:   " << RESET << copiedCat->getBrainIdea(0) << std::endl;
    delete originalCat;
    delete copiedCat;

    std::cout << CYAN << "\n--- Deleting all animals ---" << RESET << std::endl;
    for (int i = 0; i < N; ++i)
        delete animals[i];

    return 0;
}

/*
int main()
{
	const Animal *animals[6];
	
	std::cout << "Creation:\n------------------------\n";
	for (int i = 0; i < 6; ++i)
	{
		animals[i] = (i % 2) ? static_cast<const Animal*>(new Dog()) : static_cast<const Animal*>(new Cat());
		std::cout << "------------------------\n";
	}
	std::cout << "Deleting:\n------------------------\n";
	for (int i = 0; i < 6; ++i)
	{
		delete animals[i];
		std::cout << "------------------------\n";
	}
	return 0;
}
*/
