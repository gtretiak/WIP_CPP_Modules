#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

#include <string>

class	Zombie {
	private:
		std::string const	name_;
	public:
		Zombie(std::string name);
		std::string	getName(void) const;
		void	announce(void) const;
		~Zombie();
};

#endif
