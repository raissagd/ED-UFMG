// SegTree.cpp
#include "../include/segTree.hpp"

void SegTree::build(int node, int start, int end) {
    if (start == end) {
        tree[node] = Matrix(); // Initialize leaf with identity matrix
    } else {
        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        tree[node] = tree[node * 2].multiplyBy2x2(tree[node * 2 + 1]); // Combine children
    }
}

SegTree::SegTree(int n) : n(n) {
    int height = (int)(std::ceil(std::log2(n)));
    int max_size = 2 * (int)std::pow(2, height) - 1;
    tree = new Matrix[max_size];
    build(1, 0, n - 1);
}

SegTree::~SegTree() {
    delete[] tree;
}

void SegTree::update(int idx, const Matrix& mat) {
    update(1, 0, n - 1, idx, mat);
}

void SegTree::update(int node, int start, int end, int idx, const Matrix& mat) {
    if (start == end) {
        // Atualiza a matriz folha.
        tree[node] = mat;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            // Se o índice está na metade esquerda, atualize a esquerda.
            update(node * 2, start, mid, idx, mat);
        } else {
            // Se o índice está na metade direita, atualize a direita.
            update(node * 2 + 1, mid + 1, end, idx, mat);
        }
        // Atualiza o nó pai com a nova multiplicação dos filhos.
        tree[node] = tree[node * 2].multiplyBy2x2(tree[node * 2 + 1]);
    }
}

Matrix SegTree::query(int l, int r) const {
    return query(1, 0, n - 1, l, r);
}

Matrix SegTree::query(int node, int start, int end, int l, int r) const {
    if (start > r || end < l) {
        // Retorna uma matriz identidade se o intervalo de consulta não intersecciona com o intervalo do nó.
        return Matrix();
    }
    if (start >= l && end <= r) {
        // Retorna o nó se o intervalo do nó estiver completamente dentro do intervalo de consulta.
        return tree[node];
    }
    // Se o intervalo do nó se sobrepõe parcialmente com o intervalo de consulta, divida mais.
    int mid = (start + end) / 2;
    Matrix p1 = query(node * 2, start, mid, l, r);
    Matrix p2 = query(node * 2 + 1, mid + 1, end, l, r);
    
    // Combina os resultados das duas metades.
    Matrix result;
    if (p1.isDefined()) { // Supondo que Matrix tenha um método isDefined para verificar se não é uma matriz identidade.
        result = result.multiplyBy2x2(p1);
    }
    if (p2.isDefined()) { // Similarmente para a segunda metade.
        result = result.multiplyBy2x2(p2);
    }
    return result;
}