#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void) {
	Animal a1("BIO");
	Animal a2(a1);
	Animal a3;
	a3 = a1;
	std::cout << "a1 type (defined): " << a1.getType() << std::endl;
	std::cout << "a2 type (copied): " << a2.getType() << std::endl;
	std::cout << "a3 type (reassigned): " << a3.getType() << std::endl;
	std::cout << "--------------------------------" << std::endl;
	Dog d1("Bim");
	Dog d2(d1);
	Dog d3;
	d3 = d1;
	std::cout << "d1 type (defined): " << d1.getType() << std::endl;
	std::cout << "d2 type (copied): " << d2.getType() << std::endl;
	std::cout << "d3 type (reassigned): " << d3.getType() << std::endl;
	std::cout << "--------------------------------" << std::endl;
	const Animal*	m = new Animal();
	std::cout << "This object's type is " << m->getType() << std::endl;
	m->makeSound();
	delete m;
	std::cout << "--------------------------------" << std::endl;
	const Animal*	j = new Dog();
	std::cout << "This object's type is " << j->getType() << std::endl;
	j->makeSound();
	delete j;
	std::cout << "--------------------------------" << std::endl;
	const Animal*	i = new Cat();
	std::cout << "This object's type is " << i->getType() << std::endl;
	i->makeSound(); 
	delete i;
	std::cout << "--------------------------------" << std::endl;
	const WrongAnimal*	wa = new WrongAnimal();
	std::cout << "This object's type is " << wa->getType() << std::endl;
	wa->makeSound();
	delete wa;
	std::cout << "--------------------------------" << std::endl;
	const WrongAnimal*	wc = new WrongCat();
	std::cout << "This object's type is " << wc->getType() << std::endl;
	wc->makeSound();
	std::cout << "--------------------------------" << std::endl;
	delete wc;
	std::cout << "--------------------------------" << std::endl;
	return 0;
}
