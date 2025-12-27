#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

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
