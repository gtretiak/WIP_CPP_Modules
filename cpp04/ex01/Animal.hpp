#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class	Animal {
	protected:
		std::string	type_;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &Another);
		Animal &operator=(const Animal &Another);
		std::string	getType(void) const;
		virtual void		makeSound(void) const;
		virtual ~Animal();
};

#endif
