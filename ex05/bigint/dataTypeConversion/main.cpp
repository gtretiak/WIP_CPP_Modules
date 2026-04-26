#include <iostream>
#include <string>

void	printUnsignedInt(unsigned int z) {
	std::cout << z << std::endl;
}
void	printString(std::string z) {
	std::cout << z << std::endl;
}
int main() {
	printUnsignedInt(1); // stays 1
	printUnsignedInt(21474836480); //warning: long int becomes 0
	printUnsignedInt(-1); // becomes 4294967295
	printUnsignedInt(-21474836490);//warning: long int becomes 0
	printUnsignedInt(3.14f); // becomes 3
	printUnsignedInt(3.14); // becomes 3
	printUnsignedInt('A'); // becomes 65
	//printUnsignedInt("2");--
	//printUnsignedInt(";");--
	//printString(1);--
	//printString(21474836480);--
	//printString(-1);--
	//printString(-21474836490);--
	//printString(3.14f);--
	//printString(3.14);--
	//printString('A');--
	printString("2");//stays 2
	printString(";");//stays 2
	if (124.2 == 124.2f) std::cout << "yes1" << std::endl;//no, unless both casted to int, because float is different from double in binary terms
	if (124 == 124.2) std::cout << "yes2" << std::endl;//no, unless casted
	if (124 == 124.2f) std::cout << "yes3" << std::endl;//no, unless casted
	if (97 == 'a') std::cout << "yes4" << std::endl;//yes
//	if (97 == "a") std::cout << "yes5" << std::endl;--
//	if (11 == ";") std::cout << "yes6" << std::endl;--
	if (11 == ';' - 48) std::cout << "yes7" << std::endl;//yes
	if (-3 == '-' - 48) std::cout << "yes8" << std::endl;//yes
//	if ('a' == "a") std::cout << "yes9" << std::endl;--
	if ((unsigned int)-1 == 4294967295) std::cout << "yes10" << std::endl;//yes
	std::cout << 1 + 'y' << std::endl;//122
	std::cout << 'y' + 1 << std::endl;//122
	std::cout << 1 - 'y' << std::endl;//-120
	std::cout << 'y' - 1 << std::endl;//120
	std::cout << 1 * 'y' << std::endl;//121
	std::cout << 'y' * 1 << std::endl;//121
	std::cout << 'h' + 'y' << std::endl;//225
//	std::cout << 1 * "yes" << std::endl;
//	std::cout << "yes" * 1 << std::endl;
//	std::cout << 1 - "yes" << std::endl;
	std::cout << "yes" - 1 << std::endl;//empty string
	std::cout << "yes" - 'e' << std::endl;//empty string
	std::cout << "yes" - "e" << std::endl;//-4
	std::cout << 1 + "yes" << std::endl;//es
	std::cout << "yes" + 1 << std::endl;//es
//	std::cout << "hello " + "yes" << std::endl;
//	std::cout << (unsigned int)"hello";
	std::cout << (unsigned int)'h' << std::endl;//104
	std::cout << (unsigned int)-2 << std::endl;//4294967294
	std::cout << (unsigned int)2.5 << std::endl;//becomes 2
	std::cout << (unsigned int)2.5f << std::endl;//becomes 2
    return 0;
}
