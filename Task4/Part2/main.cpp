#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::vector<int> vectors[2];
    std::string file_names[2];

    for (int index = 0; index < 2; index++) {
        std::getline(std::cin, file_names[index]);
        std::ifstream file(file_names[index]);
        if (!file) {
            std::cerr << "Cannot open file\n";
            return 1;
        }

        while (file >> std::ws && !file.eof()) {
            int number;
            if (!(file >> number)) {
                std::cerr << "Expected an integer\n";
                return 1;
            }
            vectors[index].push_back(number);
        }
    }

    if (vectors[0].size() < vectors[1].size()) {
        std::swap(vectors[0], vectors[1]);
        std::swap(file_names[0], file_names[1]);
    }

    std::map<int, int> counts[2];
    for (int index = 0; index < 2; index++) {
        const std::vector<int>& values = vectors[index];
        long long result = std::accumulate(values.begin(), values.end(), 0LL,
            [](long long total, int number) {
                return total + number;
            });
        std::cout << "Vector " << index + 1 << " result (addition): " << result << '\n';

        for (int number : values) {
            counts[index][number]++;
        }

        int minimum_count = index == 0 ? 4 : 2;
        for (const auto& item : counts[index]) {
            if (item.second >= minimum_count) {
                std::cout << "Vector " << index + 1 << " number " << item.first
                          << " count: " << item.second << '\n';
            }
        }
    }

    for (const auto& item : counts[1]) {
        auto first = counts[0].find(item.first);
        if (item.second >= 2 && first != counts[0].end() && first->second > 3) {
            std::cout << "Number " << item.first << " (for): vector 1 count = "
                      << first->second << ", vector 2 count = " << item.second << '\n';
        }
    }

    std::for_each(counts[1].begin(), counts[1].end(),
        [&vectors](const std::pair<const int, int>& item) {
            auto first_count = std::count(vectors[0].begin(), vectors[0].end(), item.first);
            auto second_count = std::count(vectors[1].begin(), vectors[1].end(), item.first);
            if (first_count > 3 && second_count >= 2) {
                std::cout << "Number " << item.first << " (algorithm): vector 1 count = "
                          << first_count << ", vector 2 count = " << second_count << '\n';
            }
        });

    return 0;
}
