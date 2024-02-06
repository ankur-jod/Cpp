#include <iostream>

void transposeMatrix(int** matrix, int** transposed, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rows, cols;

    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    std::cout << "Enter the number of columns: ";
    std::cin >> cols ;

    int** matrix = new int*[rows];
    int** transposedMatrix = new int*[cols];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        transposedMatrix[i] = new int[rows];
    }

    std::cout << "Enter the elements of the matrix:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }

    transposeMatrix(matrix, transposedMatrix, rows, cols);

    std::cout << "Transposed matrix:" << std::endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            std::cout << transposedMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Deallocate memory
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
        delete[] transposedMatrix[i];
    }
    delete[] matrix;
    delete[] transposedMatrix;

    return 0;
}
