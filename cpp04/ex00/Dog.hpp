#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"

class	Dog : public Animal {
	private:
		std::string	type_;
	public:
		Dog();
		Dog(const Dog &Another);
		Dog	&operator=(const Dog &Another);
		std::string	getType(void) const;
		void		makeSound(void) const;
		~Dog();
};

#endif
