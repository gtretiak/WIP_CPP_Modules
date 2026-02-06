#include "ICharacter.hpp"
#include <iostream>

ICharacter::~ICharacter() {
	std::cout << "ICharacter destroyed" << std::endl;
}
