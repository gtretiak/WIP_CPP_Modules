#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP
#include <string>

class	ClapTrap {
	private:
		std::string	name_;
		int		health_;
		int		energy_;
		int		damage_;
	public:
		ClapTrap(std::string name);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		~ClapTrap();
};

#endif
