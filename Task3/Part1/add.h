#ifndef TASK3_ADD_H
#define TASK3_ADD_H

namespace original {
    template <typename ResultType, typename ArgumentType>
    ResultType add(const ArgumentType& first_addend, const ArgumentType& second_addend) {
        return static_cast<ResultType>(first_addend + second_addend);
    }
}

#endif
