#include <iostream>

#define UNUSED(value) (void)value

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
    foo<int> f;
    f[10] = 0;
    auto a = f[10];

//  output:
//    T& foo<T>::operator[](int) [with T = int]
//    T& foo<T>::operator[](int) [with T = int]

    UNUSED(a);

    return 0;
}
