#include <iostream>
#include <cctype>
using std::cout;
using std::endl;

void	print_str(const char *str)
{
	while (*str)
	{
		if (islower(*str))
			cout << (char)toupper(*str);
		else
			cout << *str;
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
 	else
	{
		for (int i = 1; i < argc; ++i)
		{
			print_str(argv[i]);
			if (i < argc - 1)
				cout << " ";
		}
	}
       	cout << endl;
	return (0);
}
