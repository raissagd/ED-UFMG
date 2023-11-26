// main.cpp
#include <iostream>
#include "../include/intArray.hpp"
#include "../include/matrix.hpp"
#include "../include/segTree.hpp"

using namespace std;

int main() {
    // Assuming n is the number of matrices/time instants
    int n = 4; 
    SegTree segTree(n);
    segTree.printTree();

    cout << "----------------------------------" << endl;

    // Update the matrix at position 2 (3rd position, 0-indexed) in the tree
    Matrix newMatrix(1, 2, 3, 4); // The new matrix to replace at index 2
    segTree.update(2, newMatrix); // Update the tree at index 2 with newMatrix
    segTree.printTree();

    return 0;
}