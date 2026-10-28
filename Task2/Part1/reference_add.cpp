#include "reference_add.h"

int reference_version::add(int& first_addend, const int& second_addend) {
    first_addend += second_addend;
    return first_addend;
}
