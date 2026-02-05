#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class	WrongAnimal {
	protected:
		std::string	type_;
	public:
		WrongAnimal();
		WrongAnimal(std::string name);
		WrongAnimal(const WrongAnimal &Another);
		WrongAnimal	&operator=(const WrongAnimal &Another);
		std::string	getType(void) const;
		void		makeSound(void) const;
		virtual	~WrongAnimal();
};

#endif
