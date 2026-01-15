#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

#include <string>

class	Weapon;

class	HumanB {
	private:
		std::string	name_;
		Weapon		*weapon_; // by pointer - might not have
	public:
		HumanB(std::string name);
//		std::string	getName(void) const;
		void	setWeapon(Weapon &weapon);
		void	attack() const; // to add enemyRef TODO
		~HumanB();
};

#endif
