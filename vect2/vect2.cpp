#include "vect2.hpp"

vect2::vect2() : x_(0), y_(0) {
}
vect2::vect2(int x, int y) : x_(x), y_(y) {
}
vect2::vect2(const vect2 &Another) : x_(Another.x_), y_(Another.y_) {
}
vect2	&vect2::operator=(const vect2 &Another) {
	if (*this != Another)
	{
		this->x_ = Another.x_;
		this->y_ = Another.y_;
	}
	return (*this);
}

int	vect2::getX() const {
	return (this->x_);
}
int	vect2::getY() const {
	return (this->y_);
}

vect2	vect2::operator+(const vect2 &Another) const {
	vect2	temp;
	temp.x_ = this->x_ + Another.x_;
	temp.y_ = this->y_ + Another.y_;
	return (temp);
}
vect2	vect2::operator+(int z) {
	vect2	temp;
	temp.x_ = this->x_ + z;
	temp.y_ = this->y_ + z;
	return (temp);
}
vect2	&vect2::operator+=(int z) {
	this->x_ += z;
	this->y_ += z;
	return (*this);
}
vect2	&vect2::operator+=(const vect2 &Another) {
	this->x_ += Another.x_;
	this->y_ += Another.y_;
	return (*this);
}
vect2	&vect2::operator++() {
	this->x_ += 1;
	this->y_ += 1;
	return (*this);
}
vect2	vect2::operator++(int dum) {
	(void)dum;
	vect2	temp;
	temp.x_ = this->x_;
	temp.y_ = this->y_;
	this->x_ += 1;
	this->y_ += 1;
	return (temp);
}

vect2	vect2::operator-(const vect2 &Another) const {
	vect2	temp;
	temp.x_ = this->x_ - Another.x_;
	temp.y_ = this->y_ - Another.y_;
	return (temp);
}
vect2	vect2::operator-(int z) {
	vect2	temp;
	temp.x_ = this->x_ - z;
	temp.y_ = this->y_ - z;
	return (temp);
}
vect2	&vect2::operator-=(int z) {
	this->x_ -= z;
	this->y_ -= z;
	return (*this);
}
vect2	&vect2::operator-=(const vect2 &Another) {
	this->x_ -= Another.x_;
	this->y_ -= Another.y_;
	return (*this);
}
vect2	&vect2::operator--() {
	this->x_ -= 1;
	this->y_ -= 1;
	return (*this);
}
vect2	vect2::operator--(int dum) {
	(void)dum;
	vect2	temp;
	temp.x_ = this->x_;
	temp.y_ = this->y_;
	this->x_ -= 1;
	this->y_ -= 1;
	return (temp);
}
vect2	vect2::operator-() const {
	vect2	temp;
	temp.x_ = -(this->x_);
	temp.y_ = -(this->y_);
	return (temp);
}

vect2	vect2::operator*(int z) {
	vect2	temp;
	temp.x_ = this->x_ * z;
	temp.y_ = this->y_ * z;
	return (temp);
}
vect2	vect2::operator*(const vect2 &Another) const {
	vect2	temp;
	temp.x_ = this->x_ * Another.x_;
	temp.y_ = this->y_ * Another.y_;
	return (temp);
}
vect2	&vect2::operator*=(int z) {
	this->x_ *= z;
	this->y_ *= z;
	return (*this);
}
vect2	&vect2::operator*=(const vect2 &Another) {
	this->x_ *= Another.x_;
	this->y_ *= Another.y_;
	return (*this);
}

int	&vect2::operator[](int i) {
	if (i == 0)
		return (this->x_);
	else 
		return (this->y_);
}
const int	&vect2::operator[](int i) const {
	if (i == 0)
		return (this->x_);
	else 
		return (this->y_);
}
vect2::~vect2() {
}

bool	vect2::operator==(const vect2 &Another) const {	
	return (this->x_ == Another.x_ && this->y_ == Another.y_);
}
bool	vect2::operator!=(const vect2 &Another) const {
	return !(this->x_ == Another.x_ && this->y_ == Another.y_);
}

vect2	operator+(int z, const vect2 &v) {
	vect2	temp(v.getX() + z, v.getY() + z);
	return (temp);
}
vect2	operator-(int z, const vect2 &v) {
	vect2	temp(z - v.getX(), z - v.getY());
	return (temp);
}
vect2	operator*(int z, const vect2 &v) {
	vect2	temp(v.getX() * z, v.getY() * z);
	return (temp);
}
std::ostream	&operator<<(std::ostream &os, const vect2 &V) {
	os << "{" << V.getX() << ", " << V.getY() << "}";
	return (os);
}
