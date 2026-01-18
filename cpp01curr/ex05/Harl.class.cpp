#include "Harl.class.hpp"
#include <iostream>

Harl::Harl() {
	std::cout << "Harl entered the room. He noticed us and opened his mouth to say something...\n" << std::endl;
}

void	Harl::debug(void) {
	std::cout << "Debug: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "Info: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "Warning: I think I deserve to have some extra bacon for free. I’ve been coming foryears, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "Error: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	typedef void	(Harl::*funcPtr)(void);
       	funcPtr	options[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"debug", "info", "warning", "error"};
	int	i = 0;
	while (i < 4 && levels[i] != level)
		i++;
	if (i == 4)
	{
		std::cout << "You asked for \"" << level << "\" (level that I don't know)." << std::endl;
		return ;
	}
	(this->*options[i])();
}

Harl::~Harl() {
	std::cout << "\nHarl said everything he wanted - we are released!" << std::endl;
}
