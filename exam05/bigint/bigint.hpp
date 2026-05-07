#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class	bigint {
	private:
		std::string	num_;
		void	normalize_();
	public:
		bigint();
		bigint(std::string const &num);
		bigint(unsigned int num);
		bigint(const bigint &N);
		bigint	&operator=(const bigint &N);
		bigint	operator+(const bigint &N) const;
		bigint	&operator+=(const bigint &N);
		bigint	&operator++();
		bigint	operator++(int dum);
		//bigint	operator+(int z) const;
		//bigint	&operator+=(int z);
		//bigint	operator-() const;//optional
		//bigint	operator-(const bigint &N) const;//optional
		//bigint	operator-(int z) const;//optional
		//bigint	&operator-=(const bigint &N);//optional
		//bigint	&operator-=(int z);//optional
		//bigint	&operator--();//optional
		//bigint	operator--(int dum);//optional
		bool	operator==(const bigint &N) const;
		bool	operator!=(const bigint &N) const;
		bool	operator<(const bigint &N) const;
		bool	operator<=(const bigint &N) const;
		bool	operator>(const bigint &N) const;
		bool	operator>=(const bigint &N) const;
		//bool	operator==(int z) const;
		//bool	operator!=(int z) const;
		//bool	operator<(int z) const;
		//bool	operator<=(int z) const;
		//bool	operator>(int z) const;
		//bool	operator>=(int z) const;
		bigint	operator<<(const bigint &N) const;
		bigint	operator>>(const bigint &N) const;
		bigint	&operator<<=(const bigint &N);
		bigint	&operator>>=(const bigint &N);
		bigint	operator<<(unsigned int z) const;
		bigint	operator>>(unsigned int z) const;
		bigint	&operator<<=(unsigned int z);
		bigint	&operator>>=(unsigned int z);
		std::string	getNum() const;
		~bigint();
};

std::ostream	&operator<<(std::ostream &os, const bigint &N);

#endif
