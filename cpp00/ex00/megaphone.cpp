#include <iostream>
#include <cctype>

static void	print_str(std::string s)
{
	for (int i = 0; i < s.length(); i++)
		s[i] = std::toupper(s[i]);
	std::cout << "\033[32m" << s;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "\033[31m* LOUD AND UNBEARABLE FEEDBACK NOISE *\033[0m";
 	else
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string	s(argv[i]);
			print_str(s);
			if (i < argc - 1)
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}
