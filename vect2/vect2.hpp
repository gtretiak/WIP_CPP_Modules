#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class	vect2 {
	private:
		int	x_;
		int	y_;
	public:
		vect2();
		vect2(int x, int y);
		vect2(const vect2 &Another);
		vect2	&operator=(const vect2 &Another);
		int	getX() const;
		int	getY() const;
		vect2	operator+(const vect2 &Another) const;
		vect2	operator-(const vect2 &Another) const;
		vect2	operator*(const vect2 &Another) const;
		vect2	operator+(int z);
		vect2	operator-(int z);
		vect2	operator*(int z);
		vect2	&operator+=(int z);
		vect2	&operator-=(int z);
		vect2	&operator*=(int z);
		vect2	&operator+=(const vect2 &Another);
		vect2	&operator-=(const vect2 &Another);
		vect2	&operator*=(const vect2 &Another);
		vect2	&operator++();
		vect2	&operator--();
		vect2	operator++(int dum);
		vect2	operator--(int dum);
		vect2	operator-() const;
		int	&operator[](int i);
		const int	&operator[](int i) const;
		bool	operator==(const vect2 &Another) const;
		bool	operator!=(const vect2 &Another) const;
		~vect2();
};

vect2	operator+(int z, const vect2 &v);
vect2	operator-(int z, const vect2 &v);
vect2	operator*(int z, const vect2 &v);
std::ostream	&operator<<(std::ostream &os, const vect2 &V);

//all the '+' and '*' operations might be unsafe due to overflow - long? long long?

#endif
