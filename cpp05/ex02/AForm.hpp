#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class	Bureaucrat;

class	AForm {
	private:
		std::string const	name_;
		bool			isSigned_;
		const int		signGrade_;
		const int		execGrade_;
	public:
		AForm();
		AForm(std::string name, int toSign, int toExec);
		AForm(const Form &Another);
		AForm	&operator=(const AForm &Another);
		std::string	getName() const;
		bool		getStatus() const;
		int		getGradeToSign() const;
		int		getGradeToExec() const;
		void		beSigned(Bureaucrat &obj);
		virtual void	execute(Bureaucrat const &executor) const = 0;
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
		virtual ~AForm();
};

std::ostream	&operator<<(std::ostream &os, AForm &obj);

#endif
