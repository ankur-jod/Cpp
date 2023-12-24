#include <iostream>

// Function to calculate the inverse of a matrix
void inverseMatrix(int n) {
    // Create the matrix
    int matrix[n][n];

    // Read the matrix elements from the user
    std::cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    // Calculate the determinant of the matrix
    int det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    // Check if the matrix is invertible
    if (det == 0) {
        std::cout << "Matrix is not invertible.\n";
        return;
    }

    // Calculate the inverse matrix
    int inverse[n][n];
    inverse[0][0] = matrix[1][1] / det;
    inverse[0][1] = -matrix[0][1] / det;
    inverse[1][0] = -matrix[1][0] / det;
    inverse[1][1] = matrix[0][0] / det;

    // Print the inverse matrix
    std::cout << "Inverse matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << inverse[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int n;

    // Read the dimensions of the matrix from the user
    std::cout << "Enter the dimensions of the matrix: ";
    std::cin >> n;

    // Calculate the inverse of the matrix
    inverseMatrix(n);

    return 0;
}
