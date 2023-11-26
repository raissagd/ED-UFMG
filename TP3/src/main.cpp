//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Arquivo principal
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 25/11/2023 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include "../include/intArray.hpp"
#include "../include/matrix.hpp"
#include "../include/segTree.hpp"

using namespace std;

int main() {
    int n, q;  // n indicando quantos instantes de tempo, q indicando quantas operações serão realizadas
    cin >> n >> q;

    SegTree segTree(n); // Inicialização da árvore de segmentos com 'n' folhas
    
    char operation;
    int a, t0, td, x, y;
    unsigned long long m1, m2, m3, m4;

    while (q != 0) {
        cin >> operation;
        if (operation == 'u') {
            // Operação de atualização:
            // 'a' representa o instante de tempo que deve ter sua matriz de transformação alterada
            cin >> a;
            cin >> m1 >> m2;
            cin >> m3 >> m4;
            Matrix transform(m1, m2, m3, m4); // Cria uma nova matriz os valores lidos
            segTree.update(a, transform); // Atualiza o respectivo nó com a matriz passada
            q--;
        } else if (operation == 'q') {
            // Operação de consulta:
            // 't0' representa o instante de nascimento do ponto
            // 'td' representa o instante de morte do ponto
            // 'x' e 'y' são as coordenadas do ponto
            cin >> t0 >> td >> x >> y;
            IntArray point;
            point.push_back(x);
            point.push_back(y);
            
            Matrix transformed = segTree.query(t0, td); // Realiza a consulta na árvore de segmentos para obter a matriz transformada
            point = transformed.multiplyBy2x1(point); // Multiplica o ponto pela matriz de transformação obtida
            point.print();
            q--;
        }
    }
    
    return 0;
}