#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

#include <string>

class	Cat {
	private:
		std::string	type_;
	public:
		Cat();
		std::string	getType(void);
		void		makeSound(void);
		~Cat();
};

#endif
