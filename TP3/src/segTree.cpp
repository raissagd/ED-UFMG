//---------------------------------------------------------------------
// Arquivo      : segTree.cpp
// Conteudo     : Implementação de segTree.hpp
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 25/11/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/segTree.hpp"

// Construtor da árvore: inicializa a árvore com matrizes identidade
SegTree::SegTree(int n) {
    int x = ceil(log2(n)); // Encontra a menor potência de dois maior ou igual a n
    size = 2 * (int)pow(2, x) - 1; // Calcula o tamanho necessário para o array da árvore
    length = n; // Define o número de elementos no array original
    tree = new Matrix[size]; // Aloca memória para a árvore

    // Inicializa a árvore de segmentos com matrizes identidade
    for (int i = 0; i < size; ++i) {
        tree[i] = Matrix();
    }
}

// Destrutor da árvore: libera a memória alocada pela árvore
SegTree::~SegTree() {
    delete[] tree;
}

// Método para atualizar um nó na árvore de segmentos
void SegTree::updateTree(int node, int start, int end, int idx, const Matrix& val) {
    // Atualiza o nó se este for o final do intervalo
    if (start == end) {
        tree[node] = val;
    } else {
        // Caso contrário, atualiza o filho apropriado e depois o nó atual
        int mid = start + (end - start) / 2; // Calcula o ponto médio do intervalo
        if (idx >= start && idx <= mid) {
            // Atualiza o filho da esquerda se o índice estiver na metade esquerda
            updateTree(node * 2 + 1, start, mid, idx, val);
        } else {
            // Atualiza o filho da direita se o índice estiver na metade direita
            updateTree(node * 2 + 2, mid + 1, end, idx, val);
        }
        // Atualiza o nó atual como o produto das matrizes de seus filhos
        tree[node] = tree[node * 2 + 1].multiplyBy2x2(tree[node * 2 + 2]);
    }
}

// Método para consultar um intervalo na árvore de segmentos e retornar o produto das matrizes
Matrix SegTree::queryTree(int node, int start, int end, int l, int r) const {
    // Verifica se não há sobreposição
    if (r < start || l > end) {
        return Matrix();  // Retorna a matriz identidade se não houver sobreposição
    }

    // Verifica se há sobreposição total
    if (l <= start && end <= r) {
        return tree[node];
    }

    // Se houver sobreposição parcial, consulta ambos os filhos e combina os resultados
    int mid = (start + end) / 2;
    Matrix leftResult = queryTree(node * 2 + 1, start, mid, l, r);
    Matrix rightResult = queryTree(node * 2 + 2, mid + 1, end, l, r);

    // Combina os resultados dos filhos, garantindo que as matrizes não identidade sejam multiplicadas na ordem correta
    if (leftResult.isIdentity()) {
        return rightResult;
    } else if (rightResult.isIdentity()) {
        return leftResult;
    } else {
        return leftResult.multiplyBy2x2(rightResult);
    }
}

// Método para atualizar uma das matrizes
void SegTree::update(int idx, const Matrix& val) {
    // Começa a atualização pelo nó raiz, que está no índice 0
    updateTree(0, 0, length - 1, idx, val);
}

// Método para consultar um intervalo na árvore de segmentos e retornar o produto das matrizes nesse intervalo
Matrix SegTree::query(int l, int r) const {
    // Começa a consulta pelo nó raiz, que está no índice 0
    return queryTree(0, 0, length - 1, l, r);
}