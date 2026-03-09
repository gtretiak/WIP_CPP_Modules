#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>

class	Form;

class	Bureaucrat {
	private:
		std::string const	name_;
		int			grade_;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &Another);
		Bureaucrat	&operator=(const Bureaucrat &Another);
		class	GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		const std::string	&getName() const;
		int			getGrade() const;
		void			incrementGrade();
		void			decrementGrade();
		void			signForm(Form &obj);
		void			executeForm(Form const &form);
		~Bureaucrat();
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
