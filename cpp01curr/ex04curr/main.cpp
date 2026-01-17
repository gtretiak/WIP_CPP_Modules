#include "sed.hpp"

int	arg_checker(int argc, char **argv) {
	if (argc != 4)
	{
		std::cerr << "Error: Invalid number of arguments. Expected a filename and two strings." << std::endl;
		return (1);
	}
	std::string	s1(argv[2]);
	if (s1.empty())
	{
		std::cerr << "Error: string to be replaced is empty." << std::endl;
		return (1);
	}
	return (0);
}

std::string	reading(char *filename) {
	std::string	text;
	std::string	buf;
	std::ifstream	infile(filename);
	if (!infile)
	{
		std::cerr << "Error: Invalid file." << std::endl;
		return ("");
	}
	while (std::getline(infile, buf))
	{	
		text += buf += "\n";
	}
	if (text.empty())
		std::cerr << "Error: File is empty." << std::endl;
	return (text);
}

int	main(int argc, char **argv) {
	std::string	text;
	if (arg_checker(argc, argv))
		return (1);
	text = reading(argv[1]);
	if (text.empty())
		return (1);
	
/*	size_t		pos;
//	size_t		len;
	pos = infile.find(argv[2]);
	if (pos = npos)
		std::cout << "Not found" << std::endl;
	result = infile.substr(0, pos);
//	result += //new cycle
//	input.length()
//	std::ofstream	result(argv[1] + ".replace");*/	
	return (0);
}
