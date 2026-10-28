#ifndef TASK3_MODIFIED_ADD_H
#define TASK3_MODIFIED_ADD_H

#include "add.h"

#include <random>

namespace modified {
    template <typename ResultType, typename ArgumentType>
    ResultType add(const ArgumentType& first_addend, const ArgumentType& second_addend) {
        static std::mt19937 generator(std::random_device{}());
        std::uniform_int_distribution<int> chance(0, 1);
        std::uniform_int_distribution<int> random_number(1, 10);

        ArgumentType result = original::add<ArgumentType>(first_addend, second_addend);
        if (chance(generator) == 1) {
            result += random_number(generator);
        }
        return static_cast<ResultType>(result);
    }
}

#endif
