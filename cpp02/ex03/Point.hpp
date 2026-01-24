#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class	Point {
	private:
		Fixed const	x_;
		Fixed const	y_;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &Another);
		Point	&operator=(const Point &Another);
		Fixed const	&getX(void) const;
		Fixed const	&getY(void) const;
		bool	operator==(const Point &Another) const;
		~Point();
};

#endif
