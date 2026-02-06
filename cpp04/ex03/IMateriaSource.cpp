#include "IMateriaSource.hpp"
#include <iostream>

IMateriaSource::~IMateriaSource() {
	std::cout << "IMateriaSource destructed" << std::endl;
}
