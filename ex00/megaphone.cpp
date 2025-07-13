#include <iostream>
using namespace std;

void	print_str(char *str)
{
	while (*str)
	{
		if (*str >= 97 && *str <= 122)
			*str -= 32;
		cout << *str;
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
 	else
	{
		while (++i < argc)
		{
			print_str(argv[i]);
			if (i < argc)
				cout << " ";
		}
	}
       	cout << endl;
}
