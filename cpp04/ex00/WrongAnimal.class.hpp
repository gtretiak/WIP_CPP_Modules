#ifndef WRONGANIMAL_CLASS_HPP
# define WRONGANIMAL_CLASS_HPP

#include <string>

class	WrongAnimal {
	public:
		WrongAnimal();
		std::string	getType(void);
		void		makeSound(void);
		~WrongAnimal();
};

#endif
