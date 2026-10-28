#include <iostream>

int main() {
    int* value_pointer = new int(42);
    int* dangling_pointer = value_pointer;

    std::cout << "Value: " << *value_pointer << '\n';
    std::cout << "Value through another pointer: " << *dangling_pointer << '\n';

    delete value_pointer;
    value_pointer = nullptr;

    std::cout << "dangling_pointer now refers to freed memory.\n";
    std::cout << "Reading *dangling_pointer can give garbage or crash the program.\n";
    std::cout << "Deleting it again can cause a double free.\n";
    dangling_pointer = nullptr;

    int array_size = 6;
    int* values = new int[array_size];

    for (int index = 0; index < array_size; index++) {
        values[index] = (index + 1) * 10;
    }

    std::cout << "Array before insertion: ";
    for (int index = 0; index < array_size; index++) {
        std::cout << values[index] << ' ';
    }
    std::cout << '\n';

    int insertion_index = array_size / 2;
    int inserted_value = 99;
    int* expanded_values = new int[array_size + 1];

    for (int index = 0; index < insertion_index; index++) {
        expanded_values[index] = values[index];
    }
    expanded_values[insertion_index] = inserted_value;
    for (int index = insertion_index; index < array_size; index++) {
        expanded_values[index + 1] = values[index];
    }

    delete[] values;
    values = expanded_values;
    expanded_values = nullptr;
    array_size++;

    std::cout << "Array after insertion: ";
    for (int index = 0; index < array_size; index++) {
        std::cout << values[index] << ' ';
    }
    std::cout << '\n';

    delete[] values;
    values = nullptr;

    std::cout << "Memory released, pointers set to nullptr.\n";
    return 0;
}
