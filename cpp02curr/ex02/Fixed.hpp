#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class	Fixed {
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &Ex);
		Fixed	&operator=(const Fixed &Ex);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
		static Fixed	&min(Fixed &One, Fixed &Two);
		static Fixed	&max(Fixed &One, Fixed &Two);
		static const Fixed	&min(const Fixed &One, const Fixed &Two);
		static const Fixed	&max(const Fixed &One, const Fixed &Two);
		// Binary Comparison:
		bool	operator<(const Fixed &Another);
		bool	operator>(const Fixed &Another);
		bool	operator<=(const Fixed &Another);
		bool	operator>=(const Fixed &Another);
		bool	operator==(const Fixed &Another);
		bool	operator!=(const Fixed &Another);
		// Binary Arithmetic (returning new object), then using copy assignment internally:
		Fixed	operator+(const Fixed &Another);
		Fixed	operator-(const Fixed &Another);
		Fixed	operator*(const Fixed &Another);
		Fixed	operator/(const Fixed &Another);
		Fixed	operator%(const Fixed &Another);
		// Unary:
		Fixed	operator-(void); // returning new object
		Fixed	&operator++(void); // pre-incrementing: the same object
		Fixed	&operator--(void); // pre-decrementing: the same object
		Fixed	operator++(int dummy); // post-incrementing: new object
		Fixed	operator--(int dummy); // post-decrementing: new object
		~Fixed();
	private:
		int	value_;
		static const int	bits_ = 8; // The more scaling factor:
						   // the more precision and less int range
};

std::ostream	&operator<<(std::ostream &out, const Fixed &Num); //free function

#endif
