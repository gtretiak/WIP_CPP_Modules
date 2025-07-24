#include "myPhoneBook.hpp"

int	main(void) {
	string	input;
	short	i = 0;
	Contact	contacts[];
	c = new Contact[8];
	Contact	:: Contact();
	PhoneBook :: PhoneBook{};
	while (1)
	{
		cout << INITIAL_PROMPT;
		cin >> input;
		if (input == "ADD")
		{
			//if (i > 8)
			//	i = 0;
			//contacts[i++] = ft_add_contact;
			cout << "do add" << input.size() << endl;

		}
		else if (input == "SEARCH")
		{
			cout << right << "do search"
			<< setw(10) << "test" << endl;
		}
		else if (input == "EXIT")
		{
			cout << "do exit" << endl;
			delete(PhoneBook);
		}
	}
	return (0);
}
