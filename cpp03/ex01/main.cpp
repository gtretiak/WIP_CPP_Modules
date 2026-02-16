#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

int	main(void) {
	ClapTrap a("Alpha");
	ScavTrap b("Bravo");
	std::cout << "\n--- Polymorphism ---\n";
	ClapTrap* poly = new ScavTrap("Charlie");
	poly->attack("Alpha");
	std::cout << "\n--- Copy construction on Bravo ---\n";
	ScavTrap c(b);
	ScavTrap d("Delta");
	std::cout << "\n--- Assignment to Delta a copy of Bravo ---\n";
	d = c;
	std::cout << "\n--- Member functions ---\n";
	d.attack("Poly");
	poly->takeDamage(40);
	b.attack("Poly");
	poly->takeDamage(40);
	poly->beRepaired(20);
	d.guardGate();
	std::cout << "\n--- Charlie destruction (both ScavTrap & ClapTrap) ---\n";
	delete poly;
	std::cout << "\n--- Stack destruction (Alpha and Bravo (x3) destruction) ---\n";
	return 0;
}
