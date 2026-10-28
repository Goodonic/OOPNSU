#include "add.h"
#include "modified_add.h"

#include <iostream>

int main() {
    int first_addend;
    int second_addend;

    std::cout << "Enter two integers: ";
    if (!(std::cin >> first_addend >> second_addend)) {
        std::cerr << "Input error: 2 integers expected\n";
        return 1;
    }

    double first_double_addend;
    double second_double_addend;

    std::cout << "Enter two real numbers: ";
    if (!(std::cin >> first_double_addend >> second_double_addend)) {
        std::cerr << "Input error: 2 real numbers expected\n";
        return 1;
    }

    std::cout << "02.IV\n";
    std::cout << "original::add<int>: " << original::add<int>(first_addend, second_addend) << '\n';
    std::cout << "modified::add<int>: " << modified::add<int>(first_addend, second_addend) << '\n';
    std::cout << "original::add<double>: " << original::add<double>(first_double_addend, second_double_addend) << '\n';
    std::cout << "modified::add<double>: " << modified::add<double>(first_double_addend, second_double_addend) << '\n';

    return 0;
}
