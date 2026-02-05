#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void) {
	const int	N = 6;
	const Animal	*arr[N];
	for (int i = 0; i < N; i++)
	{
		if (i % 2)
		{
			arr[i] = new Dog();
			arr[i]->makeSound(); 
		}
		else
		{
			arr[i] = new Cat();
			arr[i]->makeSound(); 
		}
	}
	for (int i = 0; i < N; i++)
		delete arr[i];
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Copy testing - Dog class" << std::endl;
	Dog d1;
	d1.setIdea(0, "Look for bones"); 
	std::cout << "d1 Idea: " << d1.getIdea(0) << std::endl;
	Dog d2(d1);
	std::cout << "d2 Idea (copied): " << d2.getIdea(0) << std::endl;
	d2.setIdea(0, "Chase cats");
	std::cout << "d2 Idea (replaced): " << d2.getIdea(0) << std::endl;
	std::cout << "But d1 Idea: " << d1.getIdea(0) << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Assignment testing - Cat class" << std::endl;
	Cat c1;
	c1.setIdea(0, "Play hunting");
	std::cout << "c1 Idea: " << c1.getIdea(0) << std::endl;
	Cat c2;
	c2.setIdea(0, "Drink milk");
	std::cout << "c2 Idea: " << c2.getIdea(0) << std::endl;
	c2 = c1;
	std::cout << "c2 Idea (reassigned): " << c2.getIdea(0) << std::endl;
	std::cout << "And c1 Idea is still: " << c1.getIdea(0) << std::endl;
	c1.setIdea(0, "Drink milk");
	std::cout << "c1 Idea (reassigned): " << c1.getIdea(0) << std::endl;
	std::cout << "But c2 Idea is still: " << c2.getIdea(0) << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Copy testing - Wrong Cat (shallow copy)" << std::endl;
	WrongCat w1; // leak1
	w1.setIdea(0, "Sleep"); 
	std::cout << "w1 Idea: " << w1.getIdea(0) << std::endl;
	WrongCat w2(w1); // This is not a new object - just a pointer
	std::cout << "w2 Idea (copied): " << w2.getIdea(0) << std::endl;
	w2.setIdea(0, "Chase mouses");
	std::cout << "w2 Idea (replaced): " << w2.getIdea(0) << std::endl;
	std::cout << "w1 Idea replaced too: " << w1.getIdea(0) << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Assignment testing - WrongCat (shallow)" << std::endl;
	WrongCat w3; // leak2
	w3.setIdea(0, "Play hunting");
	std::cout << "w3 Idea: " << w3.getIdea(0) << std::endl;
	WrongCat w4; // leak3
	w4.setIdea(0, "Drink milk");
	std::cout << "w4 Idea: " << w4.getIdea(0) << std::endl;
	w4 = w3;
	std::cout << "w4 Idea (reassigned): " << w4.getIdea(0) << std::endl;
	std::cout << "And w3 Idea is still: " << w3.getIdea(0) << std::endl;
	w3.setIdea(0, "Drink milk");
	std::cout << "w3 Idea (reassigned): " << w3.getIdea(0) << std::endl;
	std::cout << "w4 Idea reassigned too: " << w4.getIdea(0) << std::endl;
	std::cout << "--------------------------------" << std::endl;
	return 0;
}
