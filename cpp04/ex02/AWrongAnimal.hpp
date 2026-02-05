#ifndef AWRONGANIMAL_HPP
#define AWRONGANIMAL_HPP

#include <string>

class	AWrongAnimal {
	protected:
		std::string	type_;
	public:
		AWrongAnimal();
		AWrongAnimal(std::string name);
		AWrongAnimal(const AWrongAnimal &Another);
		AWrongAnimal	&operator=(const AWrongAnimal &Another);
		std::string	getType(void) const;
		void		makeSound(void) const; // not virtual!
		//change the two functions (comment/uncomment):
//		virtual	void	purevirtual(void) const = 0;
		virtual	void	purevirtual(void) const;
		virtual	~AWrongAnimal();
};

#endif
