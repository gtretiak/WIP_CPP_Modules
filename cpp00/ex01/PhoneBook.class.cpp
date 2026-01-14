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

PhoneBook::PhoneBook(void) : pbSize_(0), index_(0) {} // Member initialization during construction

static int	processField(std::string field, Contact &contact) {
	std::string	var;
	std::cout << "\033[32mEnter the " << field << ": \033[0m";
	getline(std::cin, var);
	if (std::cin.eof())
	{
		std::cout << "\033[31m\nCtrl+D has pressed (EoF). Exit with code 1.\033[0m" << std::endl;
		return (-1);
	}
	if (var.empty())
	{
		std::cout << "\033[33mA saved contact can't have empty fields. Try one more time.\033[32m Enter the " << field << ": \033[0m";
		getline(std::cin, var);
		if (std::cin.eof())
		{
			std::cout << "\033[31m\nCtrl+D has pressed (EoF). Exit with code 1.\033[0m" << std::endl;
			return (-1);
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
	int	ret;

	ret = processField(FNAME, contact);
	if (ret != 0)
		return (ret);
	ret = processField(LNAME, contact);
	if (ret != 0)
		return (ret);
	ret = processField(NNAME, contact);
	if (ret != 0)
		return (ret);
	ret = processField(PHONE, contact);
	if (ret != 0)
		return (ret);
	ret = processField(SECRET, contact);
	if (ret != 0)
		return (ret);
	if (index_ < CAPACITY)
	{
		this->contacts_[this->index_] = contact;
		this->index_++;
		if (this->pbSize_ < this->CAPACITY)
			this->pbSize_++;
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
				return (-1);
			}
			std::cin.ignore();
			if (c == 'n')
				return (0);
		}
		this->index_ = 0;
		this->contacts_[this->index_] = contact;
		this->index_++;
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
	if (pbSize_ == 0)
	{
		std::cout << "\033[31mNo entries. Back to the main menu.\033[0m" << std::endl;
		return (0);
	}
	for (int i = 0; i < pbSize_; i++)
	{
		std::cout << std::setw(10) << i + 1 << " | ";
		std::cout << std::setw(10) << getData(this->contacts_[i].getFirst()) << " | ";
		std::cout << std::setw(10) << getData(this->contacts_[i].getLast()) << " | ";
		std::cout << std::setw(10) << getData(this->contacts_[i].getNick()) << std::endl;
	}
	std::cout << "Enter the index of the entry to display: \033[0m";
	std::cin >> index;
	if (std::cin.eof())
	{
		std::cout << "\033[31m\nCtrl+D has pressed (EoF). Exit with code 1.\033[0m" << std::endl;
		return (-1);
	}
	std::cin.ignore();
	if (index < 1 || index > this->pbSize_)
	       return (1);
	std::cout << std::endl << "\033[35m" << FNAME << ": " << this->contacts_[index - 1].getFirst() << std::endl;
	std::cout << LNAME << ": " << this->contacts_[index - 1].getLast() << std::endl;
	std::cout << NNAME << ": " << this->contacts_[index - 1].getNick() << std::endl;
	std::cout << PHONE << ": " << this->contacts_[index - 1].getPhone() << std::endl;
	std::cout << SECRET << ": " << this->contacts_[index - 1].getSecret() << "\033[0m" << std::endl << std::endl;
	return (0);
}
