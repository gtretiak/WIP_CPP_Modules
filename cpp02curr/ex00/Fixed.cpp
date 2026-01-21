#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &Another) : value_(Another.value_) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &Another) {
	this->value_ = Another.value_;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this-> value_); // raw value of fixed-point value
}

void	Fixed::setRawBits(int const raw) {
	this->value_ = raw; // set raw value of fixed-point value
}

Fixed::~Fixed() {
	std::cout << "Desctructor called" << std::endl;
}
