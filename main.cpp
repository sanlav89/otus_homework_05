#include <iostream>
#include <cassert>
#include "matrix.h"

#define UNUSED(value) (void)value

using namespace matrix;

template<typename T>
class foo
{
public:
    foo() = default;

    const T &operator[](int) const
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return tmp;
    }

    T &operator[](int)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return tmp;
    }

private:
    T tmp;
};

int main(void)
{
//    std::cout << "Hello from Matrix" << std::endl;

//    Matrix<int, -1> matrix;
//    assert(matrix.size() == 0);
//    int a = matrix[0][0];
//    assert(a == -1);
//    matrix[100][100] = 314;
//    assert(matrix[100][100] == 314);
//    std::cout << matrix.size() << std::endl;
//    assert(matrix.size() == 1);


    foo<int> f;
    f[10] = 0;
    auto a = f[10];
    UNUSED(a);

    return 0;
}
