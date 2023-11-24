// Matrix.cpp
#include "../include/matrix.hpp"
#include <stdexcept>

Matrix::Matrix() {
    // Initialize the matrix as 2x2 identity matrix
    rows[0].push_back(1);
    rows[0].push_back(0);
    rows[1].push_back(0);
    rows[1].push_back(1);
}

Matrix::Matrix(unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long d) {
    // Initialize the matrix with provided values
    rows[0].push_back(a);
    rows[0].push_back(b);
    rows[1].push_back(c);
    rows[1].push_back(d);
}

void Matrix::set(int row, int col, unsigned long long value) {
    if (row < 0 || row > 1 || col < 0 || col > 1) {
        throw std::out_of_range("Index out of range");
    }
    rows[row][col] = value;
}

unsigned long long Matrix::get(int row, int col) const {
    if (row < 0 || row > 1 || col < 0 || col > 1) {
        throw std::out_of_range("Index out of range");
    }
    return rows[row][col];
}

IntArray Matrix::multiplyBy1x2(const IntArray& mat1x2) {
    if (mat1x2.size() != 2) {
        throw std::invalid_argument("Invalid matrix size for multiplication");
    }
    IntArray result;
    for (int j = 0; j < 2; ++j) {
        unsigned long long sum = 0;
        for (int k = 0; k < 2; ++k) {
            sum += mat1x2[k] * get(k, j);
        }
        result.push_back(sum);
    }
    return result;
}

Matrix Matrix::multiplyBy2x2(const Matrix& other) {
    Matrix result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            unsigned long long sum = 0; // Changed from int to unsigned long long
            for (int k = 0; k < 2; ++k) {
                sum += get(i, k) * other.get(k, j);
            }
            result.set(i, j, sum);
        }
    }
    return result; 
}

void Matrix::print() const {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << rows[i][j] << (j < 1 ? " " : "\n");
        }
    }
}

bool Matrix::isDefined() const {
    // Check if the matrix is the identity matrix
    return !(rows[0][0] == 1 && rows[0][1] == 0 &&
             rows[1][0] == 0 && rows[1][1] == 1);
}