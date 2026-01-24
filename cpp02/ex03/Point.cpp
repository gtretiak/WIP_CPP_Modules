#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x_(0), y_(0) {
	std::cout << "Default \"Point\" constructor called" << std::endl;
}

Point::Point(const float x, const float y) : x_(x), y_(y) {
	std::cout << "Float \"Point\" constructor called" << std::endl;
}

Point::Point(const Point &Another) : x_(Another.x_), y_(Another.y_) {
	std::cout << "\"Point\" copy constructor called" << std::endl;
}

Point	&Point::operator=(const Point &Another) {
	std::cout << "\"Point\" copy assignment operator called\n";
	std::cout << "Warning: const point can't be reassigned! ";
	std::cout << "Returning initial object." << std::endl;
	(void)Another;
	return (*this);
}

Fixed const	&Point::getX(void) const {
	return (this->x_);
}
Fixed const	&Point::getY(void) const {
	return (this->y_);
}

bool	Point::operator==(const Point &Another) const {
	return ((this->x_ == Another.getX())
		&& (this->y_ == Another.getY()));
}

Point::~Point() {
	std::cout << "\"Point\" destructor called" << std::endl;
}
