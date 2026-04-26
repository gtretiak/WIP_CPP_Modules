#ifndef SET_HPP
#define SET_HPP

#include "SearchableBag.hpp"

class	Set {
	private:
		SearchableBag	*bag;
	public:
		Set(SearchableBag *bag);
		Set(const Set &An);
		Set	&operator=(const Set &An);
		~Set();
		void	print() const;
		void	clear() const;
		void	insert(int n);
		void	insert(int *arr, int size);
		bool	has(int n) const;
};

#endif
