// MatrixHistory.hpp
#ifndef MATRIX_HISTORY_HPP
#define MATRIX_HISTORY_HPP

#include <vector>
#include "matrix.hpp"

class MatrixHistory {
private:
    std::vector<Matrix> transformations;

public:
    explicit MatrixHistory(int n);
    void update(int time, const Matrix& matrix);
    Matrix query(int start, int end) const;
};

#endif // MATRIX_HISTORY_HPP