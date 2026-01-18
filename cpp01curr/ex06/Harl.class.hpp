#ifndef HARL_CLASS_HPP
#define HARL_CLASS_HPP

#include <string>

class	Harl {
	public:
		Harl();
		Harl(std::string);
		void	complain(std::string level);
		~Harl();
	private:
		void	debug(void); 
		void	info(void);
		void	warning(void);
		void	error(void);
		std::string	filter_;
};

#endif
