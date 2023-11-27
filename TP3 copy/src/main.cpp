//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Arquivo principal
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 25/11/2023 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <chrono>
#include "../include/intArray.hpp"
#include "../include/matrix.hpp"
#include "../include/matrixVector.hpp"
#include "../include/segTree.hpp"

using namespace std;
using namespace std::chrono;

int main() {
    int n, q;  // n indicando quantos instantes de tempo, q indicando quantas operações serão realizadas
    cin >> n >> q;

    SegTree segTree(n); // Inicialização da árvore de segmentos com 'n' folhas
    
    char operation;
    int a, t0, td, x, y;
    unsigned long long m1, m2, m3, m4;

    // Variáveis para acumular o tempo de atualização e consulta
    duration<double> total_update_time(0);
    duration<double> total_query_time(0);

    while (q--) {
        cin >> operation;
        if (operation == 'u') {
            // Operação de atualização:
            cin >> a >> m1 >> m2 >> m3 >> m4;
            Matrix transform(m1, m2, m3, m4);

            auto start = high_resolution_clock::now();
            segTree.update(a, transform); // Atualiza o respectivo nó com a matriz passada
            auto end = high_resolution_clock::now();

            total_update_time += end - start;

        } else if (operation == 'q') {
            // Operação de consulta:
            cin >> t0 >> td >> x >> y;
            IntArray point;
            point.push_back(x);
            point.push_back(y);

            auto start = high_resolution_clock::now();
            Matrix transformed = segTree.query(t0, td); // Realiza a consulta na árvore de segmentos para obter a matriz transformada
            point = transformed.multiplyBy2x1(point);
            auto end = high_resolution_clock::now();

            point.print();

            total_query_time += end - start;
        }
    }

    // Exibir tempos acumulados
    cout << "Tempo total de atualização: " << total_update_time.count() << " segundos" << endl;
    cout << "Tempo total de consulta: " << total_query_time.count() << " segundos" << endl;
    
    return 0;
}