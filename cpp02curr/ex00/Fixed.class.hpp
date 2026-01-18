#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class	Fixed {
	private:
		int	value_;
		static const int	bits_;
	public:
		Fixed();
		Fixed(Fixed Another);
		int	getRawBits(void);
		void	setRawBits(int const raw);
		~Fixed();
};

#endif
