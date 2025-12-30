#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

#include <string>

class	Dog {
	private:
		std::string	type_;
	public:
		Dog();
		std::string	getType(void);
		void		makeSound(void);
		~Dog();
};

#endif
