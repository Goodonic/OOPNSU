#include "add.h"
#include "modified_add.h"
#include "reference_add.h"

#include <iostream>

int main() {
    int first_addend;
    int second_addend;

    std::cout << "Enter two integers: ";
    if (!(std::cin >> first_addend >> second_addend)) {
        std::cerr << "Input error\n";
        return 1;
    }

    std::cout << "02.I\n";
    int changing_first_addend = first_addend;
    std::cout << "First addend before: " << changing_first_addend << '\n';
    std::cout << "add by reference: " << reference_version::add(changing_first_addend, second_addend) << '\n';
    std::cout << "First addend after: " << changing_first_addend << '\n';

    std::cout << "add by const reference: " << add(first_addend, second_addend) << '\n';
    std::cout << "modified_add by const reference: " << modified_add(first_addend, second_addend) << '\n';
    std::cout << "Addends after const reference calls: " << first_addend << ' ' << second_addend << '\n';

    return 0;
}
