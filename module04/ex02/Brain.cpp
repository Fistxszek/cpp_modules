#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
}
Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; ++i)
		this->setIdea(other.getIdea(i), i);
	std::cout << "Brain copy constructor called\n";
}
Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			this->setIdea(other.getIdea(i), i);
	}
	return *this;
}
Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}
std::string Brain::getIdea(int index) const
{
	return this->ideas[index];
}
void Brain::setIdea(std::string idea, int index)
{
	this->ideas[index] = idea;
}
