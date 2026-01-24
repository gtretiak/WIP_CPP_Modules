#include "Fixed.hpp"
#include <cmath> //roundf()

Fixed::Fixed() : value_(0) {
//	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int num) : value_(num * (1 << bits_)) {
//	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float num) : value_(roundf(num * (1 << bits_))) { //rounding to store float
//	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &Ex) : value_(Ex.value_) {
//	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &Ex) {
//	std::cout << "Copy assignment operator called" << std::endl;
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
	return (static_cast<float>(this->value_) / (1 << bits_)); //c++ casting to float
}
int	Fixed::toInt(void) const {
	return (this->value_ / (1 << bits_));
}

Fixed	&Fixed::min(Fixed &One, Fixed &Two) {
	if (One.getRawBits() < Two.getRawBits())
		return (One);
	else
		return (Two);
}
Fixed const	&Fixed::min(const Fixed &One, const Fixed &Two) {
	if (One.getRawBits() < Two.getRawBits())
		return (One);
	else
		return (Two);
}
Fixed	&Fixed::max(Fixed &One, Fixed &Two) {
	if (One.getRawBits() > Two.getRawBits())
		return (One);
	else
		return (Two);
}
Fixed const	&Fixed::max(const Fixed &One, const Fixed &Two) {
	if (One.getRawBits() > Two.getRawBits())
		return (One);
	else
		return (Two);
}

bool	Fixed::operator<(const Fixed &Another) const {
	return (this->value_ < Another.getRawBits());
}
bool	Fixed::operator>(const Fixed &Another) const {
	return (this->value_ > Another.getRawBits());
}
bool	Fixed::operator<=(const Fixed &Another) const {
	return (this->value_ <= Another.getRawBits());
}
bool	Fixed::operator>=(const Fixed &Another) const {
	return (this->value_ >= Another.getRawBits());
}
bool	Fixed::operator==(const Fixed &Another) const {
	return (this->value_ == Another.getRawBits());
}
bool	Fixed::operator!=(const Fixed &Another) const {
	return (this->value_ != Another.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &Another) const {
	Fixed	Result;
	int	mathRes = this->value_ + Another.getRawBits();
	Result.setRawBits(mathRes);
	return (Result);
}
Fixed	Fixed::operator-(const Fixed &Another) const {
	Fixed	Result;
	int	mathRes = this->value_ - Another.getRawBits();
	Result.setRawBits(mathRes);
	return (Result);
}
Fixed	Fixed::operator*(const Fixed &Another) const {
	Fixed	Result;
	long long	mathRes = static_cast<long long>(this->value_) * Another.getRawBits();
	Result.setRawBits(mathRes / (1 << bits_));
	return (Result);
}
Fixed	Fixed::operator/(const Fixed &Another) const {
	Fixed	Result;
	if (Another.getRawBits() == 0)
	{
		std::cerr << "Error: Division by zero detected! Exit." << std::endl;
		exit(1);
	}
	int	mathRes = this->value_ * (1 << bits_) / Another.getRawBits();
	Result.setRawBits(mathRes);
	return (Result);
}
Fixed	Fixed::operator%(const Fixed &Another) const {
	Fixed	Result;
	int	mathRes = this->value_ % Another.getRawBits();
	Result.setRawBits(mathRes);
	return (Result);
}

Fixed	Fixed::operator-(void) const {
	Fixed	Result;
	Result.setRawBits(-(this->value_));
	return (Result);
}

Fixed	&Fixed::operator++(void) {
	this->value_++;
	return (*this);
}
Fixed	Fixed::operator++(int dummy) {
	Fixed	Result(*this);
	this->value_++;
	(void)dummy;
	return (Result);
}
Fixed	&Fixed::operator--(void) {
	this->value_--;
	return (*this);
}
Fixed	Fixed::operator--(int dummy) {
	Fixed	Result(*this);
	this->value_--;
	(void)dummy;
	return (Result);
}

Fixed::~Fixed() {
//	std::cout << "Destructor called" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &Num) {
	out << Num.toFloat(); //float by default (handles int too)
	return (out);
}
