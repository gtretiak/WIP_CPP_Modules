#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

#include <string>

class	Weapon;

class	HumanA {
	private:
		Weapon		_weapon;
		std::string	_name;
	public:
		HumanA(std::string name, Weapon weapon);
		std::string	getName(void) const;
		void	setWeapon(Weapon weapon);
		void	attack() const;
		~HumanA();
};

#endif
