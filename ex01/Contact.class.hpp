#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <iomanip>
#include <string>

class	Contact {
	public:
		Contact(void); // do I need a constructor?
		std::string	getFirst(void);
		std::string	getLast(void);
		std::string	getNick(void);
		std::string	getPhone(void);
		std::string	getSecret(void);
		void	setFirst(std::string);
		void	setLast(std::string);
		void	setNick(std::string);
		void	setPhone(std::string);
		void	setSecret(std::string);
		~Contact(void); // do I need a destructor?
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif
