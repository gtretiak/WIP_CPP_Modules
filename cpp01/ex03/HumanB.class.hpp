#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

#include <string>

class	Weapon;

class	HumanB {
	private:
		Weapon		weapon_;
		std::string	name_;
	public:
		HumanB(std::string name);
		std::string	getName(void) const;
		void	setWeapon(Weapon weapon);
		void	attack() const;
		~HumanB();
};

#endif
