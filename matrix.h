#pragma once
#include <iostream>
#include <cassert>
#include <map>
#include <vector>
#include <tuple>

namespace matrix {

template<typename T, T Default, int Dimension = 2>
class Matrix
{

private:

    class SubMatrix
    {
        friend class Matrix;
    public:

        SubMatrix operator[](int idx)
        {
            assert(m_idx.size() < Dimension);
            return SubMatrix(*this, idx);
        }

        T &operator=(const T &value)
        {
            assert(m_idx.size() == Dimension);
            if (value != m_default) {
                m_parent.m_matrix[m_idx] = value;
                return m_parent.m_matrix[m_idx];
            } else {
                return m_default;
            }
        }

        bool operator==(const T &value)
        {
            return find() == value;
        }

        friend std::ostream& operator<<(std::ostream& os, const SubMatrix& mt)
        {
            os << mt.find();
            return os;
        }

    private:
        SubMatrix(Matrix &parent, int idx)
            : m_parent(parent)
            , m_idx({idx})
            , m_default(Default)
        {}

        SubMatrix(const SubMatrix &other, int idx)
            : m_parent(other.m_parent)
            , m_idx(other.m_idx)
            , m_default(Default)
        {
            m_idx.push_back(idx);
        }

        T find() const
        {
            T tmp = m_default;
            auto it = m_parent.m_matrix.find(m_idx);
            auto end = m_parent.m_matrix.end();
            if (it != end) {
                tmp = m_parent.m_matrix[m_idx];
            }
            return tmp;
        }

        Matrix &m_parent;
        std::vector<int> m_idx;
        T m_default;

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
            assert((*m_it).first.size() == 2);
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

    SubMatrix operator[](int row)
    {
        return SubMatrix(*this, {row});
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
void example(std::ostream &os = std::cout)
{
    os << "Example: " << std::endl;

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
        os << x << y << v << std::endl;
    }

    os << std::endl;
}

}
