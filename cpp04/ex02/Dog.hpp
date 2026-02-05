#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog : public AAnimal {
	private:
		Brain	*myBrain_;
	public:
		Dog();
		Dog(const std::string name);
		Dog(const Dog &Another);
		Dog	&operator=(const Dog &Another);
		void		setIdea(int i, const std::string idea);
		std::string	getIdea(int i) const;
		void		makeSound(void) const;
		~Dog();
};

#endif
