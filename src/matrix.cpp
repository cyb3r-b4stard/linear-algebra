#include "matrix.h"

namespace linalg
{

template <typename DataType>
Matrix<DataType>::Matrix(size_t n_, size_t m_)
    : rows{n_}, columns{m_}, data{std::vector<DataType>{rows, columns}}
{}

template <typename DataType>
Matrix<DataType>::Matrix(const Matrix& other)
    : rows{other.rows}, columns{other.columns}, data{std::vector<DataType>{rows, columns}}
{
    std::copy(other.data.begin(), other.data.end(), data.begin());
}

template <typename DataType>
Matrix<DataType> Matrix<DataType>::transpose() {
    Matrix result{rows, columns};

    for (size_t i = 0; i < rows * columns; ++i) {
        result.data[i] = data[size_t(rows / i) + i * columns];
    }

    return std::move(result);
}

template <typename DataType>
Matrix<DataType> Matrix<DataType>::kronecker(const Matrix& other) {
    Matrix<DataType> result{this->rows * other.rows, this->columns * other.columns};

    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->columns; ++j) {
            for (size_t m = 0; m < other.rows; ++m) {
                for (size_t n = 0; n < other.columns; ++n) {
                    result(i * other.rows + m, j * other.columns + n) = *this(i, j) * other(m, n);
                }
            }
        }
    }
    
    return std::move(result);
}

template <typename DataType>
DataType& Matrix<DataType>::operator () (size_t row, size_t column) {
    return data[row * columns + column];
}

template <typename DataType>
Matrix<DataType>& Matrix<DataType>::operator *= (const Matrix& other) {
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < other.columns; ++j) {
            size_t new_value {0};
            
            for (size_t k = 0; k < this->columns; ++k) {
                new_value += *this(i, j) * other(i, j);
            }

            *this(i, j) = new_value;
        }
    }
    return *this;
}

template <typename DataType>
Matrix<DataType> operator * (const Matrix<DataType>& lhs, const Matrix<DataType>& rhs) {
    Matrix<DataType> result {lhs.rows, rhs.columns};
    
    lhs *= rhs;

    return std::move(result);
} 

template <typename DataType>
std::ostream& operator << (std::ostream& os, const Matrix<DataType>& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        // os << '|';
        for (size_t j = 0; j < matrix.columns; ++j) {
            os << matrix(i, j) << ' ';
        }
        // os << '|' << '\n';
    }

    return os;
}

template <typename DataType>
std::istream& operator >> (std::istream& is, const Matrix<DataType>& matrix) {
    std::copy(std::istream_iterator<DataType>(is),
                std::istream_iterator<DataType>(),
                matrix.data.begin());
    return is;
}

template <typename DataType>
void operator >> (std::vector<DataType>& vec, const Matrix<DataType>& matrix) {
    std::copy(vec.begin(),
                vec.end(),
                matrix.data.begin());
}

}

