#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

#include <string>

class	Zombie {
	private:
		std::string	name_;
		int		num_;
	public:
		Zombie();
		Zombie(std::string name, int num);
		void	setZombie(std::string const name, const int num);
		std::string	getName(void) const;
		int	getNum(void) const;
		void	announce(void) const;
		~Zombie();
};

#endif
