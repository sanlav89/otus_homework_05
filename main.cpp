#include <iostream>
#include <cassert>
#include "matrix.h"

using namespace matrix;

#define UNUSED(value) (void)value

int main(void)
{
    Matrix<int, -1> matrix;
    assert(matrix.size() == 0);
    auto a = matrix[0][0];
    assert(a == -1);
    assert(matrix.size() == 0); // Уже здесь ошибка
    matrix[100][100] = 314;
    assert(matrix[100][100] == 314);
    assert(matrix.size() == 1);   // size = 2

    return 0;
}
