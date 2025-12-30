#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP

#include <string>

class	WrongCat {
	private:
		std::string	type_;
	public:
		WrongCat();
		std::string	getType(void);
		void		makeSound(void);
		~WrongCat();
};

#endif
