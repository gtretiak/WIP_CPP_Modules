#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

int	main(void) {
	ClapTrap a("Clap-Alpha");
	ScavTrap b("Scav-Bravo");
	FragTrap c("Frag-Charlie");
	std::cout << "\n--- Polymorphism (Scav based) ---\n";
	ClapTrap* poly1 = new ScavTrap("Poly_Scav");
	poly1->attack("Clap-Alpha");
	std::cout << "Destruction both Scav and Clap classes:" << std::endl;
	delete poly1;
	std::cout << "\n--- Polymorphism (Frag based) ---\n";
	ClapTrap* poly2 = new FragTrap("Poly_Frag");
	poly2->attack("Scav-Bravo");
	std::cout << "Destruction both Frag and Clap classes:" << std::endl;
	delete poly2;
	std::cout << "\n--- Copy construction on Bravo ---\n";
	ScavTrap b2(b);
	FragTrap c2(c);
	std::cout << "\n--- Assignment to Delta a copy of Bravo ---\n";
	ScavTrap b3("Scav-Delta");
	b3 = b2;
	FragTrap c3("Frag-Delta");
	c3 = c2;
/*	std::cout << "\n--- Self assignment ---\n";
	b3 = b3;
	c3 = c3;*/ //uncomment and compile without Werror flag
	std::cout << "\n--- Member functions ---\n";
	b3.attack("Frag-Charlie");
	c3.takeDamage(40);
	c3.beRepaired(20);
	b3.guardGate();
	c3.attack("Scav-Bravo");
	b3.takeDamage(60);
	b3.beRepaired(20);
	c3.highFivesGuys();
	std::cout << "\n--- Stack destruction (a, b, b2, b3, c, c2, c3) ---" << std::endl;
	return 0;
}
