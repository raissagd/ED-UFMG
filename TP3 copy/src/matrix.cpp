//---------------------------------------------------------------------
// Arquivo      : matrix.cpp
// Conteudo     : Implementação de matrix.hpp
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 25/11/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/matrix.hpp"
#include <stdexcept>

// Construtor padrão que inicializa a matriz como uma matriz identidade 2x2
Matrix::Matrix() {
    rows[0].push_back(1);
    rows[0].push_back(0);
    rows[1].push_back(0);
    rows[1].push_back(1);
}

// Construtor que inicializa a matriz com valores dados para cada posição
Matrix::Matrix(unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long d) {
    rows[0].push_back(a);
    rows[0].push_back(b);
    rows[1].push_back(c);
    rows[1].push_back(d);
}

// Define o valor em uma posição específica da matriz
void Matrix::set(int row, int col, unsigned long long value) {
    if (row < 0 || row > 1 || col < 0 || col > 1) {
        throw std::out_of_range("Index out of range"); // Lança exceção se o índice estiver fora do intervalo
    }
    rows[row][col] = value;
}

// Obtém o valor em uma posição específica da matriz
unsigned long long Matrix::get(int row, int col) const {
    if (row < 0 || row > 1 || col < 0 || col > 1) {
        throw std::out_of_range("Index out of range"); // Lança exceção se o índice estiver fora do intervalo
    }
    return rows[row][col];
}

// Multiplica a matriz atual por outra matriz 2x2
Matrix Matrix::multiplyBy2x2(const Matrix& other) {
    Matrix result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            unsigned long long sum = 0;
            for (int k = 0; k < 2; ++k) {
                sum = (sum + (this->get(i, k) * other.get(k, j)) % 100000000) % 100000000; // Aplica módulo a cada etapa para prevenir overflow
            }
            result.set(i, j, sum);
        }
    }
    return result;
}

// Multiplica a matriz 2x2 por um vetor coluna 2x1
IntArray Matrix::multiplyBy2x1(const IntArray& mat2x1) {
    if (mat2x1.size() != 2) {
        throw std::invalid_argument("Invalid vector size for multiplication"); // Lança exceção se o tamanho do vetor não for compatível
    }
    IntArray result;
    for (int i = 0; i < 2; ++i) {
        unsigned long long sum = 0;
        for (int j = 0; j < 2; ++j) {
            sum = (sum + (this->get(i, j) * mat2x1[j]) % 100000000) % 100000000; // Aplica módulo a cada etapa para prevenir overflow
        }
        result.push_back(sum);
    }
    return result;
}

// Verifica se a matriz é a matriz identidade
bool Matrix::isIdentity() const {
    return rows[0][0] == 1 && rows[0][1] == 0 &&
           rows[1][0] == 0 && rows[1][1] == 1;
}

// Construtor de cópia
Matrix::Matrix(const Matrix& other) {
    rows[0] = other.rows[0];
    rows[1] = other.rows[1];
}

// Sobrecarga do operador de atribuição
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        rows[0] = other.rows[0];
        rows[1] = other.rows[1];
    }
    return *this;
}