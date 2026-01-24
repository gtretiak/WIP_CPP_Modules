#include "Point.hpp"
#include "Fixed.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	if (point == a || point == b || point == c)
	{
		std::cout << "The point is on a vertex of the triangle." << std::endl;
		return (false);
	}
	Fixed	minX = Fixed::min(a.getX(), Fixed::min(b.getX(), c.getX()));
	Fixed	minY = Fixed::min(a.getY(), Fixed::min(b.getY(), c.getY()));
	Fixed	maxX = Fixed::max(a.getX(), Fixed::max(b.getX(), c.getX()));
	Fixed	maxY = Fixed::max(a.getY(), Fixed::max(b.getY(), c.getY()));
	if ((point.getX() < minX) || (point.getX() > maxX)
		|| (point.getY() < minY) || (point.getY() > maxY))
	{
		std::cout << "The point is way too outside of the triangle." << std::endl;
		return (false);
	}
	Fixed	baEdgeX = b.getX() - a.getX();
	Fixed	baEdgeY = b.getY() - a.getY();
	Fixed	cbEdgeX = c.getX() - b.getX();
	Fixed	cbEdgeY = c.getY() - b.getY();
	Fixed	acEdgeX = a.getX() - c.getX();
	Fixed	acEdgeY = a.getY() - c.getY();
	Fixed	paX = point.getX() - a.getX();
	Fixed	paY = point.getY() - a.getY();
	Fixed	pbX = point.getX() - b.getX();
	Fixed	pbY = point.getY() - b.getY();
	Fixed	pcX = point.getX() - c.getX();
	Fixed	pcY = point.getY() - c.getY();
	Fixed	crossA = baEdgeX * paY - baEdgeY * paX;
	Fixed	crossB = cbEdgeX * pbY - cbEdgeY * pbX;
	Fixed	crossC = acEdgeX * pcY - acEdgeY * pcX;
	if (crossA == 0 || crossB == 0 || crossC == 0)
	{
		std::cout << "The point is on an edge of the triangle." << std::endl;
		return (false);
	}
	else if ((crossA > 0 && crossB > 0 && crossC > 0)
		|| (crossA < 0 && crossB < 0 && crossC < 0))
		return (true);
	std::cout << "The point is outside of the triangle." << std::endl;
	return (false);
}
