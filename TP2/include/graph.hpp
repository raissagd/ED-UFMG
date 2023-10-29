//---------------------------------------------------------------------
// Arquivo      : graph.hpp
// Conteúdo     : arquivo de cabeçario de graph.hpp
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Histórico    : 28/10/2023 - arquivo criado
//---------------------------------------------------------------------

// graph.hpp
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "./linkedList.hpp"
class Graph {
private:
    int V;  // Number of vertices
    LinkedList* adjList;  // Array of adjacency lists
    int* vColors;

public:
    Graph();
    ~Graph();

    void addV();
    void addEdge(int v, int w);

    int numV();
    int numEdges();

    int minDegree();
    int maxDegree();
    
    void addColor (int i, int c);

    void printNeighbors(int v);
};

#endif  // GRAPH_HPP
