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
		int	addContact(void);
		int	searchContact(void) const;
//		~PhoneBook(void);
	private:
		static const int	CAPACITY = 8;
		Contact	_contacts[CAPACITY];
		int		_pbSize;
		int		_index;
};

#endif
