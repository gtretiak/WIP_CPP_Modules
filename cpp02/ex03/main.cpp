#include <iostream>
#include <limits>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const p);

static int	safeFloatInput(float &var) {
	if (std::cin >> var)
		return (0);
	else if (std::cin.eof())
	{
		std::cerr << "EOF (Ctrl+D). Returned. Error code 1." << std::endl;
		return (1);
	}
	else
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input! Setting coordinate to 0" << std::endl;
		var = 0.0f;
	}
	return (0);
}

static int	reading(float (*triangle)[2], float *point) {
	char	c;
	std::cout << "Let's see whether a point inside a triangle or not." << std::endl;
	std::cout << "Enter floating-point coordinates (x, y) for each of 3 vertices (a, b, c).\n";
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 2; j++)
		{
			if (i == 0) c = 'a';
			else if (i == 1) c = 'b';
			else c = 'c';
			std::cout << c << ".";
			if (j == 0) c = 'x';
			else c = 'y';
			std::cout << c << " (float) = ";
			if (safeFloatInput(triangle[i][j]))
				return (1);
		}
	}
	std::cout << "Great! Now enter the point to check.\nPoint.x (float): ";
	if (safeFloatInput(point[0]))
			return (1);
	std::cout << "Point.y (float): ";
	if (safeFloatInput(point[1]))
			return (1);
	return (0);
}

int	main(void) {
	float	triangle[3][2];
	float	point[2];
	if (reading(triangle, point))
		return (1);
	Point	a(triangle[0][0], triangle[0][1]);
	Point	b(triangle[1][0], triangle[1][1]);
	Point	c(triangle[2][0], triangle[2][1]);
	Point	p(point[0], point[1]);
	if (bsp(a, b, c, p))
		std::cout << "The point is inside the triangle." << std::endl;
	else
		std::cout << "Try next time!" << std::endl;
	return (0);
}
