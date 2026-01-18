#include "Harl.class.hpp"
#include <iostream>

Harl::Harl() {
	std::cout << "Harl has entered the room, noticed us and opened his mouth to say something...\n" << std::endl;
}

Harl::Harl(std::string filter) : filter_(filter) {
	std::cout << "Harl has entered the room again, but what's the point to listen to him?\n" << "We applied \"" << this->filter_ << "\" filter to his complaints.\n" << std::endl;
}

void	Harl::debug(void) {
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming foryears, whereas you started working here just last month.\n" << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	typedef void	(Harl::*funcPtr)(void);
       	funcPtr	options[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i;
	static bool	muted = false;
	if (muted)
		return ;
	switch (this->filter_[0]) {
		case 'D':
			i = 0;
			break ;
		case 'I':
			i = 1;
			break ;
		case 'W':
			i = 2;
			break ;
		case 'E':
			i = 3;
			break ;
		default:
		{
			muted = true;
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			return ;
		}
	}
	while (i < 4 && levels[i] != level)
		i++;
	if (i == 4)
		return ;
	(this->*options[i])();
}

Harl::~Harl() {
	std::cout << "\nHarl said everything he wanted - we are released!" << std::endl;
}
