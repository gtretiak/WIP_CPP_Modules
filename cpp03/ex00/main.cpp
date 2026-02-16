#include "ClapTrap.hpp"
#include <string>
#include <iostream>

int	main(void) {
	std::string	robot[4] = {"Optimus Prime", "R2-D2", "T1000", "Terminator"};
	ClapTrap	Op(robot[0]);
	ClapTrap	R2(robot[1]);
	ClapTrap	T1000orig(robot[2]);
	ClapTrap	Terminator(robot[3]);
	std::cout << "\nRound 1.\n" << std::endl;
	Op.attack(robot[1]); //Op=9E
	R2.takeDamage(4); //R2=6HP
	R2.attack(robot[0]); 
	Op.takeDamage(2); //Op=8HP
	std::cout << "\nRound 2.\n" << std::endl;
	Op.attack(robot[1]); //Op=8E
	R2.takeDamage(4); //R2=2HP
	R2.beRepaired(2); //R2=4HP
	std::cout << "\nRound 3.\n" << std::endl;
	Op.attack(robot[1]); //Op=7E
	R2.takeDamage(4); //R2=0HP
	R2.attack(robot[0]); //can't attack (no health)
	ClapTrap	T1000copy(T1000orig); //Copy constructor
	T1000copy.attack(robot[0]);
	Op.takeDamage(3); //Op=5HP
	std::cout << "\nRound 4.\n" << std::endl;
	Op.attack(robot[2]); //Op=6E
	T1000copy.takeDamage(4); //T1000=6HP
	T1000copy.attack(robot[0]);
	Op.takeDamage(3); //Op=2HP
	std::cout << "\nRound 5.\n" << std::endl;
	Op.beRepaired(4); //Op=6HP, 5E
	T1000copy.attack(robot[0]);
	Op.takeDamage(3); //Op=3HP
	std::cout << "\nRound 6.\n" << std::endl;
	Op.beRepaired(4); //Op=7HP, 4E
	T1000copy.attack(robot[0]);
	Op.takeDamage(3); //Op=4HP
	std::cout << "\nRound 7.\n" << std::endl;
	Op.beRepaired(4); //Op=8HP, 3E
	T1000copy.attack(robot[0]);
	Op.takeDamage(3); //Op=5HP
	std::cout << "\nRound 8.\n" << std::endl;
	Op.beRepaired(4); //Op=9HP, 2E
	T1000copy.attack(robot[0]);
	Op.takeDamage(3); //Op=6HP
	std::cout << "\nRound 9.\n" << std::endl;
	Op.beRepaired(4); //Op=10HP, 1E
	T1000copy.attack(robot[0]);
	Op.takeDamage(3); //Op=7HP
	std::cout << "\nRound 10.\n" << std::endl;
	Op.attack(robot[2]); //Op=0E
	T1000copy.takeDamage(4); //T1000=2HP
	T1000copy.beRepaired(3); //T1000=5HP
	std::cout << "\nRound 11.\n" << std::endl;
	Op.attack(robot[2]); //can't attack (no energy)
	Op = Terminator; //Copy assignment operator
	Op.attack(robot[2]);
	T1000copy.takeDamage(5); //T1000=0HP
	std::cout << "Optimus Prime in the Terminator's shell win!" << std::endl;
	return 0;
}
