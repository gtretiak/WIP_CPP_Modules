#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class	ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &Another);
		ScavTrap	&operator=(const ScavTrap &Another);
		void	attack(const std::string &target);
		void	guardGate(void);
		~ScavTrap();
};

#endif
