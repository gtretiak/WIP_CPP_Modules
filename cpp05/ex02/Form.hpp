#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class	Bureaucrat;

class	Form {
	private:
		std::string const	name_;
		bool			isSigned_;
		const int		signGrade_;
		const int		execGrade_;
	public:
		Form();
		Form(std::string name, int toSign, int toExec);
		Form(const Form &Another);
		Form	&operator=(const Form &Another);
		std::string	getName() const;
		bool		getStatus() const;
		int		getGradeToSign() const;
		int		getGradeToExec() const;
		void		beSigned(Bureaucrat &obj);
		void		execute(Bureaucrat const &executor) const;
		class	SignedException : public std::exception {
			public:
				const char *what() const throw();
		};
		class	GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		~Form();
};

std::ostream	&operator<<(std::ostream &os, Form &obj);

#endif
