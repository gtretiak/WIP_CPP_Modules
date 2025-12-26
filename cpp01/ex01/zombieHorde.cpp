#include "Zombie.class.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	if (N <= 0)
		return (NULL);
	Zombie *newBatch = new Zombie[N];
	for (int i = 0; i < N; i++)
		newBatch[i].setZombie(name, i + 1);
	return (newBatch);
}
