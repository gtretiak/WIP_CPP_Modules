#ifndef DIAMOND_TRAP
#define DIAMOND_TRAP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class	DiamondTrap : public ScavTrap, FragTrap {
	private:
		std::string	name_;
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &Another);
		DiamondTrap	&operator=(const DiamondTrap &Another);
		void	whoAmI();
		void	attack(const std::string &target);
		~DiamondTrap();
};

#endif
