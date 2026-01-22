#include "Fixed.hpp"
#include <cmath> //roundf()

Fixed::Fixed() : value_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : value_(num * (1 << bits_)) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : value_(roundf(num * (1 << bits_))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const &Fixed Ex) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&operator=(const &Fixed Ex) {
	std::cout << "Copy assignment operator called" << std::endl;
}

std::ostream	&Fixed::operator<<(std::ostream &out, const Fixed &Num) {
	out << "Value is: " << Num.value_ / (1 << bits_) << std::endl; // TODO
	return (out);
}

int	Fixed::getRawBits(void) const {
	return (this->value_);
}

void	Fixed::setRawBits(int const raw) {
	this->value_ = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->value_); //TODO
}

int	Fixed::toInt(void) const {
	return ((int)this->value_); //TODO
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

#endif
