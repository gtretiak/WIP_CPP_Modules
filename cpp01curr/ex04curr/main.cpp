#include "sed.hpp"

int	main(int argc, char **argv) {
	std::string	result;
	std::string	initialText;
	size_t		pos;
	size_t		len;
	if (argc != 4)
	{
		std::cerr << "Error: Invalid number of arguments. Expected a filename and two strings." << std::endl;
		return (1);
	}
	std::cout << "filename: " << argv[1] << std::endl;
	std::cout << "string to be replaced: " << argv[2] << std::endl;
	std::cout << "string to replace with: " << argv[3] << std::endl;
	std::ifstream	infile(argv[1]);
	if (!infile)
	{
		std::cerr << "Error: Invalid filename." << std::endl;
		return (1);
	}
	if (infile.empty())
	{
		std::cerr << "Error: No text has been found in the file." << std::endl;
		return (1);
	}
	if (argv[2].empty())
	{
		std::cerr << "Error: string to be replaced is empty." << std::endl;
		return (1);
	}
	len = argv[2].length();
	std::getline(infile, initialText);
	pos = infile.find(argv[2]);
	if (pos = npos)
		std::cout << "Not found" << std::endl;
	result = infile.substr(0, pos);
//	result += //new cycle
//	input.length()
//	std::ofstream	result(argv[1] + ".replace");	
	return (0);
}
