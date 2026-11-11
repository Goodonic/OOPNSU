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

    for (int index = 0; index < 2; index++) {
        const std::vector<int>& values = vectors[index];
        std::cout << "Vector " << index + 1 << " count: " << values.size() << '\n';

        std::map<int, int> counts;
        for (int number : values) {
            counts[number]++;
        }

        for (const auto& item : counts) {
            std::cout << "Number " << item.first << " count (for): " << item.second << '\n';
            std::cout << "Number " << item.first << " count (std::count): "
                      << std::count(values.begin(), values.end(), item.first) << '\n';
        }

        std::cout << "Sum (accumulate): "
                  << std::accumulate(values.begin(), values.end(), 0LL) << '\n';

        long long sum = 0;
        std::for_each(values.begin(), values.end(), [&sum](int number) {
            sum += number;
        });
        std::cout << "Sum (for_each): " << sum << '\n';

        if (values.size() >= 10) {
            std::cout << "Sum of first 10: "
                      << std::accumulate(values.begin(), values.begin() + 10, 0LL) << '\n';
        } else {
            std::cout << "Sum of first 10: not enough numbers\n";
        }
    }

    return 0;
}
