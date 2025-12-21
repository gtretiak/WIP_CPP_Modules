#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <string>
#include <iomanip>
//#include <cstdio> - do I need this?
//#include <limits> - do I need this?
//#include <sstream> - do I need this?
//#include <cstdlib> - do I need this?
#include "Contact.class.hpp"

#define FNAME "first name"
#define LNAME "last name"
#define NNAME "nickname"
#define PHONE "phone number"
#define SECRET "darkest secret"

class	PhoneBook {
	public:
		PhoneBook(void); // do I need a constructor?
				 // do I need get_count?
		int	addContact(void);
		void	searchContact(void);
		void	terminateProgram(void);
		~PhoneBook(void); // do I need a destructor?
	private:
		Contact	_contacts[8];
		int		_counter; // do I need an index as well?
};

#endif
