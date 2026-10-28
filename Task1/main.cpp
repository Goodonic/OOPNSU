#include "add.h"
#include "modified_add.h"

#include <iostream>

int main() {
    int first_addend;
    int second_addend;

    std::cout << "Enter two integers: ";
    if (!(std::cin >> first_addend >> second_addend)) {
        std::cerr << "Input error: 2 numbers expected\n";
        return 1;
    }

    std::cout << "add: " << add(first_addend, second_addend) << '\n';
    std::cout << "modified_add: " << modified_add(first_addend, second_addend) << '\n';

    return 0;
}
