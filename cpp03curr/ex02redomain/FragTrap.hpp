#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class	FragTrap : public ClapTrap {
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &Another);
		FragTrap	&operator=(const FragTrap &Another);
		void	attack(const std::string &target);
		void	highFivesGuys(void);
		~FragTrap();
};

#endif
