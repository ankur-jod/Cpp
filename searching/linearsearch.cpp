#include <iostream>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int arr[size];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int target;
    std::cout << "Enter the target value: ";
    std::cin >> target;

    int result = linearSearch(arr, size, target);

    if (result == -1) {
        std::cout << "Target not found" << std::endl;
    } else {
        std::cout << "Target found at index " << result << std::endl;
    }

    return 0;
}
