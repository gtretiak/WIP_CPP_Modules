#include "Fixed.class.hpp"
#include <iostream>

Fixed::Fixed() {
	std::cout << "Default constructor" << std::endl;
}

Fixed::Fixed(Fixed Another)() {
	std::cout << "A copy constructor" << std::endl;
}

int	Fixed::getRawBits(void) {
	return 0;
}

void	Fixed::setRawBits(int const raw) {
	return ;
}
//int	value_;
//static const int	bits_;
Fixed::~Fixed() {
	std::cout << "Desctructor" << std::endl;
}
