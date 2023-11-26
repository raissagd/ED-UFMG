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

// In Matrix::multiplyBy2x2
Matrix Matrix::multiplyBy2x2(const Matrix& other) {
    Matrix result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            unsigned long long sum = 0;
            for (int k = 0; k < 2; ++k) {
                sum = (sum + (this->get(i, k) * other.get(k, j)) % 100000000) % 100000000;
            }
            result.set(i, j, sum);
        }
    }
    return result;
}

// This function will now multiply a 2x2 matrix by a 2x1 vector.
IntArray Matrix::multiplyBy2x1(const IntArray& mat2x1) {
    if (mat2x1.size() != 2) {
        throw std::invalid_argument("Invalid vector size for multiplication");
    }
    IntArray result;
    for (int i = 0; i < 2; ++i) {
        unsigned long long sum = 0;
        for (int j = 0; j < 2; ++j) {
            sum = (sum + (this->get(i, j) * mat2x1[j]) % 100000000) % 100000000;
        }
        result.push_back(sum);
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

bool Matrix::isIdentity() const {
    return rows[0][0] == 1 && rows[0][1] == 0 &&
           rows[1][0] == 0 && rows[1][1] == 1;
}

Matrix::Matrix(const Matrix& other) {
    rows[0] = other.rows[0];
    rows[1] = other.rows[1];
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        rows[0] = other.rows[0];
        rows[1] = other.rows[1];
    }
    return *this;
}