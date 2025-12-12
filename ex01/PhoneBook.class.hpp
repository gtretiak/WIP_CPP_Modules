#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.class.hpp"
#define FNAME "first name"
#define LNAME "last name"
#define NNAME "nickname"
#define PHONE "phone number"
#define SECRET "darkest secret"

class	PhoneBook {
	public:
		PhoneBook(void);
		void	addContact(void);
		void	searchContact(void);
		void	terminateProgram(void);
		~PhoneBook(void);
	private:
		Contact	_contacts[8];
		int		_counter;
};

#endif
