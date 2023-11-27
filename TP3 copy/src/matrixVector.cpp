#include <vector>
#include "../include/matrixVector.hpp"
#include "../include/matrix.hpp"

MatrixHistory::MatrixHistory(int n) {
    // Inicializa o vetor com matrizes identidade
    for (int i = 0; i < n; ++i) {
        transformations.push_back(Matrix());
    }
}

void MatrixHistory::update(int time, const Matrix& matrix) {
    if (time >= 0 && time < transformations.size()) {
        transformations[time] = matrix;
    } else {
        // Lançar exceção ou lidar com erro de índice inválido
    }
}

Matrix MatrixHistory::query(int start, int end) const {
    Matrix result;
    // Começar com a matriz identidade
    if (start >= 0 && start < transformations.size() && end >= start && end < transformations.size()) {
        result = Matrix(); // Assume-se que o construtor padrão cria uma matriz identidade

        for (int i = start; i <= end; ++i) {
            result = result.multiplyBy2x2(transformations[i]);
        }
    } else {
        // Lançar exceção ou lidar com erro de índice inválido
    }
    return result;
}
