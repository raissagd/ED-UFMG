//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteúdo     : Implementação do arquivo principal
// Autora       : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Histórico    : 28/10/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/graph.hpp"
#include "../include/sort.hpp"
#include <iostream>
#include <string>
#include <sstream> 

int main(int argc, char* argv[]) {
    char op; // Operação
    int numV; // Num de vértices
    std::cin >> op >> numV;    
    
    Graph graph;
    Sort sort(numV);  // Creation of the sorting object.
    Vertix* vertices = new Vertix[numV];  // Dynamic allocation of the vertex array.

    // Inserindo vértices no grafo.
    for (int i = 0; i < numV; ++i) {
        vertices[i].item = i;
        graph.insertVertex();  // Inserir um vértice no grafo.
    }

    // Ler os vizinhos.
    for (int i = 0; i < numV; ++i) {
        int numNeighbors;
        std::cin >> numNeighbors;  // Lendo o número de vizinhos do vértice i.

        // Adicionando arestas para cada vizinho.
        for (int j = 0; j < numNeighbors; ++j) {
            int neighbor;
            std::cin >> neighbor;  // Lendo o identificador do vizinho específico.
            graph.insertEdge(i, neighbor);  // Isso adiciona uma aresta do vértice i para o vértice 'vizinho'.
        }
    }

    int* colors = new int[numV]; 
    for (int i = 0; i < numV; ++i) {
        std::cin >> colors[i];  // Lendo a cor para o vértice 'i'.
    }

    // Definir a cor de cada vértice no grafo.
    for (int i = 0; i < numV; ++i) {
       vertices[i].color = colors[i];
       graph.addColor(i, colors[i]);  
    }

    // Se não for um algoritmo guloso, retorna 0 imediatamente.
    for (int i = 0; i < numV; i++) {
        if (!graph.isGreedy(vertices[i].item, vertices[i].color)) {
            std::cout << 0 << std::endl;  
            delete[] vertices;  
            delete[] colors;  
            return 0;
        }
    }

    // Se o algoritmo é guloso, ordena o array.
    // O método específico de ordenação é determinado pela opção passada na linha de comando.
    sort.method(numV, vertices, op);
    sort.printVerticesByValue(vertices, numV);  // Imprimir vértices ordenados por valor.

    delete[] vertices;  // Liberando a memória alocada.
    delete[] colors;  // Liberando a memória do array de cores.

    return 0; 
}