#include <iostream>
#include <memory>
#include <utility>

int main() {
    std::unique_ptr<int> first_owner(new int(42));
    std::cout << "unique_ptr value: " << *first_owner << '\n';

    std::unique_ptr<int> second_owner = std::move(first_owner);
    std::cout << "First owner is empty: " << (first_owner == nullptr) << '\n';
    std::cout << "Value after moving ownership: " << *second_owner << '\n';

    second_owner.reset();
    std::cout << "Second owner is empty after reset: " << (second_owner == nullptr) << '\n';

    {
        const int array_size = 6;
        std::unique_ptr<int[]> values(new int[array_size]);

        std::cout << "Smart pointer array: ";
        for (int index = 0; index < array_size; index++) {
            values[index] = (index + 1) * 10;
            std::cout << values[index] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "Array memory released automatically after leaving the block.\n";

    std::weak_ptr<int> observer;
    {
        std::shared_ptr<int> first_shared_owner = std::make_shared<int>(100);
        std::shared_ptr<int> second_shared_owner = first_shared_owner;
        observer = first_shared_owner;

        first_shared_owner.reset();
        std::cout << "Object is alive while another owner exists: " << *second_shared_owner << '\n';

        std::shared_ptr<int> checked_value = observer.lock();
        if (checked_value) {
            std::cout << "Value obtained through weak_ptr: " << *checked_value << '\n';
        }
    }

    std::shared_ptr<int> checked_value = observer.lock();
    if (checked_value) {
        std::cout << "Value: " << *checked_value << '\n';
    } else {
        std::cout << "Object has been deleted. weak_ptr::lock returned an empty pointer.\n";
    }

    return 0;
}
