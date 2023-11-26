// SegTree.hpp
#ifndef SEGTREE_HPP
#define SEGTREE_HPP

#include "matrix.hpp"
#include <cmath>

class SegTree {
private:
    Matrix* tree; // Array to represent the segment tree
    int size; // Size of the segment tree array
    int length; // Number of elements in the original array

    void updateTree(int node, int start, int end, int idx, const Matrix& val);
    Matrix queryTree(int node, int start, int end, int l, int r) const;

public:
    SegTree(int n);
    ~SegTree();
    void update(int idx, const Matrix& val);
    Matrix query(int l, int r) const;
    void printTree() const;
};

#endif // SEGTREE_HPP