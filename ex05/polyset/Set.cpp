#include "Set.hpp"

Set::Set(SearchableBag *bag) : bag(bag) {}
Set::Set(const Set &An) : bag(An.bag) {}
Set	&Set::operator=(const Set &An) {
	if (this != &An)
		this->bag = An.bag;
	return (*this);
}
Set::~Set() {}

bool	Set::has(int n) const {
	return (this->bag->has(n));
}
void	Set::insert(int n) {
	if (!this->bag->has(n))
		this->bag->insert(n);
}
void	Set::insert(int *arr, int size) {
	for (int i = 0; i < size; i++)
	{
		if (!this->bag->has(arr[i]))
			this->bag->insert(arr[i]);
	}
}
void	Set::print() const {
	this->bag->print();
}
void	Set::clear() const {
	this->bag->clear();
}
