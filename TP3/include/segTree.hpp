//---------------------------------------------------------------------
// Arquivo      : segTree.hpp
// Conteudo     : Arquivo de cabeçário - Implementação da estrutura da árvore de segmentos
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 25/11/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef SEGTREE_HPP
#define SEGTREE_HPP

#include "matrix.hpp"
#include <cmath>

// Classe SegTree é usada para realizar operações de atualização e consulta de forma eficiente em um intervalo de matrizes
class SegTree {
private:
    Matrix* tree; // Ponteiro para um array que representa a árvore de segmentos
    int size; // Tamanho do array que representa a árvore
    int length; // Número de elementos no array original

    // Método privado para atualizar a árvore de segmentos
    void updateTree(int node, int start, int end, int idx, const Matrix& val);
    // Método privado para consultar um intervalo na árvore de segmentos
    Matrix queryTree(int node, int start, int end, int l, int r) const;

public:
    SegTree(int n); // Construtor que inicializa a árvore de segmentos com n elementos
    ~SegTree(); // Destrutor para desalocar a memória utilizada pela árvore
    // Método para atualizar uma das matrizes na árvore
    void update(int idx, const Matrix& val);
    // Método para consultar um intervalo na árvore de segmentos e retornar o produto das matrizes nesse intervalo
    Matrix query(int l, int r) const;
};

#endif // SEGTREE_HPP