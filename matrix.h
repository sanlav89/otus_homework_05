#pragma once
#include <map>

namespace matrix {

template <typename T, T Default, int Dim = 2>
class Matrix
{
    using itemType = Matrix<T, Default, Dim - 1>;

public:

    itemType& operator[](int idx)
    {
        return m_data[idx];
    }

    const itemType& operator[](int idx) const
    {
        return m_data[idx];
    }

    size_t size() const
    {
        return m_data.size();
    }

private:
    std::map<int, itemType> m_data;
};

template <typename T, T Default>
class Matrix<T, Default, 1>
{
public:
    T& operator[](int idx)
    {
        return m_data[idx];
    }

    const T& operator[](int idx) const
    {
        return m_data[idx];
    }

    size_t size() const
    {
        return m_data.size();
    }

private:
    std::map<int, T> m_data;
};

}
