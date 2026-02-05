#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "AWrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void) {
	const AWrongAnimal *wc = new WrongCat();
	std::cout << "This is a pointer to AWrongAnimal, thus sound: ";
	wc->makeSound();
	std::cout << "(depends on pointer type, since not virtual function)" << std::endl;
	const AAnimal *c1 = new Cat();
	c1->makeSound();
	WrongCat	wc2;
	std::cout << "This is an object on stack, thus: ";
	wc2.makeSound();
	std::cout << "(depends on object type anyway, regardless of virtuality)" << std::endl;
	Dog		d1;
	d1.makeSound();
	delete wc;
	delete c1;
	std::cout << "--------------------------------" << std::endl;
	AWrongAnimal	y; // if has pure virtual, should be commented
	//Uncomment below to see that an abstract class can't be created.
	//AAnimal		x;
	std::cout << "--------------------------------" << std::endl;
	return 0;
}
