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
	protected:
		virtual void	execute2() const = 0;
	public:
		AForm();
		AForm(std::string name, int toSign, int toExec);
		AForm(const AForm &Another);
		AForm	&operator=(const AForm &Another);
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
		virtual ~AForm();
};

std::ostream	&operator<<(std::ostream &os, AForm &obj);

#endif
