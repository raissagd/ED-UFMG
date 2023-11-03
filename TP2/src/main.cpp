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

void readGraph(Graph &graph, Vertix* vertices, int numV) {
    // Inserção dos vértices no grafo.
    for (int i = 0; i < numV; ++i) {
        vertices[i].item = i;
        graph.insertVertex();
    }

    // Leitura das arestas do grafo.
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
}

void readAndAssignColors(Graph &graph, Vertix* vertices, int numV) {
    int* colors = new int[numV];
    for (int i = 0; i < numV; ++i) {
        std::cin >> colors[i];  // Lendo a cor para o vértice 'i'.
    }

    // Definindo a cor de cada vértice no grafo.
    for (int i = 0; i < numV; ++i) {
       vertices[i].color = colors[i];
       graph.addColor(i, colors[i]);
    }
    
    delete[] colors;  // Liberando a memória do array de cores.
}

int main(int argc, char* argv[]) {
    char op; // Operação a ser realizada
    int numV; // Número de vértices
    std::cin >> op >> numV;    
    
    Graph graph;
    Sort sort(numV);  // Criação do objeto de ordenação.
    Vertix* vertices = new Vertix[numV];  // Alocação dinâmica do array de vértices.

    readGraph(graph, vertices, numV); // Lê a estrutura do grafo a partir da entrada
    readAndAssignColors(graph, vertices, numV); // Lê e atribui cores aos vértices

    // Se o algoritmo não é guloso, já retorna 0.
    for (int i = 0; i < numV; i++) {
        if (!graph.isGreedy(vertices[i].item, vertices[i].color)) {
            std::cout << 0 << std::endl;  
            delete[] vertices;  // Liberando a memória alocada para os vértices.
            return 0;
        }
    }

    // Se o algoritmo for guloso, ordena o array com base no argumento da linha de comando.
    sort.method(numV, vertices, op);
    sort.printVerticesByValue(vertices, numV);  // Imprime os vértices ordenados.
    delete[] vertices;  // Liberando a memória alocada.

    return 0; 
}