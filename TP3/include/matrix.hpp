// Matrix.hpp
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include "intArray.hpp"

class Matrix {
private:
    IntArray rows[2]; // Array to hold 2 rows of the matrix

public:
    Matrix();
    Matrix(unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long d); 
    void set(int row, int col, unsigned long long value);
    unsigned long long get(int row, int col) const;
    IntArray multiplyBy1x2(const IntArray& mat1x2);
    Matrix multiplyBy2x2(const Matrix& other);
    void print() const; 
    bool isDefined() const;
};

#endif // MATRIX_HPP