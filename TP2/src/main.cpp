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
    std::string op = argv[1];  // Operação a ser realizada, informada na linha de comando.
    int numV;
    std::cin >> numV;  // Lendo o número de vértices.
    Graph graph;
    Sort sort(numV);  // Criação do objeto de ordenação.
    Vertix* vertices = new Vertix[numV];  // Alocação dinâmica do array de vértices.

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

    // Ordenar o array de vértices primeiro, de acordo com as cores.
    // O método específico de ordenação é determinado pela opção passada na linha de comando.
    if (op == "-b") {
        sort.bubblesort(vertices, numV);  // Bubble sort.
    } else if (op == "-s") {
        sort.selectionsort(vertices, numV);  // Selection sort.
    } else if (op == "-i") {
        sort.insertionsort(vertices, numV);  // Insertion sort.
    } else if (op == "-q") {
        sort.quicksort(vertices, 0, numV - 1);  // Quicksort.
    } else if (op == "-m") {
        sort.mergesort(vertices, 0, numV - 1);  // Mergesort.
    } else if (op == "-p") {
        sort.heapsort(vertices, numV);  // Heapsort.
    } else if (op == "-y") {
        sort.customsort(vertices, numV);  // Método de ordenação personalizado.
    }

    sort.printVerticesByValue(vertices, numV);  // Imprimir vértices ordenados por valor.

    delete[] vertices;  // Liberando a memória alocada.
    delete[] colors;  // Liberando a memória do array de cores.

    return 0; 
}