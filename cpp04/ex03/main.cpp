#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int	main() {
	IMateriaSource	*src = new MateriaSource();
	std::cout << "-----------learning-------------" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << "-----------creating & equiping------------" << std::endl;
	ICharacter	*me = new Character("me");
	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << "-----------using------------" << std::endl;
	ICharacter	*bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	std::cout << "-----------deleting bob with his materias (0 learned)------------" << std::endl;
	delete bob;
	std::cout << "-----------deleting me with my materias (2 learned)------------" << std::endl;
	delete me;
	std::cout << "-----------deleting source of evil------------" << std::endl;
	delete src;
	return 0;
}
