#include <iostream>

const int MAX_SIZE = 100;

void rotateMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    // Transpose the matrix
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row of the transposed matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size / 2; j++) {
            std::swap(matrix[i][j], matrix[i][size - j - 1]);
        }
    }
}

int main() {
    int size;
    std::cout << "Enter the size of the matrix: ";
    std::cin >> size;

    int matrix[MAX_SIZE][MAX_SIZE];

    std::cout << "Enter the elements of the matrix:" << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cin >> matrix[i][j];
        }
    }

    rotateMatrix(matrix, size);

    std::cout << "Rotated matrix:" << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
