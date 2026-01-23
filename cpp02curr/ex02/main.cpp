#include <iostream>
#include "Fixed.hpp"

int	main(void) {
		Fixed	t;
		Fixed const	y(Fixed(5.05f) * Fixed(2));
		std::cout << t << std::endl;
		std::cout << ++t << std::endl;
		std::cout << t << std::endl;
		std::cout << t++ << std::endl;
		std::cout << t << std::endl;
		std::cout << y << std::endl;
		std::cout << Fixed::max(t, y) << std::endl;
//TEST
    		std::cout << "\n\n\nTESTING\n\n\n";
	    // Constructors
	    Fixed a;                    // default
	    Fixed b(10);                // int
	    Fixed c(5.05f);             // float
	    Fixed d(c);                 // copy
	    Fixed e;

	    e = b;                      // copy assignment

	    std::cout << "a (should be 0): " << a << std::endl;
	    std::cout << "b (10): " << b << std::endl;
	    std::cout << "c (roundf(5.05 * 256) / 256): " << c << std::endl;
	    std::cout << "d (same): " << d << std::endl;
	    std::cout << "e (10): " << e << std::endl;

	    // Conversions
	    std::cout << "c toInt() (should be 5): " << c.toInt() << std::endl;
	    std::cout << "c toFloat() (again rounding): " << c.toFloat() << std::endl;

	    // Comparison
	    std::cout << std::boolalpha;
	    std::cout << "b > c (should be true): " << (b > c) << std::endl;
	    std::cout << "b < c (false): " << (b < c) << std::endl;
	    std::cout << "b >= e (true): " << (b >= e) << std::endl;
	    std::cout << "b == e (true): " << (b == e) << std::endl;
	    std::cout << "b != c (true): " << (b != c) << std::endl;

	    // Unary minus
	    std::cout << "-c (rounding and '-' sign) = " << (-c) << std::endl;

	    // Increment / Decrement
	    Fixed x(1);

	    std::cout << "x (initial value - 1): " << x << std::endl;
	    std::cout << "++x (1 + (1/256)): " << ++x << std::endl;
	    std::cout << "x++ (same - post-incrementing): " << x++ << std::endl;
	    std::cout << "x (+0.00390625): " << x << std::endl;

	    std::cout << "--x (-0.00390625): " << --x << std::endl;
	    std::cout << "x-- (same - post-decrementing): " << x-- << std::endl;
	    std::cout << "x (1): " << x << std::endl;

	    // Min / Max
	    Fixed f(2);
	    Fixed g(3);

	    std::cout << "min(f, g) - should be f(2): " << Fixed::min(f, g) << std::endl;
	    std::cout << "max(f, g) - should be g(3): " << Fixed::max(f, g) << std::endl;

	    const Fixed cf(4);
	    const Fixed cg(5);

	    std::cout << "min(const f, const g) - should be f(4): " << Fixed::min(cf, cg) << std::endl;
	    std::cout << "max(const f, const g) - should be g(5): " << Fixed::max(cf, cg) << std::endl;

	// Arithmetic
	    std::cout << "b + c (10*256 + (rounfd)5.05*256) = " << (b + c) << std::endl;
	    std::cout << "b - c (same, but truncation) = " << (b - c) << std::endl;
	    std::cout << "b * c (both * 256, then res / 256 (twice)) = " << (b * c) << std::endl;
	    std::cout << "b % Fixed(3) (should be 1 - the remainder) = " << (b % Fixed(3)) << std::endl;
	    std::cout << "b / c (10*256*256 = 655360; roundf(5.05*256) = 1293, 655360/1293=506/256) = " << (b / c) << std::endl;
	    std::cout << "b / a (error) = " << (b / a) << std::endl;
}
