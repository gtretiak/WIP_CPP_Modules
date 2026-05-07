#include "SearchableTreeBag.hpp"

SearchableTreeBag::SearchableTreeBag() : TreeBag() {}
SearchableTreeBag::SearchableTreeBag(const SearchableTreeBag &An) : TreeBag(An) {}
SearchableTreeBag	&SearchableTreeBag::operator=(const SearchableTreeBag &An) {
	if (this != &An)
		TreeBag::operator=(An);
	return (*this);
}
SearchableTreeBag::~SearchableTreeBag() {}
bool	SearchableTreeBag::has(int n) const {
	Node	*current = this->root;
	while (current)
	{
		if (n > current->value)
			current = current->right;
		else if (n < current->value)
			current = current->left;
		else
			return (true);
	}
	return (false);
}
