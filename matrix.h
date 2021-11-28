#pragma once
#include <map>
#include <vector>

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
            m_parent.m_matrix[{m_row, m_col}] = value;
            return m_parent.m_matrix[{m_row, m_col}];
        }

        bool operator==(const T &value)
        {
            T tmp = Default;
            auto it = m_parent.m_matrix.find({m_row, m_col});
            auto end = m_parent.m_matrix.end();
            if (it != end) {
                tmp = m_parent.m_matrix[{m_row, m_col}];
            }
            return tmp == value;
        }

    private:
        Matrix &m_parent;
        int m_row;
        int m_col;

        MatrixType(Matrix &parent, int row, int col)
            : m_parent(parent)
            , m_row(row)
            , m_col(col)
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

    std::map<std::pair<int, int>, T> m_matrix;

public:

    Matrix() = default;

    Row operator[](int row)
    {
        return Row(*this, row);
    }

    std::size_t size() const
    {
        return m_matrix.size();
    }
};

}
