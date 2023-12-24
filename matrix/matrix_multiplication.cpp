#include <iostream>

int main() {
    int rows1, cols1, rows2, cols2;

    // Get the size of the first matrix from the user
    std::cout << "Enter the number of rows for the first matrix: ";
    std::cin >> rows1;
    std::cout << "Enter the number of columns for the first matrix: ";
    std::cin >> cols1;

    // Get the size of the second matrix from the user
    std::cout << "Enter the number of rows for the second matrix: ";
    std::cin >> rows2;
    std::cout << "Enter the number of columns for the second matrix: ";
    std::cin >> cols2;

    // Check if the matrices can be multiplied
    if (cols1 != rows2) {
        std::cout << "Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix." << std::endl;
        return 0;
    }

    // Create the matrices
    int matrix1[rows1][cols1];
    int matrix2[rows2][cols2];
    int result[rows1][cols2];

    // Get the data for the first matrix from the user
    std::cout << "Enter the data for the first matrix:" << std::endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            std::cin >> matrix1[i][j];
        }
    }

    // Get the data for the second matrix from the user
    std::cout << "Enter the data for the second matrix:" << std::endl;
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            std::cin >> matrix2[i][j];
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print the result
    std::cout << "Result:" << std::endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
