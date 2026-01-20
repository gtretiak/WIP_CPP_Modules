#ifndef FIXED_HPP
#define FIXED_HPP

class	Fixed {
	private:
		int	value_;
		static const int	bits_;
	public:
		Fixed();
		Fixed(const Fixed &Another);
		&Fixed	operator=(const Fixed &Another) const;
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		~Fixed();
};

#endif
