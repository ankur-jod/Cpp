#include <iostream>

// Function to calculate the determinant of a matrix
int determinant(int** matrix, int size) {
    int det = 0;
    
    // Base case for 2x2 matrix
    if (size == 2) {
        det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    else {
        for (int i = 0; i < size; i++) {
            // Create submatrix
            int** submatrix = new int*[size - 1];
            for (int j = 0; j < size - 1; j++) {
                submatrix[j] = new int[size - 1];
            }
            
            // Fill submatrix
            for (int j = 1; j < size; j++) {
                int k = 0;
                for (int l = 0; l < size; l++) {
                    if (l != i) {
                        submatrix[j - 1][k++] = matrix[j][l];
                    }
                }
            }
            
            // Calculate determinant recursively
            det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant(submatrix, size - 1);
            
            // Delete submatrix
            for (int j = 0; j < size - 1; j++) {
                delete[] submatrix[j];
            }
            delete[] submatrix;
        }
    }
    
    return det;
}

int main() {
    int size;
    std::cout << "Enter the size of the matrix: ";
    std::cin >> size;
    
    // Create matrix
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }
    
    // Fill matrix
    std::cout << "Enter the elements of the matrix:" << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cin >> matrix[i][j];
        }
    }
    
    // Calculate determinant
    int det = determinant(matrix, size);
    
    // Display result
    std::cout << "Determinant: " << det << std::endl;
    
    // Delete matrix
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}
