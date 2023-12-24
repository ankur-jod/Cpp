#include <iostream>

void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    int* matrix = new int[rows * cols];

    std::cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows * cols; i++) {
        std::cin >> matrix[i];
    }

    bubbleSort(matrix, rows * cols);

    std::cout << "Sorted matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i * cols + j] << " ";
        }
        std::cout << "\n";
    }

    delete[] matrix;
    return 0;
}