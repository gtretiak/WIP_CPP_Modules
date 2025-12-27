#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#define FNAME "first name"
#define LNAME "last name"
#define NNAME "nickname"
#define PHONE "phone number"
#define SECRET "darkest secret"

PhoneBook::PhoneBook(void):_pbSize(0), _index(0) {} // Member initialization during construction
/*
PhoneBook::PhoneBook(void):_pbSize(0), _index(0) {
	std::cout << "\033[36mPB constructor is called.\033[0m" << std::endl;
} // Member initialization during construction*/

static int	processField(std::string field, Contact &contact) {
	std::string	var;
	std::cout << "\033[32mEnter the " << field << ": \033[0m";
	getline(std::cin, var);
	if (std::cin.eof())
	{
		std::cout << "\033[31m\nCtrl+D has pressed (EoF). Exit with code 1.\033[0m" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	if (var.empty())
	{
		std::cout << "\033[33mA saved contact can't have empty fields. Try one more time.\033[32m Enter the " << field << ": \033[0m";
		getline(std::cin, var);
		if (std::cin.eof())
		{
			std::cout << "\033[31m\nCtrl+D has pressed (EoF). Exit with code 1.\033[0m" << std::endl;
			std::exit(EXIT_FAILURE);
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
	if (_index < CAPACITY)
	{
		this->_contacts[_index] = contact;
		_index++;
		if (_pbSize < CAPACITY)
			_pbSize++;
	}
	else
	{
		if (!overwritten)
		{
			std::cout << "\033[33mAttention! Phone book is full. " <<
				"This and upcoming contacts will overwrite existing ones." <<
				" Do you want to proceed? [y/n]: \033[0m";
			std::cin >> c;
			if (std::cin.eof())
			{
				std::cout << "\033[31m\nCtrl+D has pressed (EoF). Exit with code 1.\033[0m" << std::endl;
				std::exit(EXIT_FAILURE);
			}
			std::cin.ignore();
			if (c == 'n')
				return (0);
		}
		_index = 0;
		this->_contacts[_index] = contact;
		_index++;
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

int	PhoneBook::searchContact(void) const {
	int	index;
	std::cout << "\033[32m" << std::setw(10) << "Index" << " | ";
	std::cout << std::setw(10) << "First name" << " | ";
	std::cout << std::setw(10) << "Last name" << " | ";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	if (_pbSize == 0)
	{
		std::cout << "\033[31mNo entries. Back to the main menu.\033[0m" << std::endl;
		return (0);
	}
	for (int i = 0; i < _pbSize; i++)
	{
		std::cout << std::setw(10) << i + 1 << " | ";
		std::cout << std::setw(10) << getData(_contacts[i].getFirst()) << " | ";
		std::cout << std::setw(10) << getData(_contacts[i].getLast()) << " | ";
		std::cout << std::setw(10) << getData(_contacts[i].getNick()) << std::endl;
	}
	std::cout << "Enter the index of the entry to display: \033[0m";
	std::cin >> index;
	if (std::cin.eof())
	{
		std::cout << "\033[31m\nCtrl+D has pressed (EoF). Exit with code 1.\033[0m" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	std::cin.ignore();
	if (index < 1 || index > _pbSize)
	       return (1);
	std::cout << std::endl << "\033[35m" << FNAME << ": " << _contacts[index - 1].getFirst() << std::endl;
	std::cout << LNAME << ": " << _contacts[index - 1].getLast() << std::endl;
	std::cout << NNAME << ": " << _contacts[index - 1].getNick() << std::endl;
	std::cout << PHONE << ": " << _contacts[index - 1].getPhone() << std::endl;
	std::cout << SECRET << ": " << _contacts[index - 1].getSecret() << "\033[0m" << std::endl << std::endl;
	return (0);
}
/*
PhoneBook::~PhoneBook(void) {
	std::cout << "\033[36mPB destructor is called.\033[0m" << std::endl;
}*/
