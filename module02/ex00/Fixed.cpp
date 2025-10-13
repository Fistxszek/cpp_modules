#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed& copyObj)
{
	this->value = copyObj.value;
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other)
        return *this;
	std::cout << "Copy assignment operator called\n";
    this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	this->value = raw >> 8;
	std::cout << "setRawBits member function called\n";
}
