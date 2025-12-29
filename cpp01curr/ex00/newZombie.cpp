#include "Zombie.class.hpp"
#include <string>

Zombie	*newZombie(std::string name) {
	Zombie *newUnit = new Zombie(name);
	return (newUnit);
}
