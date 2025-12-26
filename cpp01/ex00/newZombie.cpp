#include "Zombie.class.hpp"

Zombie	*newZombie(std::string name) {
	Zombie *newUnit = new Zombie(name);
	return (newUnit);
}
