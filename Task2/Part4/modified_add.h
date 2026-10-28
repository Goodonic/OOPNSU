#ifndef TASK2_PART4_MODIFIED_ADD_H
#define TASK2_PART4_MODIFIED_ADD_H

#include "add.h"

#include <random>

namespace modified {
    template <typename T>
    T add(const T& first_addend, const T& second_addend) {
        static std::mt19937 generator(std::random_device{}());
        std::uniform_int_distribution<int> chance(0, 1);
        std::uniform_int_distribution<int> random_number(1, 10);

        T result = original::add<T>(first_addend, second_addend);
        if (chance(generator) == 1) {
            result += random_number(generator);
        }
        return result;
    }
}

#endif
