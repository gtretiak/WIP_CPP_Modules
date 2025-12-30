#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

#include <string>

class	Animal {
	private:
		std::string	type_;
	public:
		Animal();
		std::string	getType(void);
		void		makeSound(void);
		~Animal();
};

#endif
