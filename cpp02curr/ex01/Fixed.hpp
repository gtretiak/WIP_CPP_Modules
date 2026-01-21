#ifndef FIXED_HPP
#define FIXED_HPP

class	Fixed {
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const &Fixed Ex);
		Fixed	&operator=(const &Fixed Ex);
		//	operator<<();TODO
		float	toFloat(void) const;
		int	toInt(void) const;
		~Fixed();
	private:
		int	value_;
		//float	value_; TODO?
		static const int	bits_ = 8;
};

#endif
