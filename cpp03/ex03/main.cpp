#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <string>
#include <iostream>

int	main(void) {
	ClapTrap	a("Alpha");
	ScavTrap	b("Bravo");
	FragTrap	c("Charlie");
	DiamondTrap	d("Delta");
	std::cout << "\n--- Polymorphism ---\n";
	ClapTrap* poly = new DiamondTrap("Delta2");
	poly->attack("Alpha");
	a.takeDamage(60);
	std::cout << "\n--- Heap destruction ---\n";
	delete poly;
	std::cout << "\n--- Copy construction on Delta ---\n";
	DiamondTrap d2(d);
	std::cout << "\n--- Assignment to Delta3 a copy of Delta ---\n";
	DiamondTrap d3("Delta3");
	d3 = d2;
	/*std::cout << "\n--- Self assignment ---\n";
	d3 = d3;*/
	std::cout << "\n--- Member functions ---\n";
	b.beRepaired(20);
	b.guardGate();
	d3.attack("Bravo");
	b.takeDamage(60);
	c.beRepaired(20);
	c.highFivesGuys();
	d3.attack("Charlie");
	c.takeDamage(60);
	d3.whoAmI();
	std::cout << "\n--- Stack destruction (a, b, c, d, d2, d3) ---\n";
	return 0;
}
