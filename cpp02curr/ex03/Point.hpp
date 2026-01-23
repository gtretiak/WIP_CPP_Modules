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
		Fixed	&getX(void);
		Fixed	&getY(void);
		~Point();
};

#endif
