#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const int value)
{
	this->setRawBits(value * 256);
}

Fixed::Fixed(const float value)
{
	this->setRawBits(roundf(value * 256));
}

Fixed::Fixed(const Fixed& copyObj)
{
	this->value = copyObj.value;
}

Fixed::~Fixed()
{
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
    this->value = other.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->value > other.value);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->value < other.value);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->value >= other.value);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->value <= other.value);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->value != other.value);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    long long temp = static_cast<long long>(this->getRawBits()) * other.getRawBits();
    result.setRawBits(static_cast<int>(temp / 256));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    long long temp = static_cast<long long>(this->getRawBits()) * 256;
    result.setRawBits(static_cast<int>(temp / other.getRawBits()));
    return result;
}

Fixed& Fixed::operator++()
{
	this->value++;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return temp;
}
Fixed& Fixed::operator--()
{
	this->value--;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return temp;
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	return (fixed1 < fixed2) ? fixed1 : fixed2;
}
const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	return (fixed1 < fixed2) ? fixed1 : fixed2;
}
Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	return (fixed1 > fixed2) ? fixed1 : fixed2;
}
const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2) 
{
	return (fixed1 > fixed2) ? fixed1 : fixed2;
}
