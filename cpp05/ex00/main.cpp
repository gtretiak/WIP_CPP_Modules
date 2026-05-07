#include "Bureaucrat.hpp"
#include <iostream>

int	main(void) {
	try {
		//Bureaucrat	test1("test1", 200);//too low exception
		//Bureaucrat	test2("test2", 0);//too high exception
		Bureaucrat	n;
		std::cout << n << std::endl;

		Bureaucrat	a("Alice", 14);
		std::cout << a << std::endl;
		std::cout << "incrementing grade" << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;

		Bureaucrat	a2(a);
		std::cout << a2 << std::endl;
		
		Bureaucrat	b("Bob", 1);
		std::cout << b << std::endl;
		
		Bureaucrat	c("Charlie", 77);
		std::cout << c << std::endl;
		c = b;
		//c.incrementGrade(); //too high exception
		std::cout << "decrementing grade" << std::endl;
		c.decrementGrade();
		std::cout << c << std::endl;

		Bureaucrat	d("Delta", 33);
		std::cout << d << std::endl;
		d = n;
		//d.decrementGrade(); //too low exception
		std::cout << "incrementing grade" << std::endl;
		d.incrementGrade();
		std::cout << d << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
