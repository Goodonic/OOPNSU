#include "add.h"
#include "modified_add.h"

#include <iostream>

int main() {
    int first_addend;
    int second_addend;

    std::cout << "Enter two integers: ";
    if (!(std::cin >> first_addend >> second_addend)) {
        std::cerr << "Input error\n";
        return 1;
    }

    std::cout << "02.II\n";
    std::cout << "original::add: " << original::add(first_addend, second_addend) << '\n';
    std::cout << "modified::add: " << modified::add(first_addend, second_addend) << '\n';
    std::cout << "Addends after calls: " << first_addend << ' ' << second_addend << '\n';

    return 0;
}
