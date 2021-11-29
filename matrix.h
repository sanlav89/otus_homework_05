#pragma once
#include <iostream>
#include <cassert>
#include <map>
#include <vector>
#include <tuple>

namespace matrix {

template<typename T, T Default>
class Matrix
{

private:

    class MatrixType
    {
        friend class Matrix;

    public:

        T &operator=(const T &value)
        {
            if (value != m_default) {
                m_parent.m_matrix[{m_row, m_col}] = value;
                return m_parent.m_matrix[{m_row, m_col}];
            } else {
                return m_default;
            }
        }

        bool operator==(const T &value)
        {
            return find() == value;
        }

        friend std::ostream& operator<<(std::ostream& os, const MatrixType& mt)
        {
            os << mt.find();
            return os;
        }

    private:
        Matrix &m_parent;
        int m_row;
        int m_col;
        T m_default;

        T find() const
        {
            T tmp = m_default;
            auto it = m_parent.m_matrix.find({m_row, m_col});
            auto end = m_parent.m_matrix.end();
            if (it != end) {
                tmp = m_parent.m_matrix[{m_row, m_col}];
            }
            return tmp;
        }

        MatrixType(Matrix &parent, int row, int col)
            : m_parent(parent)
            , m_row(row)
            , m_col(col)
            , m_default(Default)
        {}
    };


    class Row
    {
        friend class Matrix;
    public:

        MatrixType operator[](int col)
        {
            return MatrixType(m_parent, m_row, col);
        }

    private:
        Row(Matrix &parent, int row) : m_parent(parent), m_row(row) {}
        Matrix &m_parent;
        int m_row;

    };

    std::map<std::vector<int>, T> m_matrix;

public:

    using map_iter = typename std::map<std::vector<int>, T>::iterator;

    // Iterator Class
    class iterator {
    public:
        iterator() : m_it(map_iter(nullptr)) {}

        iterator(map_iter it) : m_it(it) {}

        bool operator==(const iterator& other) const
        {
            return m_it == other.m_it;
        }

        bool operator!=(const iterator& other) const
        {
            return !(*this == other);
        }

        std::tuple<int, int, T> operator*() const
        {
            return std::make_tuple((*m_it).first.at(0),
                                   (*m_it).first.at(1),
                                   (*m_it).second);
        }

        iterator& operator++()
        {
            ++m_it;
            return *this;
        }

    private:
        map_iter m_it;
    };

    Matrix() = default;

    Row operator[](int row)
    {
        return Row(*this, row);
    }

    std::size_t size() const
    {
        return m_matrix.size();
    }

    iterator begin()
    {
        return iterator(m_matrix.begin());
    }

    iterator end()
    {
        return iterator(m_matrix.end());
    }
};

// Task Example
void example()
{
    // Example

    std::cout << "Example: " << std::endl;

    Matrix<int, -1> matrix;
    assert(matrix.size() == 0);
    auto a = matrix[0][0];
    assert(a == -1);
    assert(matrix.size() == 0);
    matrix[100][100] = 314;
    assert(matrix[100][100] == 314);
    assert(matrix.size() == 1);
    // выведется одна строка
    // 100100314
    for (auto c : matrix) {
        int x;
        int y;
        int v;
        std::tie(x, y, v) = c;
        std::cout << x << y << v << std::endl;
    }

    ((matrix[100][100] = 314) = 0) = 217;
    assert(matrix[100][100] == 217);

    std::cout << std::endl;
}

}
