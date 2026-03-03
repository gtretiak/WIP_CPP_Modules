#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <string>

class	MateriaSource : IMateriaSource {
private:
	AMateria	*templates[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &Another);
	MateriaSource	&operator=(const MateriaSource &Another);
	void		learnMateria(AMateria *);
	AMateria	*createMateria(std::string const &type);
	~IMateriaSource();
};

#endif
