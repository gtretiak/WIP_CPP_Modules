#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class	Ice : AMateria {
	public:
		Ice();
		Ice(const Ice &Another);
		Ice		&operator=(const Ice &Another);
		AMateria	*clone() const;
		void		use(ICharacter &target);
		~Ice();
};

#endif
