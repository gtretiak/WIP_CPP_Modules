#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"

class	Character : public ICharacter {
	private:
		std::string const	name_;
		AMateria	inventory_[4];
	public:
		Character(std::string name);
		Character(const Character &Another);
		Character	&operator=(const Character &Another);
		std::string const	&getName() const;
		void	equip(AMateria *m);
		void	unequip(int idx);
		void	use(int idx, ICharacter &target);
		~Character();
};

#endif
