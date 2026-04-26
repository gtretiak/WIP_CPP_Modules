#ifndef SEARCHABLETREEBAG
#define SEARCHABLETREEBAG

#include "SearchableBag.hpp"
#include "TreeBag.hpp"

class	SearchableTreeBag : public TreeBag, public SearchableBag {
	public:
		SearchableTreeBag();
		SearchableTreeBag(const SearchableTreeBag &An);
		SearchableTreeBag	&operator=(const SearchableTreeBag &An);
		virtual ~SearchableTreeBag();
		bool	has(int n) const;
};

#endif
