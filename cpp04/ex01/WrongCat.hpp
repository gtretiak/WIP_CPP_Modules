#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include "WrongAnimal.hpp"
#include "Brain.hpp"

class	WrongCat : public WrongAnimal {
	private:
		Brain	*myBrain_;
	public:
		WrongCat();
		WrongCat(const std::string name);
		WrongCat(const WrongCat &Another);
		WrongCat	&operator=(const WrongCat &Another);
		std::string	getIdea(int i) const;
		void		setIdea(int i, const std::string idea);
		void		makeSound(void) const;
		~WrongCat();
};

#endif
