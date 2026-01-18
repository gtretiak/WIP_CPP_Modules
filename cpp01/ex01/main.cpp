#include "Zombie.class.hpp"
#include <iostream>
#include <string>

#define RED "\033[31m"
#define GRE "\033[32m"
#define YE "\033[33m"
#define PURP "\033[35m"
#define CYA "\033[36m"
#define RES "\033[0m"

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	std::string	name;
	int		N;
	char		c;
	std::cout << GRE"Greetings, Lord of Darkness!" RES << std::endl 
		<< GRE"You recovered from the last shameful defeat.\n"
		"Now it's time to summon a batch of zombies!!! Name them in bulk: " RES;
	getline(std::cin, name);
	if (std::cin.eof())
	{
		std::cout << RED"\nEof (Ctrl+D). Returned with the error code 1." RES << std::endl;
		return (1);
	}
	std::cout << GRE"How many of zombies each named " RES << name << GRE" do you want to revive: " RES;
	std::cin >> N;
	if (std::cin.eof())
	{
		std::cout << RED"\nEof (Ctrl+D). Returned with the error code 1." RES << std::endl;
		return (1);
	}
	std::cin.ignore();
	Zombie	*newBatch = zombieHorde(N, name);
	if (!newBatch)
	{
		std::cout << CYA"Well... Probably not this time..." RES << std::endl;
		return (0);
	}
	std::cout << CYA"The batch of zombies each named " RES << newBatch[0].getName() << CYA
		" has started walking..." GRE" Do you want them to roar? [y/n]: " RES;
	std::cin >> c;
	if (std::cin.eof())
	{
		std::cout << RED"\nEof (Ctrl+D). Returned with the error code 1." RES << std::endl;
		return (1);
	}
	std::cin.ignore();
	if (c != 'y')
	{
		std::cout << CYA"Since your warriors didn't hear a firm 'y', they continued walking.\nThey silently infiltrated the enemy camp and killed the guards." GRE" It's dinner time! You win!" << std::endl;
		delete [] newBatch;
		return (0);
	}
	std::cout << CYA"Of course, you do..." RES << std::endl;
	for (int i = 0; i < N; i++)
		newBatch[i].announce();
	std::cout << RED"!!! Warriors of light suddenly appeared (they heard the zombies, idiot) !!!" RES << std::endl;
	delete [] newBatch;
	std::cout << CYA"You failed again and asked yourself: "
		 RES"\"Should I try another time with demons?\n"
		 "Wait, what if I'm not the Lord of Darkness at all?\""
		CYA" and you burst into tears..." RES << std::endl;
	return (0);
}
