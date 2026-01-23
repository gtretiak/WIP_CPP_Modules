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
	std::cout << "\"Point\" copy assignment operator called" << std::endl;
	this->x_ = Another.x_;
	this->y_ = Another.y_;
	return (*this);
}

Fixed	&Point::getX(void) {
	return (this->x_);
}
Fixed	&Point::getY(void) {
	return (this->y_);
}

Point::~Point() {
	std::cout << "\"Point\" destructor called" << std::endl;
}

#endif
