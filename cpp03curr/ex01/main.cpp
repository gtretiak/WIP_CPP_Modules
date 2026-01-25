#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

int	main(void) {
	ClapTrap a("Alpha");
	ScavTrap b("Bravo");
	std::cout << "\n--- Polymorphism ---\n";
	ClapTrap* poly = new ScavTrap("Charlie");
	poly->attack("Target");
	delete poly; // MUST call both destructors
	std::cout << "\n--- Copy construction on Bravo ---\n";
	ScavTrap c(b);
	ScavTrap d("Delta");
	std::cout << "\n--- Assignment to Delta a copy of Bravo ---\n";
	d = c;
	std::cout << "\n--- Self assignment ---\n";
	d = d;
	std::cout << "\n--- Member functions ---\n";
	d.attack("Enemy");
	d.takeDamage(30);
	d.beRepaired(20);
	d.guardGate();
	return 0;
}
