#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &cpy);
		Dog &operator=(const Dog &other);
		~Dog();
		void makeSound() const;
};
