#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class	WrongAnimal {
	protected:
		std::string	type_;
	public:
		WrongAnimal();
		std::string	getType(void) const;
		void		makeSound(void) const;
		~WrongAnimal();
};

#endif
