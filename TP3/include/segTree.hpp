// SegTree.hpp
#ifndef SEGTREE_HPP
#define SEGTREE_HPP

#include <cmath>
#include "matrix.hpp" // Ensure you include the path to your Matrix class header

class SegTree {
private:
    Matrix* tree; // Pointer to array containing the segment tree
    int n; // Number of leaves, which are the power of 2

    void build(int node, int start, int end);
    void update(int node, int start, int end, int idx, const Matrix& mat);
    Matrix query(int node, int start, int end, int l, int r) const;

public:
    SegTree(int n);
    ~SegTree();
    void update(int idx, const Matrix& mat);
    Matrix query(int l, int r) const;
};

#endif // SEGTREE_HPP
