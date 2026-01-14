#include "Weapon.class.hpp"
#include "HumanA.class.hpp"
#include "HumanB.class.hpp"

int	main(void) {
	{
		Weapon weapon("crude spiked club");
		HumanA bob("Bob", weapon);
		bob.attack();
		weapon.setType("divine titanium sword");
		bob.attack();
	}
	{
		Weapon weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(weapon);
		jim.attack();
		weapon.setType("divine titanium sword");
		jim.attack();
	}
	return (0);
}
