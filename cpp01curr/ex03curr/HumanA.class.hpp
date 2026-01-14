#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

#include <string>

class	Weapon;

class	HumanA {
	private:
		std::string	name_;
		Weapon		&weapon_; // by reference - always has
	public:
		HumanA(std::string name, Weapon &weapon);
	//	std::string	getName(void) const;
		void	attack() const; // to add enemyRef TODO
		~HumanA();
};

#endif
