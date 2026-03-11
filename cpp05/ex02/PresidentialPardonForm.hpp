#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class	PresidentialPardonForm : public AForm {
	private:
		std::string	target_;
	protected:
		void	execute2() const;
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &Another);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &Another);
		~PresidentialPardonForm();
};

#endif
