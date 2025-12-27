#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

#include <string>

class	Weapon {
	private:
		std::string	_type;
	public:
		Weapon(std::string type);
		std::string const	&getType(void);
		void	setType(std::string const type);
		~Weapon();
};

#endif
