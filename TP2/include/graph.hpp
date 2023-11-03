//---------------------------------------------------------------------
// Arquivo      : graph.hpp
// Conteúdo     : arquivo de cabeçario de graph.hpp
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Histórico    : 28/10/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <new>
#include "../include/sort.hpp"

class Node {
public:
    int data;
    int color;
    Node* next;
};
class Graph {
public:
    int numVertices; // Número de vértices
    int* colors; // array o colors;
    Node** adjList; // Lista de adjacência

    Graph();
    ~Graph();
    void insertVertex();
    void insertEdge(int v, int w);
    int getNumberOfVertices() const;
    int getNumberOfEdges() const;
    void printNeighbors(int v) const;
    void addColor(int v, int c); // Atribui a cor 'c' ao vértice 'v'
    bool isGreedy(int v, int c); 
};

#endif // GRAPH_HPP