#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	this->setRawBits(value * 256);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	this->setRawBits(roundf(value * 256));
}

Fixed::Fixed(const Fixed& copyObj)
{
	this->value = copyObj.value;
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

float Fixed::toFloat( void ) const
{
	float test = static_cast<float>(this->getRawBits());
	test /= 256;
	return test;
}

int Fixed::toInt( void ) const
{
	return this->getRawBits()/256;
}

std::ostream& operator<<(std::ostream& os ,const Fixed& other)
{
	float test = other.toFloat();
	os << test;
	return os;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other)
        return *this;
	std::cout << "Copy assignment operator called\n";
    this->value = other.getRawBits();
    return *this;
}
