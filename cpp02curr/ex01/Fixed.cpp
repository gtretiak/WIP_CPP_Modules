#include "Fixed.hpp"
#include <cmath> //roundf()

Fixed::Fixed() : value_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : value_(num * (1 << Fixed::bits_)) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : value_(roundf(num * (1 << Fixed::bits_))) { //rounding to store float
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &Ex) : value_(Ex.value_) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &Ex) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->value_ = Ex.value_;
	return (*this);
}

int	Fixed::getRawBits(void) const {
	return (this->value_);
}

void	Fixed::setRawBits(int const raw) {
	this->value_ = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->value_ / (1 << Fixed::bits_)); //casting to float
}

int	Fixed::toInt(void) const {
	return (this->value_ / (1 << Fixed::bits_));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &Num) {
	out << Num.toFloat(); //float by default (handles int too)
	return (out);
}
