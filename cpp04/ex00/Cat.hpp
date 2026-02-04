#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"

class	Cat : public Animal {
	private:
		std::string	type_;
	public:
		Cat();
		Cat(const Cat &Another);
		Cat	&operator=(const Cat &Another);
		std::string	getType(void) const;
		void		makeSound(void) const;
		~Cat();
};

#endif
