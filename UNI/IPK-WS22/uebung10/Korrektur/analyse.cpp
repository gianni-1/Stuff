//
// Created by admin on 05.02.23.
//

#include "aufgabe1und2.cc"


int main() {
    // 1a) erstelle Objekt mit jedem Konstruktor
    int int2 = 234;
    std::string string3 = "2342354265442456456234";
    std::string add_solution = "2342354265442456456468";

    BigInteger big_int1;
    BigInteger big_int2(int2);
    BigInteger big_int3(string3);
    BigInteger big_int3_compare_add(add_solution);

    // 1b) teste cout
    std::cout << "\n1b) Sind folgende Zahlen gleich?" << std::endl;
    std::cout << "1: " << big_int1 << std::endl;
    std::cout << "1: " << "" << std::endl;

    std::cout << "2: " << big_int2 << std::endl;
    std::cout << "2: " << int2 << std::endl;

    std::cout << "3: " << big_int3 << std::endl;
    std::cout << "3: " << string3 << std::endl;

    // 2a) teste Addition
    BigInteger add1 = big_int2 + big_int3;
    big_int3 += big_int2;
    std::cout << "\n2a) Sind die 3 Zahlen gleich?" << std::endl;
    std::cout << big_int3 << " (+=)" << std::endl;
    std::cout << add1 << " (+)" << std::endl;
    std::cout << big_int3_compare_add << " (correct solution)" << std::endl;

    // 2b)
    BigInteger a(1);
    int b = 1;
    std::cout << "\n2b) Sind folgende Rechnungen richtig?" << std::endl;
    std::cout << "1 + 1 = " << a + b << std::endl;
    std::cout << "1 + 1 = " << b + a << std::endl;

}