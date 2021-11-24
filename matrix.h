#pragma once
#include <map>
#include <vector>

namespace matrix {

    template<typename T, T Default, int Order = 1>
    class Matrix
    {

    private:

        class Row
        {
            friend class Matrix;

        public:

            const T &operator[](int col) const
            {
                auto it = m_parent.m_matrix.find({m_row, col});
                auto end = m_parent.m_matrix.end();
                if (it == end) {
                    return Default;
                } else {
                    return m_parent.m_matrix[{m_row, col}];
                }
            }

            T &operator[](int col)
            {
                auto it = m_parent.m_matrix.find({m_row, col});
                auto end = m_parent.m_matrix.end();
                if (it == end) {
                    m_parent.m_matrix.insert({{m_row, col}, -1});
                }
                return m_parent.m_matrix[{m_row, col}];
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
