#include <iostream>
#include "Harl.class.hpp"

int	main(void) {
	Harl	Instance;
	Instance.complain("debug");
	Instance.complain("info");
	Instance.complain("warning");
	Instance.complain("error");
	Instance.complain("non existent level");
	return 0;
}
