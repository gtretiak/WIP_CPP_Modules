#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void):_counter(0){} // Is it initialization? Construction!

// Do I need getCount?

static int	processField(std::string field, Contact &contact) {
	std::string	var;
	std::cout << "Enter the " << field << ": ";
	getline(std::cin, var);
	if (std::cin.eof())
	{
		std::cout << "Ctrl+D has pressed (EoF). Exit with code 1." << std::endl;
		exit(1);
	}
	if (var.empty())
	{
		std::cout << "A saved contact can't have empty fields. Try one more time. Enter the " << field << ": ";
		getline(std::cin, var);
		if (std::cin.eof())
		{
			std::cout << "Ctrl+D has pressed (EoF). Exit with code 1." << std::endl;
			exit(1);
		}
	}
	if (var.empty())
		return (1);
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
	return (0);
}

int	PhoneBook::addContact(void) { //member fucntion
	Contact	contact;
	char	c;
	bool	overwritten = false;

	if (processField(FNAME, contact))
		return (1);
	if (processField(LNAME, contact))
		return (1);
	if (processField(NNAME, contact))
		return (1);
	if (processField(PHONE, contact))
		return (1);
	if (processField(SECRET, contact))
		return (1);
	if (_counter < 8)
	{
		this->_contacts[_counter] = contact;
		_counter++;
		// do I need an index here?
	}
	else
	{
		if (!overwritten)
		{
			std::cout << "Attention! Phone book is full. " <<
				"This and upcoming contacts will overwrite existing ones." <<
				" Do you want to proceed? [y/n]: ";
			std::cin >> c;
			if (c == 'n')
				return (0);
		}
		_counter = 0;
		this->_contacts[_counter] = contact;
		_counter++;
	}
	return (0);
}

static std::string	getData(const std::string &data)
{
	if (data.length() > 10)
		return (data.substr(0, 9) + ".");
	else
		return (data);
}

int	PhoneBook::searchContact(void) {
	int	index;
	std::cout << std::setw(10) << "Index" << " | ";
	std::cout << std::setw(10) << "First name" << " | ";
	std::cout << std::setw(10) << "Last name" << " | ";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < _counter; i++)
	{
		std::cout << std::setw(10) << i + 1 << " | ";
		std::cout << std::setw(10) << getData(_contacts[i].getFirst()) << " | ";
		std::cout << std::setw(10) << getData(_contacts[i].getLast()) << " | ";
		std::cout << std::setw(10) << getData(_contacts[i].getNick()) << std::endl;
	}
	std::cout << "Enter the index of the entry to display: ";
	std::cin >> index; //should I handle EoF?
	std::cin.ignore();
	if (index < 1 || index > _counter)
	       return (1);
	std::cout << std::endl << FNAME << ": " << _contacts[index - 1].getFirst() << std::endl;
	std::cout << LNAME << ": " << _contacts[index - 1].getLast() << std::endl;
	std::cout << NNAME << ": " << _contacts[index - 1].getNick() << std::endl;
	std::cout << PHONE << ": " << _contacts[index - 1].getPhone() << std::endl;
	std::cout << SECRET << ": " << _contacts[index - 1].getSecret() << std::endl << std::endl;
	return (0);
}

void	PhoneBook::terminateProgram(void) {
	exit(0);
}

PhoneBook::~PhoneBook(void) {
	std::cout << "Destructor is called." << std::endl;
}
