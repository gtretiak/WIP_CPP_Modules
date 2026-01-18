#include "sed.hpp"

struct Test {
	std::string	description;
	std::string	infile;
	std::string	s1;
	std::string	s2;
	std::string	expected;
};

static	int	arg_checker(int argc) {
	if (argc != 2)
	{
		std::cout << "Error: No arguments. Insert the program name to test." << std::endl;
		return (1);
	}
	return (0);
}

static void	printErrors(std::string file1, std::string file2) {
	std::ifstream f1(file1.c_str());
	std::ifstream f2(file2.c_str());
	std::string	line1, line2;
	std::string	toPrint;
	if (!f1 || !f2)
	{
		std::cerr << "Error: Invalid file(s)." << std::endl;
		return ;
	}
	std::cout << "Expected error:" << std::endl;
	while (std::getline(f2, line2))
		toPrint += line2 + "\n";
	if (!toPrint.empty())
		toPrint.erase(toPrint.end() - 1);
	std::cout << toPrint << std::endl;
	toPrint.clear();
	std::cout << "The program printed:" << std::endl;
	while (std::getline(f1, line1))
		toPrint += line1 + "\n";
	if (!toPrint.empty())
		toPrint.erase(toPrint.end() - 1);
	std::cout << toPrint << std::endl;
}

static bool	compareFiles(std::string file1, std::string file2) {
	std::ifstream f1(file1.c_str());
	std::ifstream f2(file2.c_str());
	std::string	line1, line2;
	if (!f1 || !f2)
	{
		std::cerr << "Error: Invalid file(s)." << std::endl;
		return (false);
	}
	while (std::getline(f1, line1) && std::getline(f2, line2))
	{
		if (line1 != line2)
			return (false);
	}
	return (f1.eof() && f2.eof());
}

int	main(int argc, char **argv) {
	std::string	cmd;
	std::string	output;
	const int	N = 9;
	if (arg_checker(argc))
		return (1);
	std::string	name(argv[1]);
	int	res;
	Test	tests[N] = {
		{"Test 1: No arguments", "normal", "a", "b", "error_no_arg"},
		{"Test 2: Too few arguments", "normal", "a", "b", "error_few_arg"},
		{"Test 3: Too many arguments", "normal", "a", "b", "error_many_arg"},
		{"Test 4: No file to read", "qwertyfile", "a", "b", "error_no_file"},
		{"Test 5: Infile is protected to read from", "protected", "a", "b", "error_protected1"},
		{"Test 6: Infile is empty (nothing to search)", "empty", "a", "b", "error_empty_file"},
		{"Test 7: String is empty (nothing to search)", "normal", "''", "b", "error_empty_str"},
		{"Test 8: Outfile is protected", "outprotected", "a", "b", "error_protected2"},
		{"Test 9: Good arguments", "normal", "42", "Life", "success"}
	};
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
			cmd = "./" + name;
		else if (i == 1)
			cmd = "./" + name + " " + tests[i].s1 + " " + tests[i].s2;
		else if (i == 2)
			cmd = "./" + name + " " + tests[i].infile + " " + tests[i].s1 + " " + tests[i].s2 + " " + name + ".replace";
		else
			cmd = "./" + name + " " + tests[i].infile + " " + tests[i].s1 + " " + tests[i].s2;
		if (i < N - 1)
		{
			output = "program_" + tests[i].expected;
			cmd += " 2> " + output;
		}
		res = system(cmd.c_str());
		std::cout << tests[i].description << std::endl;
		if (res == 0)
			std::cout << "The program returned 0 (no error found)." << std::endl;
		else 
			std::cout << "The program returned non-zero value (found the error)" << std::endl;
		if (i < N - 1)
			printErrors(output, tests[i].expected);
		else
		{
			if (compareFiles(tests[i].infile + ".replace", tests[i].expected))
				std::cout << "Test " << i + 1 << " passed";
			else
				std::cout << "Test " << i + 1 << " failed";
		}
		cmd.clear();
		std::cout << std::endl;
	}
	return (0);
}
