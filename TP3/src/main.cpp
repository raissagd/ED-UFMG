// main.cpp
#include <iostream>
#include "../include/intArray.hpp"
#include "../include/matrix.hpp"
#include "../include/segTree.hpp"

using namespace std;

int main() {
    // Assuming n is the number of matrices/time instants
    int n = 3; 
    SegTree segTree(n);
    segTree.printTree();

    cout << "----------------------------------" << endl;

    // Update the matrix at position 2 (3rd position, 0-indexed) in the tree
    Matrix newMatrix(0, 1, 1, 0); // The new matrix to replace at index 2
    segTree.update(0, newMatrix); // Update the tree at index 2 with newMatrix
    //segTree.printTree();

    cout << "----------------------------------" << endl;
    IntArray ponto;
    ponto.push_back(5);
    ponto.push_back(7);

    int l = 0; // Query start index
    int r = 2; // Query end index
    Matrix queryResult = segTree.query(l, r);
    IntArray result = queryResult.multiplyBy1x2(ponto);
    result.print();
    
    return 0;
}