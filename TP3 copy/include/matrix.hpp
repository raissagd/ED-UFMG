//---------------------------------------------------------------------
// Arquivo      : matrix.hpp
// Conteudo     : Arquivo de cabeçário - classe para representar as matrizes
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 25/11/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include "intArray.hpp"

// Classe Matrix representa uma matriz 2x2
class Matrix {
private:
    IntArray rows[2]; // Vetor que contém as 2 linhas da matriz

public:
    Matrix(); // Construtor padrão que cria uma matriz identidade 2x2
    Matrix(unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long d); // Construtor que inicializa a matriz com valores específicos
    void set(int row, int col, unsigned long long value); // Define o valor de uma posição específica da matriz
    unsigned long long get(int row, int col) const; // Obtém o valor de uma posição específica da matriz
    IntArray multiplyBy2x1(const IntArray& mat2x1); // Multiplica a matriz por um vetor coluna 2x1
    Matrix multiplyBy2x2(const Matrix& other); // Multiplica a matriz por outra matriz 2x2
    bool isIdentity() const; // Verifica se a matriz é a matriz identidade
    Matrix(const Matrix& other); // Construtor de cópia
    Matrix& operator=(const Matrix& other); // Sobrecarga do operador de atribuição
};

#endif // MATRIX_HPP