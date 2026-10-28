#include "../Part1/modified_add.h"

#include <array>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <random>
#include <sstream>
#include <string>
#include <vector>

int main() {
    using InputType = int;
    using ResultType = double;

    const int container_size = 6;
    const InputType random_limit = 10;

    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<InputType> random_number(-random_limit, random_limit);
    const InputType second_addend = random_number(generator);

    std::array<InputType, container_size> array_values;
    std::vector<InputType> vector_values(container_size);
    std::list<InputType> list_values(container_size);
    std::deque<InputType> deque_values(container_size);

    std::vector<ResultType> array_results;
    std::list<ResultType> vector_results;
    std::deque<ResultType> list_results;
    std::array<ResultType, container_size> deque_results;

    for (std::size_t index = 0; index < array_values.size(); index++) {
        array_values[index] = random_number(generator);
        array_results.push_back(modified::add<ResultType>(array_values[index], second_addend));
    }

    for (std::vector<InputType>::iterator value = vector_values.begin(); value != vector_values.end(); value++) {
        *value = random_number(generator);
        vector_results.push_back(modified::add<ResultType>(*value, second_addend));
    }

    for (InputType& value : list_values) {
        value = random_number(generator);
        list_results.push_back(modified::add<ResultType>(value, second_addend));
    }

    for (std::size_t index = 0; index < deque_values.size(); index++) {
        deque_values[index] = random_number(generator);
        deque_results[index] = modified::add<ResultType>(deque_values[index], second_addend);
    }

    std::vector<std::string> table_rows;
    std::string table = "# Container results\n\n";
    table += "T1 = int, T2 = double, M = " + std::to_string(container_size);
    table += ", N = " + std::to_string(random_limit) + ".\n\n";
    table += "Second addend = " + std::to_string(second_addend) + ".\n\n";
    table += "| Index | `array<int>` | `vector<double>` result | `vector<int>` | `list<double>` result | `list<int>` | `deque<double>` result | `deque<int>` | `array<double>` result |\n";
    table += "| --- | --- | --- | --- | --- | --- | --- | --- | --- |\n";

    std::list<InputType>::const_iterator list_value = list_values.begin();
    std::list<ResultType>::const_iterator vector_result = vector_results.begin();

    for (std::size_t index = 0; index < array_values.size(); index++, list_value++, vector_result++) {
        std::ostringstream row;
        row << std::fixed << std::setprecision(2);
        row << "| " << index + 1
            << " | " << array_values[index] << " | " << array_results[index]
            << " | " << vector_values[index] << " | " << *vector_result
            << " | " << *list_value << " | " << list_results[index]
            << " | " << deque_values[index] << " | " << deque_results[index] << " |";
        table_rows.push_back(row.str());
        table += table_rows.back() + '\n';
    }

    std::ofstream output_file("containers.md");
    if (!output_file) {
        std::cerr << "Cannot open containers.md\n";
        return 1;
    }

    output_file << table;
    output_file.close();
    if (!output_file) {
        std::cerr << "Cannot write containers.md\n";
        return 1;
    }

    std::cout << table;
    std::cout << "\nSaved as containers.md\n";
    return 0;
}
