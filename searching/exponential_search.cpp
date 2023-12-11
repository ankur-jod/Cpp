#include <iostream>

int exponentialSearch(int arr[], int n, int target) {
    if (arr[0] == target) {
        return 0;
    }

    int i = 1;
    while (i < n && arr[i] <= target) {
        i *= 2;
    }

    return -1;
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int arr[n];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int target;
    std::cout << "Enter the target element: ";
    std::cin >> target;

    int result = exponentialSearch(arr, n, target);
    if (result == -1) {
        std::cout << "Element not found." << std::endl;
    } else {
        std::cout << "Element found at index " << result << std::endl;
    }

    return 0;
}
