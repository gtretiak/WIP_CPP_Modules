#ifndef SEARCHABLEARRAYBAG
#define SEARCHABLEARRAYBAG

#include "SearchableBag.hpp"
#include "ArrayBag.hpp"

class	SearchableArrayBag : public ArrayBag, public SearchableBag {
	public:
		SearchableArrayBag();
		SearchableArrayBag(const SearchableArrayBag &An);
		SearchableArrayBag	&operator=(const SearchableArrayBag &An);
		virtual ~SearchableArrayBag();
		bool	has(int n) const;
};

#endif
