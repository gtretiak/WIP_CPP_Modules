#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

#include <string>

class	Weapon;

class	HumanB {
	private:
		Weapon		_weapon;
		std::string	_name;
	public:
		HumanB(std::string name);
		std::string	getName(void) const;
		void	setWeapon(Weapon weapon);
		void	attack() const;
		~HumanB();
};

#endif
