#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <iomanip>
#include <string>

class	Contact {
	public:
		Contact(void);
		std::string	getFirst(void) const;
		std::string	getLast(void) const;
		std::string	getNick(void) const;
		std::string	getPhone(void) const;
		std::string	getSecret(void) const;
		void	setFirst(const std::string &var);
		void	setLast(const std::string &var);
		void	setNick(const std::string &var);
		void	setPhone(const std::string &var);
		void	setSecret(const std::string &var);
		~Contact(void);
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif
