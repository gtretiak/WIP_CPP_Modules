#include "Point.hpp"
#include "Fixed.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	minX = Fixed::min(a.getX(), Fixed::min(b.getX(), c.getX()));
	Fixed	minY = Fixed::min(a.getY(), Fixed::min(b.getY(), c.getY()));
	Fixed	maxX = Fixed::max(a.getX(), Fixed::max(b.getX(), c.getX()));
	Fixed	maxY = Fixed::max(a.getY(), Fixed::max(b.getY(), c.getY()));
	if (!(minX < point.getX()) || !(maxX > point.getX())
		|| !(minY < point.getY()) || !(maxY > point.getY()))
		return (false);
	return (true);
}
