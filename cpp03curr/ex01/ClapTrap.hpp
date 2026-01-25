#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>

class	ClapTrap {
	protected:
		std::string	name_;
		int		health_;
		int		energy_;
		int		damage_;
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &Another);
		ClapTrap	&operator=(const ClapTrap &Another);
		virtual void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		virtual ~ClapTrap();
};

#endif
