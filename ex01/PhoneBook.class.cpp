#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void):_counter(0){} // Is it initialization? Construction!

// Do I need getCount?

static void	processField(std::string field, Contact contact) {
	std::string	var;
	std::cout << "Enter the " << field << ": ";
	std::cin >> var; // or is it better to use getline?
	if (std::cin.eof())
		exit(1); // do I need to throw an error message?
	if (field == FNAME)
		contact.setFirst(var);
	else if (field == LNAME)
		contact.setLast(var);
	else if (field == NNAME)
		contact.setNick(var);
	else if (field == PHONE)
		contact.setPhone(var);
	else if (field == SECRET)
		contact.setSecret(var);
	else
		exit(1);
}

void	PhoneBook::addContact(void) { //member fucntion
	Contact	contact;
	processField(FNAME, contact);
	processField(LNAME, contact);
	processField(NNAME, contact);
	processField(PHONE, contact);
	processField(SECRET, contact);
	// should I check for non-inserted values (like empty)?
	if (_counter < 8)
	{
		this->_contacts[_counter] = contact;
		_counter++;
		// do I need an index here?
	}
	else
		_counter = 0;
	return ;
}

static std::string	getData(const std::string &data)
{
	if (data.length() > 10)
		return (data.substr(0-9) + '.');
	else
		return (data);
}

void	PhoneBook::searchContact(void) {
	std::cout << std::setw(10) << "Index | ";
	std::cout << std::setw(10) << "First name | ";
	std::cout << std::setw(10) << "Last name | ";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < _counter; i++)
	{
		std::cout << std::setw(10) << i + 1 << " | ";
		std::cout << std::setw(10) << getData(_contacts[i].getFirst()) << " | ";
		std::cout << std::setw(10) << getData(_contacts[i].getLast()) << " | ";
		std::cout << std::setw(10) << getData(_contacts[i].getNick()) << std::endl;
	}
	return ;
}

void	PhoneBook::terminateProgram(void) {
	exit(0);
}

PhoneBook::~PhoneBook(void) {
	std::cout << "Destructor is called." << std::endl;
}
