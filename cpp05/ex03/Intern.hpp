#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include <string>

class	Intern {
	public:
		Intern();
		Intern(const Intern &An);
		Intern	&operator=(const Intern &An);
		AForm	*makeForm(const std::string &form, const std::string &targ);
		class	FormNotExist : public std::exception {
			public:
				const char *what() const throw();
		};
		static AForm	*shrubbery(const std::string &target);
		static AForm	*presidential(const std::string &target);
		static AForm	*robotomy(const std::string &target);
		~Intern();
};

#endif
