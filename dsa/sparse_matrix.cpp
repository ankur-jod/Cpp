#include <iostream>

const int MAX_SIZE = 100;

int main() {
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    int sparseMatrix[MAX_SIZE][3];
    int count = 0;

    // Input the matrix elements
    std::cout << "Enter the matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int element;
            std::cin >> element;

            if (element != 0) {
                sparseMatrix[count][0] = i;
                sparseMatrix[count][1] = j;
                sparseMatrix[count][2] = element;
                count++;
            }
        }
    }

    // Display the sparse matrix
    std::cout << "Sparse Matrix:\n";
    for (int i = 0; i < count; i++) {
        std::cout << sparseMatrix[i][0] << " "
                << sparseMatrix[i][1] << " "
                << sparseMatrix[i][2] << "\n";
    }

    return 0;
}