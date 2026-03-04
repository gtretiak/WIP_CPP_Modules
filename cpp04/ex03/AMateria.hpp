#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <string>
class	ICharacter;

class	AMateria {
	protected:
		std::string	type_;
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &Another);
		AMateria	&operator=(const AMateria &Another);
		std::string const	&getType() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
		virtual ~AMateria();
};

#endif
