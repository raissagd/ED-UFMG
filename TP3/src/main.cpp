// main.cpp
#include <iostream>
#include "../include/intArray.hpp"
#include "../include/matrix.hpp"
#include "../include/segTree.hpp"

using namespace std;

int main() {
    // n indicando quantos instantes de tempo
    // q indicando quantas operações serão realizadas
    int n, q;
    cin >> n >> q;

    SegTree segTree(n); // Initialize the segment tree with n leaves
    
    char operation;
    int a, t0, td, x, y;
    unsigned long long m1, m2, m3, m4;

    while (q != 0) {
        cin >> operation;
        if (operation == 'u') {
            // Update operation
            // a é o instante que deve ter sua transformação alterada
            cin >> a;
            cin >> m1 >> m2;
            cin >> m3 >> m4;
            Matrix transform(m1, m2, m3, m4);
            segTree.update(a, transform);
        
            q--;
        } else if (operation == 'q') {
            // Query operation
            // t0 instante de nascimento, td instante de morte  
            // xy coordenadas do ponto
            cin >> t0 >> td >> x >> y;
            IntArray ponto;
            ponto.push_back(x);
            ponto.push_back(y);
            
            // Perform the query from the segment tree to get the transformated matrix
            Matrix transformed = segTree.query(t0, td);

            // Multiply the point by the transformation matrix
            ponto = transformed.multiplyBy1x2(ponto);

            // Print the transformed point
            cout << ponto[0] % 100000000 << " " << ponto[1] % 100000000 << endl;

            q--;
        }
    }

    return 0;
}