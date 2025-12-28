#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

#include <string>

class	Weapon;

class	HumanA {
	private:
		Weapon		weapon_;
		std::string	name_;
	public:
		HumanA(std::string name, Weapon weapon);
		std::string	getName(void) const;
		void	setWeapon(Weapon weapon);
		void	attack() const;
		~HumanA();
};

#endif
