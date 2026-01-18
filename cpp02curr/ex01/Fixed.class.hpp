#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class	Fixed {
	public:
		Fixed(const int num);
		Fixed(const float num);
		float	toFloat(void) const;
		int	toInt(void) const;
		~Fixed();
};

#endif
