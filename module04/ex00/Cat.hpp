#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &cpy);
		Cat &operator=(const Cat &other);
		~Cat();
		void makeSound() const;
};
