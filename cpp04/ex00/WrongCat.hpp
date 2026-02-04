#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <string>
#include "WrongAnimal.hpp"

class	WrongCat {
	private:
		std::string	type_;
	public:
		WrongCat();
		std::string	getType(void) const;
		void		makeSound(void) const;
		~WrongCat();
};

#endif
