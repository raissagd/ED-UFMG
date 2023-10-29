//---------------------------------------------------------------------
// Arquivo      : graph.cpp
// Conteudo     : 
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 28/10/2023 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include "../include/graph.hpp"

Graph::Graph(int numVertices) : V(numVertices), adjList(new LinkedList[numVertices]), vertexColors(new int[numVertices]) {
    // inicializa todas as cores como -1 ou outra constante que indica que elas ainda não foram definidas
    for (int i = 0; i < V; ++i) {
        vColors[i] = -1;
    }
}

Graph::~Graph() {
    delete[] adjList;
    delete[] vColors; // Lembre-se de deletar o array de cores
}

void Graph::addV() {
    LinkedList* newAdjList = new LinkedList[V + 1];
    for (int i = 0; i < V; ++i) {
        newAdjList[i] = adjList[i];  // This may require an appropriate copy constructor/assignment operator in LinkedList
    }

    delete[] adjList;
    adjList = newAdjList;

    ++V;
}

int Graph::numV() {
    return V;
}

void Graph::addEdge(int v, int w) {
    if (v >= 0 && v < V && w >= 0 && w < V) {
        adjList[v].pushBack(w);  // Correcting the method name here
        // For an undirected graph, uncomment the following line
        // adjList[w].push_back(v);
    }
}

int Graph::numEdges() {
    int edges = 0;
    for (int i = 0; i < V; ++i) { // Adjusting the loop here
        edges += adjList[i].size();
    }
    // For undirected graphs, each edge is counted twice
    return edges / 2;
}

int Graph::minDegree() {
    int minDegree = INT_MAX;
    for (int i = 0; i < V; ++i) { // Adjusting the loop here
        int degree = adjList[i].size();
        if (degree < minDegree) {
            minDegree = degree;
        }
    }
    return minDegree == INT_MAX ? 0 : minDegree;
}

int Graph::maxDegree() {
    int maxDegree = 0;
    for (int i = 0; i < V; ++i) { // Adjusting the loop here
        int degree = adjList[i].size();
        if (degree > maxDegree) {
            maxDegree = degree;
        }
    }
    return maxDegree;
}

void Graph::printNeighbors(int v) {
    if (v >= 0 && v < V) {
        std::cout << "Neighbors of vertex " << v << ": ";
        for (Node* current = adjList[v].begin(); current != nullptr; current = current->next) {
            std::cout << current->data << " ";
        }
        std::cout << std::endl;
    }
}

// Implementação do método addColor
void Graph::addColor(int v, int color) {
    if (v >= 0 && v < V) { // Verifica limites
        vColors[v] = color; // Define a cor do vértice
    }
}