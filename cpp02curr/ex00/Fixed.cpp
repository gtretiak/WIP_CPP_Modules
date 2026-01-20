#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value_(0) {
	std::cout << "Default constructor has initialized a value to " << this->value_ << std::endl;
}

Fixed::Fixed(const Fixed &Another)() {
	this->value_ = *Another::value_;
	this->bits_ = *Another::bits_;
	std::cout << "A copy constructor has been called" << std::endl;
}

&Fixed	Fixed::operator=(const Fixed &Another) const {
	this->value_ = *Another::value_;
	this->bits_ = *Another::bits_;
	return (*this);
}

int	Fixed::getRawBits(void) const {
	return 0; // raw value of fixed-point value
}

void	Fixed::setRawBits(int const raw) {
	; // set raw value of fixed-point value
}

Fixed::~Fixed() {
	std::cout << "Desctructor has been called" << std::endl;
}
