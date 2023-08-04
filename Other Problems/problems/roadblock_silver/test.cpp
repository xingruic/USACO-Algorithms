
#include <iostream>
#include <algorithm>
#include <iomanip>

template<typename T, size_t N, size_t M>
void printMatrix(T(&mat)[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << std::setw(2) << mat[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    const int m = 3, n = 3;

    int mat[m][n] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int copy[m][n];
    std::copy(&mat[0][0], &mat[0][0] + m * n, &copy[0][0]);
    printMatrix(copy);

    return 0;
}