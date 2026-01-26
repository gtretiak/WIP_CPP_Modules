#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap"
#include <string>
#include <iostream>

int	main(void) {
	ClapTrap a1("Alpha1");
	ClapTrap a2("Alpha2");
	ScavTrap b1("Bravo1");
	FragTrap b2("Bravo2");
	std::cout << "\n--- Polymorphism ---\n";
	ClapTrap* poly1 = new ScavTrap("Charlie1");
	poly1->attack("Target");
	delete poly1; // MUST call both destructors
	ClapTrap* poly2 = new FragTrap("Charlie2");
	poly2->attack("Target");
	delete poly2; // MUST call both destructors
	std::cout << "\n--- Copy construction on Bravo ---\n";
	ScavTrap c1(b1);
	FragTrap c2(b2);
	std::cout << "\n--- Assignment to Delta a copy of Bravo ---\n";
	ScavTrap d1("Delta1");
	d1 = c1;
	FragTrap d2("Delta");
	d2 = c2;
	std::cout << "\n--- Self assignment ---\n";
	d1 = d1;
	d2 = d2;
	std::cout << "\n--- Member functions ---\n";
	d1.attack("Enemy");
	d1.takeDamage(30);
	d1.beRepaired(20);
	d1.guardGate();
	d2.attack("Enemy");
	d2.takeDamage(30);
	d2.beRepaired(20);
	d2.highFivesGuys();
	return 0;
}
