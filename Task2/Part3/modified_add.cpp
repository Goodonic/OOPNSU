#include "modified_add.h"
#include "add.h"

#include <random>

int modified::add(const int& first_addend, const int& second_addend) {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> chance(0, 1);
    std::uniform_int_distribution<int> random_number(1, 10);

    int result = original::add(first_addend, second_addend);
    if (chance(generator) == 1) {
        result += random_number(generator);
    }
    return result;
}

double modified::add(const double& first_addend, const double& second_addend) {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> chance(0, 1);
    std::uniform_int_distribution<int> random_number(1, 10);

    double result = original::add(first_addend, second_addend);
    if (chance(generator) == 1) {
        result += random_number(generator);
    }
    return result;
}
