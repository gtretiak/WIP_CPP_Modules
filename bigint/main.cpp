#include <iostream>
#include "bigint.hpp"

int main() {
    // Construction
    bigint num1("-1391.031287317319239126391263918732"), num2("1;"), num3, num4(-1);
    bigint num5 = num2;
    const bigint numC(6);
    std::cout << num1 << "\n" << num2 << "\n" << num3 << "\n" << num4 << "\n" << num5 << "\n" << numC << std::endl;
    // Arithmetic operators testing
    std::cout << num1 << num2 << num3 << num4 << num5 << numC << std::endl;
    std::cout << "num1 + num2 = " << (num1 + num2) << std::endl;
    num3 = num1;
    num3 += num2;
    std::cout << "num3 += num2: " << num3 << std::endl;

    bigint num8("999"), num9("9990");

    // Comparison testing
    std::cout << "num8 == num9: " << (num8 == num9) << std::endl;
    std::cout << "num8 != num9: " << (num8 != num9) << std::endl;
    std::cout << "num8 < num9: " << (num8 < num9) << std::endl;
    std::cout << "num8 <= num9: " << (num8 <= num9) << std::endl;
    std::cout << "num8 > num9: " << (num8 > num9) << std::endl;
    std::cout << "num8 >= num9: " << (num8 >= num9) << std::endl;

    bigint num10("4254");
    // Test: shifting with integers
    std::cout << "num1 << 2 = " << (num10 << 2) << std::endl;
    std::cout << "num1 >> 2 = " << (num10 >> 4) << std::endl;

    bigint num11("2");
    // Test: shifting with bigints
    std::cout << "num1 << num5 = " << (num10 >> num11) << std::endl;
    std::cout << "num1 >> num5 = " << (num10 << num11) << std::endl;

    bigint num12("2");
    // Pre- and post- incrementing
    std::cout << "num12++ = " << (num12++) << std::endl;
    std::cout << "num12 = " << (num12) << std::endl;
    std::cout << "++num12 = " << (++num12) << std::endl;
    std::cout << "num12 = " << (num12) << std::endl;

    // Test: shifting with const bigints
    std::cout << "num1 << numC = " << (num10 << numC) << std::endl;
    std::cout << "num1 >> numC = " << (num10 >> numC) << std::endl;

    // Test: shifting with integers combined with reassignment
    num3 = num1;
    num3 <<= 2;
    std::cout << "num3 <<= 2: " << num3 << std::endl;
    num3 >>= 1;
    std::cout << "num3 >>= 1: " << num3 << std::endl;

    // Test: shifting with bigints combined with reassignment
    num3 = num1;
    num3 <<= num5;
    std::cout << "num3 <<= num5: " << num3 << std::endl;
    num3 >>= num5;
    std::cout << "num3 >>= num5: " << num3 << std::endl;
    return 0;
}
