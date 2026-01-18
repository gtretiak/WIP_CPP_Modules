#include "sed.hpp"

static	int	arg_checker(int argc, char **argv) {
	if (argc != 4)
	{
		std::cerr << "Error: Invalid number of arguments. Expected a filename and two strings." << std::endl;
		return (1);
	}
	std::string	s1(argv[2]);
	if (s1.empty())
	{
		std::cerr << "Error: String to be replaced is empty." << std::endl;
		return (1);
	}
	return (0);
}

static	std::string	reading(const std::string &filename) {
	std::string	text;
	std::string	buf;
	std::ifstream	infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error: Invalid input file." << std::endl;
		return ("");
	}
	while (std::getline(infile, buf))
		text.append(buf).append("\n");
	if (text.empty())
		std::cerr << "Error: File is empty." << std::endl;
	else
		text.erase(text.end() - 1);
	return (text);
}

static	std::string	replacement(const std::string text, const std::string needle, const std::string better) {
	std::string	result;
	std::size_t	found = 0;
	std::size_t	pos = 0;
	while ((found = text.find(needle, pos)) != std::string::npos)
	{
		result.append(text.substr(pos, found - pos).append(better));
		pos = found + needle.length();
	}
	result.append(text.substr(pos));
	return (result);
}

static	int	printing(const std::string &result, const std::string &filename) {
	std::string	newfile = filename + ".replace";
	std::ofstream	outfile(newfile.c_str());
	if (!outfile)
	{
		std::cerr << "Error: Invalid output file." << std::endl;
		return (1);
	}
	outfile << result << std::endl;
	return (0);
}

int	main(int argc, char **argv) {
	std::string	text;
	std::string	result;
	if (arg_checker(argc, argv))
		return (1);
	std::string	filename(argv[1]);
	text = reading(filename);
	if (text.empty())
		return (1);
	std::string	needle(argv[2]);
	std::string	better(argv[3]);
	result = replacement(text, needle, better);
	if (result.empty())
		return (1);
	if (printing(result, filename))
		return (1);
	return (0);
}
