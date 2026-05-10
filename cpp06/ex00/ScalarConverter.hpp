#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

class	ScalarConverter {
	public:
		virtual ScalarConverter() = 0;
		ScalarConverter(const ScalarConverter &An);
		ScalarConverter	&operator=(const ScalarConverter &An);
		static void	convert(std::string var);
		~ScalarConverter();
};

#endif
