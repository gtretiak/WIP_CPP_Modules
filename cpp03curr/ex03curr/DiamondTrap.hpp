#ifndef DIAMOND_TRAP
#define DIAMOND_TRAP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class	DiamondTrap : public ScavTrap, FlagTrap {
	private:
		std::string	name_;
	public:
		void	whoAmI();
};

#endif
