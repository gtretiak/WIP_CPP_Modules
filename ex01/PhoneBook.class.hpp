#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

class	PhoneBook {
	public:
		addContact(void);
		searchContact(void);
	private:
		std::string[8]	contacts;
		int		counter;
};

# define INITIAL_PROMPT "Enter one of the three commands: ADD, SEARCH, EXIT: "

#endif
