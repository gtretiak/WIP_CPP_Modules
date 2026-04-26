#include "bigint.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

static std::string	summarize(std::string num1, std::string num2) {
	int		carry = 0;
	int		sum;
	int	i = (int)num1.size() - 1;
	int	j = (int)num2.size() - 1;
	std::string	res;
	while (i >= 0 || j >= 0 || carry)
	{
		sum = carry;
		if (i >= 0)
			sum += num1[i--] - '0';
		if (j >= 0)
			sum += num2[j--] - '0';
		res.append(1, ((sum % 10) + '0'));
		carry = sum / 10;
	}
	std::reverse(res.begin(), res.end());
	return (res);
}

static std::string	extractDigits(std::string num) {//atoi-like until the first non-digit
	std::string	res;
	for (size_t i = 0; i < num.size(); i++)
	{
		if (num[i] >= '0' && num[i] <= '9')
			res += num[i];
		else
			break ;
	}
	if (res.empty())
		return ("0");
	else
		return (res);
}

bigint::bigint() : num_("0") {}
bigint::bigint(std::string const &num) : num_(num) { //arguably needed
	this->num_ = extractDigits(num); //only if we accept string
	normalize_();
}
bigint::bigint(unsigned int num) : num_("0") {
	if (num > 0)
	{
		std::stringstream	ss;
		ss << num;
		this->num_ = ss.str();
	}
}
bigint::bigint(const bigint &N) : num_(N.num_) {}
bigint	&bigint::operator=(const bigint &N) {
	if (*this != N)
		this->num_ = N.num_;
	return (*this);
}
bigint	bigint::operator+(const bigint &N) const {
//	bigint	temp(summarize(this->num_, N.num_)); // only if accept strings
	bigint	temp;
	temp.num_ = summarize(this->num_, N.num_);
	return (temp);
}
bigint	&bigint::operator+=(const bigint &N) {
	this->num_ = summarize(this->num_, N.num_);
	normalize_();
	return (*this);
}
bigint	&bigint::operator++() {
	this->num_ = summarize(this->num_, "1");
	normalize_();
	return (*this);
}
bigint	bigint::operator++(int dum) {
	bigint	temp;
	temp.num_ = this->num_;
	this->num_ = summarize(this->num_, "1");
	normalize_();
	return (temp);
}
/*bigint	bigint::operator+(unsigned int z) const {
	std::stringstream	ss;
	ss << z;
	bigint	temp;
	temp.num_ = summarize(this->num_, ss.str());
	return (temp);
}
bigint	&bigint::operator+=(unsigned int z) {
	std::stringstream	ss;
	ss << z;
	this->num_ = summarize(this->num_, ss.str());
	normalize_();
	return (*this);
}*/
//bigint	bigint::operator-() const;//optional
//bigint	bigint::operator-(const bigint &N) const;//optional
//bigint	bigint::operator-(int z) const;//optional
//bigint	&bigint::operator-=(const bigint &N);//optional
//bigint	&bigint::operator-=(int z);//optional
//bigint	&bigint::operator--();//optional
//bigint	bigint::operator--(int dum);//optional
bool	bigint::operator==(const bigint &N) const {
	return (this->num_ == N.num_);
}
bool	bigint::operator!=(const bigint &N) const {
	return !(*this == N);
}
bool	bigint::operator<(const bigint &N) const {
	if (this->num_.size() != N.num_.size())
		return (this->num_.size() < N.num_.size());//normalized length comparison
	return (this->num_ < N.num_);//ascii comparison
}
bool	bigint::operator<=(const bigint &N) const {
	return !(N < *this);
}
bool	bigint::operator>(const bigint &N) const {
	return (N < *this);
}
bool	bigint::operator>=(const bigint &N) const {
	return !(*this < N);
}
/*bool	bigint::operator==(unsgined int z) const {
	return (*this == bigint(z));
}
bool	bigint::operator!=(unsigned int z) const {
	return (*this != bigint(z));
}
bool	bigint::operator<(unsigned int z) const {
	return (*this < bigint(z));
}
bool	bigint::operator<=(unsigned int z) const {
	return (*this <= bigint(z));
}
bool	bigint::operator>(unsigned int z) const {
	return (*this > bigint(z));
}
bool	bigint::operator>=(unsigned int z) const {
	return (*this >= bigint(z));
}*/
bigint	bigint::operator<<(const bigint &N) const {
	unsigned int	z;
	if (this->num_ == "0")
		return (*this);
	bigint	temp;
	temp.num_ = this->num_;
	std::stringstream	ss(N.num_);
	ss >> z;
	temp.num_ += std::string(z, '0');
	temp.normalize_();
	return (temp);	
}
bigint	bigint::operator>>(const bigint &N) const {
	unsigned int	z;
	bigint	temp;
	temp.num_ = this->num_;
	std::stringstream	ss(N.num_);
	ss >> z;
	if (z >= (unsigned int)temp.num_.size())
		return (bigint());
	temp.num_ = temp.num_.substr(0, temp.num_.size() - z);
	temp.normalize_();
	return (temp);
}
bigint	&bigint::operator<<=(const bigint &N) {
	unsigned int	z;
	std::stringstream	ss(N.num_);
	ss >> z;
	if (this->num_ != "0")
		this->num_ += std::string(z, '0');
	normalize_();
	return (*this);
}
bigint	&bigint::operator>>=(const bigint &N) {
	unsigned int	z;
	std::stringstream	ss(N.num_);
	ss >> z;
	if (z >= (unsigned int)this->num_.size())
		this->num_ = "0";
	else
		this->num_ = this->num_.substr(0, this->num_.size() - z);
	normalize_();
	return (*this);
}
bigint	bigint::operator<<(unsigned int z) const {
	if (this->num_ == "0")
		return (*this);
	bigint	temp;
	temp.num_ = this->num_;
	temp.num_ += std::string(z, '0');
	temp.normalize_();
	return (temp);	
}
bigint	bigint::operator>>(unsigned int z) const {
	bigint	temp;
	temp.num_ = this->num_;
	if (z >= (unsigned int)temp.num_.size())
		return (bigint());
	temp.num_ = temp.num_.substr(0, temp.num_.size() - z);
	temp.normalize_();
	return (temp);
}
bigint	&bigint::operator<<=(unsigned int z) {
	if (this->num_ != "0")
		this->num_ += std::string(z, '0');
	normalize_();
	return (*this);
}
bigint	&bigint::operator>>=(unsigned int z) {
	if (z >= (unsigned int)this->num_.size())
		this->num_ = "0";
	else
		this->num_ = this->num_.substr(0, this->num_.size() - z);
	normalize_();
	return (*this);
}

std::string	bigint::getNum() const {
	return (this->num_);
}

void	bigint::normalize_() {
	size_t	pos = this->num_.find_first_not_of('0');
	if (pos == std::string::npos)
		this->num_ = "0";
	else
		this->num_ = this->num_.substr(pos);
}

bigint::~bigint() {}

std::ostream	&operator<<(std::ostream &os, const bigint &N) {
	os << N.getNum();
	return (os);
}
