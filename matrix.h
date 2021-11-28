#pragma once
#include <map>
#include <vector>

namespace matrix {

//    template<typename T, T Default, int Order = 1>
//    class Matrix
//    {

//    private:

//        class Row
//        {
//            friend class Matrix;

//        public:

//            const T &operator[](int col) const
//            {
//                auto it = m_parent.m_matrix.find({m_row, col});
//                auto end = m_parent.m_matrix.end();
//                if (it == end) {
//                    return Default;
//                } else {
//                    return m_parent.m_matrix[{m_row, col}];
//                }
//            }

//            T &operator[](int col)
//            {
//                auto it = m_parent.m_matrix.find({m_row, col});
//                auto end = m_parent.m_matrix.end();
//                if (it == end) {
//                    m_parent.m_matrix.insert({{m_row, col}, -1});
//                }
//                return m_parent.m_matrix[{m_row, col}];
//            }

//        private:
//            Row(Matrix &parent, int row) : m_parent(parent), m_row(row) {}
//            Matrix &m_parent;
//            int m_row;

//        };

//        std::map<std::pair<int, int>, T> m_matrix;

//    public:

//        Matrix() = default;

//        Row operator[](int row)
//        {
//            return Row(*this, row);
//        }

//        std::size_t size() const
//        {
//            return m_matrix.size();
//        }
//    };


//template<typename T>


/**
 * Matrix is a class template that implements a multi-dimensional storage
 * of specific type T. The Container is responsible to how these Ts will
 * be stored and retrieved from memory.
 * This is the general case for dimensions > 1. For the simple case of 1
 * dimension see below.
 */
template <typename T, T Default, int Dim = 2>
class Matrix
{

    typedef Matrix<T, Default, Dim-1> itemType;
    std::map<int, itemType> m_data;

public:
    /**
     * This returns an item of the array m_data which is probably a matrix
     * of less dimensions that can be further accessed be the same operator
     * for resolving another dimension.
     */
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
};

/**
 * This is the simple case of a one-dimensional matrix which is technically
 * an array in its simplest case.
 */
template <typename T, T Default>
class Matrix<T, Default, 1>
{
    /**
     * Here we are defining an array of itemType which is defined to be T.
     * so we are actually defining an array of T.
     */
//    typedef T itemType;

public:

//    class MatrixType
//    {
//        friend class Matrix;

//    public:
//        MatrixType(const T &value) : m_value(value) {}

//    private:

//        MatrixType(Matrix &parent, const T &value)
//            : m_value(value)
//            , m_matrix(parent)
//        {}

//        T m_value;
//        Matrix &m_matrix;
//    };

private:

    std::map<int, T> m_data;

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
};


}
