#include <iostream>
#include <cassert>
#include "matrix.h"

using namespace matrix;

int main(void)
{
    std::cout << "Hello from Matrix" << std::endl;

    Matrix<int, -1> matrix;
    assert(matrix.size() == 0);
    int a = matrix[0][0];
    assert(a == -1);
    matrix[100][100] = 314;
    assert(matrix[100][100] == 314);
    std::cout << matrix.size() << std::endl;
    assert(matrix.size() == 1);

    return 0;
}
