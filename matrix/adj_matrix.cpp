#include <iostream>

void getCofactor(int mat[10][10], int temp[10][10], int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int mat[10][10], int n) {
    int D = 0;
    if (n == 1)
        return mat[0][0];

    int temp[10][10];
    int sign = 1;
    for (int f = 0; f < n; f++) {
        getCofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return D;
}

void adjoint(int mat[10][10], int adj[10][10], int N) {
    if (N == 1) {
        adj[0][0] = 1;
        return;
    }
    int sign = 1, temp[10][10];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            getCofactor(mat, temp, i, j, N);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (determinant(temp, N - 1));
        }
    }
}

int main() {
    int mat[10][10], adj[10][10];
    int N;
    std::cout << "Enter the order of the matrix: ";
    std::cin >> N;
    std::cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> mat[i][j];

    adjoint(mat, adj, N);

    std::cout << "The Adjoint is :\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            std::cout << adj[i][j] << " ";
        std::cout << "\n";
    }
    return 0;
}