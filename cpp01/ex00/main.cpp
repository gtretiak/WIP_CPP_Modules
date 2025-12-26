#include "Zombie.class.hpp"
#include <iostream>

#define RED "\033[31m"
#define GRE "\033[32m"
#define YE "\033[33m"
#define PURP "\033[35m"
#define CYA "\033[36m"
#define RES "\033[0m"

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

int	main(void)
{
	std::string	name;
	std::cout << GRE"Greetings, Lord of Darkness!" RES << std::endl 
		<< GRE"Name your first zombie to revive now and forever (unless killed): " RES;
	getline(std::cin, name);
	if (std::cin.eof())
	{
		std::cout << RED"\nEof (Ctrl+D). Returned with the error code 1." RES << std::endl;
		return (1);
	}
	Zombie	*newborn = newZombie(name);
	std::cout << CYA"The newborn zombie " RES << newborn->getName() << CYA
		" has started walking and it's fighting brave..." YE" Oh noooo!" RES << std::endl;
	delete newborn;
	std::cout << YE"You have almost no mana left for black magic..." RES << std::endl
		<< GRE"But you raise another zombie from the grave, whose name is: " RES;
	getline(std::cin, name);
	if (std::cin.eof())
	{
		std::cout << RED "\nEof (Ctrl+D). Returned with the error code 1." RES << std::endl;
		return (1);
	}
	randomChump(name);
	std::cout << CYA"You shout to your enemies: "
		 RES"\"The war is not over! " <<
		"I'll come back to destroy you all!\" "
		CYA"and run away..." << std::endl;
	return (0);
}
