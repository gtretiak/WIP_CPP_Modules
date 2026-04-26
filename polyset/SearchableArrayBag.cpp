#include "SearchableArrayBag.hpp"

SearchableArrayBag::SearchableArrayBag() : ArrayBag() {}
SearchableArrayBag::SearchableArrayBag(const SearchableArrayBag &An) : ArrayBag(An) {}
SearchableArrayBag	&SearchableArrayBag::operator=(const SearchableArrayBag &An) {
	if (this != &An)
		ArrayBag::operator=(An);
	return (*this);
}
SearchableArrayBag::~SearchableArrayBag() {}
bool	SearchableArrayBag::has(int n) const {
	for (size_t i = 0; i < this->_size; i++)
	{
		if (n == this->_data[i])
			return (true);
	}
	return (false);
}
