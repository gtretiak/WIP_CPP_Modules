#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class	AAnimal {
	protected:
		std::string	type_;
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &Another);
		AAnimal &operator=(const AAnimal &Another);
		std::string	getType(void) const;
		virtual void		makeSound(void) const = 0;
		virtual ~AAnimal();
};

#endif
