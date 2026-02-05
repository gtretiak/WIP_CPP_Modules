#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class	Brain {
	private:
		std::string	ideas_[100];
	public:
		Brain();
		Brain(const Brain &Another);
		Brain	&operator=(const Brain &Another);
		void		setIdea(int i, const std::string idea);
		std::string	getIdea(int i) const;
		~Brain();
};

#endif
