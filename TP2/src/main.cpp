//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Implementacao do arquivo principal
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 28/10/2023 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "../include/linkedList.hpp"
#include "../include/sort.hpp"
#include "../include/graph.hpp"

Graph* readGraph(int numVertices) {
    Graph* g;

    // Insert the vertices in the graph
    for (int i = 0; i < numVertices; ++i) {
        g->addV();
    }

    // Reading the neighbors
    for (int i = 0; i < numVertices; ++i) {
        int numNeighbours;
        std::cin >> numNeighbours;
        for (int j = 0; j < numNeighbours; ++j) {
            int neighbour;
            std::cin >> neighbour;
            g->addEdge(i, neighbour);

        }
    }
    return g;
}

int main(int argc, char* argv[]) {
    if (argc < 2 || (std::string(argv[1]) != "-n" && std::string(argv[1]) != "-d" && std::string(argv[1]) != "-k")) {
        std::cerr << "Usage: " << argv[0] << " <operation> [-n|-d|-k]\n";
        return 1;
    }

    // Check the operation to be performed
    std::string op = argv[1];
    int numV;
    scanf("%d", &numV);
    

    // Wait for graph input before proceeding
    Graph* g = readGraph(numV);

    // Lendo as cores para cada vértice
    for (int i = 0; i < numV; ++i) {
        int color;
        std::cin >> color; // ler a cor do vértice
        g->addColor(i, color); // definir a cor do vértice
    }

    if (op == "-b") {
        // bubble sort
    } else if (op == "-s") {
       // selection sort
    } else if (op == "-i") {
       // insertion sort
    } else if (op == "-q") {
       // quicksort
    } else if (op == "-m") {
       // mergesort
    } else if (op == "-p") {
       // heapsort
    } else if (op == "-y") {
       // custom sort
    }
    return 0;
}
