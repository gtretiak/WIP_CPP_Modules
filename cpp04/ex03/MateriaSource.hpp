#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <string>

class	MateriaSource : public IMateriaSource {
private:
	AMateria	*templates_[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &Another);
	MateriaSource	&operator=(const MateriaSource &Another);
	void		learnMateria(AMateria *);
	AMateria	*createMateria(std::string const &type);
	~MateriaSource();
};

#endif
