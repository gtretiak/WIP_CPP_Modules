#include <iostream>
#include <cctype>

void	print_str(const char *str)
{
	while (*str)
	{
		if (islower(*str))
			std::cout << "\033[32m" << (char)toupper(*str);
		else
			std::cout << "\033[32m" << *str;
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "\033[31m* LOUD AND UNBEARABLE FEEDBACK NOISE *\033[0m";
 	else
	{
		for (int i = 1; i < argc; ++i)
		{
			print_str(argv[i]);
			if (i < argc - 1)
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}
