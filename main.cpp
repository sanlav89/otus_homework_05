#include "matrix.h"

using namespace matrix;

int main(void)
{
    // Example
//    example();

    // Task
    const auto matrix_size = 10;
    const auto min_index = 1;
    const auto max_index = 8;

    Matrix<int, 0> matrix;
    for (auto i = 0; i < matrix_size; i++) {
        matrix[i][i] = i;
        matrix[i][matrix_size - (i + 1)] = matrix_size - (i + 1);
    }

    std::cout << "Matrix from [" << min_index << "," << min_index << "] to ["
              << max_index << "," << max_index << "]" << std::endl;
    for (auto i = min_index; i <= max_index; i++) {
        for (auto j = min_index; j <= max_index; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Size:" << matrix.size() << std::endl;
    std::cout << "Filled elements:" << std::endl;

    for (auto c : matrix) {
        int x;
        int y;
        int v;
        std::tie(x, y, v) = c;
        std::cout << "(" << x << "," << y << ") = " << v << std::endl;
    }

    std::cout << "Canonical :" << std::endl;
    std::cout << "((matrix[100][100] = 314) = 0) = 217;" << std::endl;
    ((matrix[100][100] = 314) = 0) = 217;
    std::cout << "(" << 100 << "," << 100 << ") = " << matrix[100][100] << std::endl;

    return 0;
}
