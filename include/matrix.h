#pragma once

#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <iterator>

namespace linalg 
{

template <typename DataType>
class Matrix
{
private:
    std::vector<DataType> data;

public:
    size_t rows, columns;

    Matrix() = default;

    Matrix(size_t rows_, size_t columns_);
    
    Matrix(const Matrix& other);

    Matrix transpose();

    Matrix kronecker(const Matrix& other);
    
    DataType& operator () (size_t row, size_t column);
    
    Matrix& operator *= (const Matrix& other);
    
    template <typename DataType_>
    friend Matrix<DataType_> operator * (const Matrix<DataType_>& lhs, const Matrix<DataType_>& rhs); 

    template <typename DataType_>
    friend std::ostream& operator << (std::ostream& os, const Matrix<DataType_>& matrix);
    
    template <typename DataType_>
    friend std::istream& operator >> (std::istream& is, const Matrix<DataType_>& matrix);
    
    template <typename DataType_>
    friend void operator >> (std::vector<DataType_>& vec, const Matrix<DataType_>& matrix);
};

}

