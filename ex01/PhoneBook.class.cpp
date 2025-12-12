#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void):_counter(0){}

static void	processField(std::string field) {
	std::string	var;
	std::cout << "Enter the" << field << ": ";
	std::cin >> var;
	if (std::cin.eof())
		exit(1);
	if (field == FNAME)
		Contact.setFirst(var);
	else if (field == LNAME)
		Contact.setLast(var);
	else if (field == NNAME)
		Contact.setNick(var);
	else if (field == PHONE)
		Contact.setPhone(var);
	else if (field == SECRET)
		Contact.setSecret(var);
	else
		exit(1);
}

void	PhoneBook::addContact(void) {
	Contact	Contact;
	std::cout << "ADDING" << std::endl;
	processField(FNAME);
	processField(LNAME);
	processField(NNAME);
	processField(PHONE);
	processField(SECRET);
	if (_counter < 8)
	{
		Contact[_counter] = Contact;
		_counter++;
	}
	else
		_counter = 0;
	return ;
}

void	PhoneBook::searchContact(void) {
	std::cout << "SEARCHING" << std::endl;
	return ;
}

void	PhoneBook::terminateProgram(void) {
	exit(0);
}

PhoneBook::~PhoneBook(void) {
	std::cout << "Destructor is called." << std::endl;
}
