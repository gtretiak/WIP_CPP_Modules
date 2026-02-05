#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal {
	private:
		Brain	*myBrain_;
	public:
		Cat();
		Cat(const std::string name);
		Cat(const Cat &Another);
		Cat	&operator=(const Cat &Another);
		void		setIdea(int i, const std::string idea);
		std::string	getIdea(int i) const;
		void		makeSound(void) const;
		~Cat();
};

#endif
