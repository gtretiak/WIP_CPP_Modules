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
		~Fixed();
	private:
		int	value_;
		static const int	bits_ = 8; // The more scaling factor:
						   // the more precision and less int range
};

std::ostream	&operator<<(std::ostream &out, const Fixed &Num); //free function

#endif
