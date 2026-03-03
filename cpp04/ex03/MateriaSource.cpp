#include "MateriaSource.hpp"
#include <string>
#include <iostream>

MateriaSource::MateriaSource() : IMateriaSource {
}

MateriaSource::MateriaSource(const MateriaSource &Another) : IMateriaSource(Another) {
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &Another);
	void		learnMateria(AMateria *);
	AMateria	*createMateria(std::string const &type);
	~IMateriaSource();
};

#endif
