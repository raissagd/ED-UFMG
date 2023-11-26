#include "../include/segTree.hpp"

SegTree::SegTree(int n) {
    // Find the smallest power of two greater than or equal to n and calculate the size of the segment tree
    int x = ceil(log2(n));
    size = 2 * (int)pow(2, x) - 1;
    length = n;
    tree = new Matrix[size];

    // Initialize the segment tree with identity matrices
    for (int i = 0; i < size; ++i) {
        tree[i] = Matrix(); // Default constructor creates an identity matrix
    }
}

SegTree::~SegTree() {
    delete[] tree;
}

void SegTree::updateTree(int node, int start, int end, int idx, const Matrix& val) {
    if (start == end) {
        tree[node] = val;
    } else {
        int mid = start + (end - start) / 2;
        if (idx >= start && idx <= mid) {
            updateTree(node * 2 + 1, start, mid, idx, val);
        } else {
            updateTree(node * 2 + 2, mid + 1, end, idx, val);
        }
        tree[node] = tree[node * 2 + 1].multiplyBy2x2(tree[node * 2 + 2]);
    }
}

Matrix SegTree::queryTree(int node, int start, int end, int l, int r) const {
    // No overlap
    if (r < start || l > end) {
        return Matrix();  // Return the identity matrix
    }

    // Total overlap
    if (l <= start && end <= r) {
        return tree[node];
    }

    // Partial overlap
    int mid = (start + end) / 2;
    Matrix leftResult = queryTree(node * 2 + 1, start, mid, l, r);
    Matrix rightResult = queryTree(node * 2 + 2, mid + 1, end, l, r);

    // Combine results from both sides, ensuring non-identity matrices are multiplied in the correct order
    if (leftResult.isIdentity()) {
        return rightResult;
    } else if (rightResult.isIdentity()) {
        return leftResult;
    } else {
        return leftResult.multiplyBy2x2(rightResult);
    }
}


void SegTree::update(int idx, const Matrix& val) {
    updateTree(0, 0, length - 1, idx, val); // Starting from root node at index 0
}

Matrix SegTree::query(int l, int r) const {
    return queryTree(0, 0, length - 1, l, r); // Starting from root node at index 0
}

void SegTree::printTree() const {
    int maxNodesAtDepth = 1;
    int indentSpace = 2;
    int currentDepth = 0;
    int nodesAtThisDepth = 0;

    for (int i = 0; i < size; ++i) { // Start from 0
        if (nodesAtThisDepth == maxNodesAtDepth) {
            currentDepth++;
            nodesAtThisDepth = 0;
            maxNodesAtDepth *= 2;
            indentSpace /= 2;
            std::cout << std::endl; // Add a new line for a new level of depth
        }

        std::cout << std::string(indentSpace, ' '); // Indentation for tree structure
        std::cout << "Node " << i << " at depth " << currentDepth << ":" << std::endl;
        tree[i].print(); // Assuming that Matrix::print() is properly formatted
        nodesAtThisDepth++;

        if (i == maxNodesAtDepth - 2) { // Adjusted check for end of depth
            std::cout << std::endl; // Separate the levels visually
        }
    }
}