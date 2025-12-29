#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

#include <string>

class	Weapon {
	private:
		std::string	type_;
	public:
		Weapon(std::string type);
		std::string	&getType(void);
		void	setType(std::string const type);
		~Weapon();
};

#endif
