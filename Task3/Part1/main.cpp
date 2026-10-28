#include "add.h"
#include "modified_add.h"

#include <iomanip>
#include <iostream>

int main() {
    int first_addend;
    int second_addend;

    std::cout << "Enter two integers: ";
    if (!(std::cin >> first_addend >> second_addend)) {
        std::cerr << "Input error: 2 integers expected\n";
        return 1;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "int -> double\n";
    std::cout << "original::add: " << original::add<double>(first_addend, second_addend) << '\n';
    std::cout << "modified::add: " << modified::add<double>(first_addend, second_addend) << '\n';

    std::cout << "int -> float\n";
    std::cout << "original::add: " << original::add<float>(first_addend, second_addend) << '\n';
    std::cout << "modified::add: " << modified::add<float>(first_addend, second_addend) << '\n';

    double first_double_addend;
    double second_double_addend;

    std::cout << "Enter two real numbers: ";
    if (!(std::cin >> first_double_addend >> second_double_addend)) {
        std::cerr << "Input error: 2 real numbers expected\n";
        return 1;
    }

    std::cout << "double -> int\n";
    std::cout << "original::add: " << original::add<int>(first_double_addend, second_double_addend) << '\n';
    std::cout << "modified::add: " << modified::add<int>(first_double_addend, second_double_addend) << '\n';

    return 0;
}
