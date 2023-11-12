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

// Estrutura nó, usada na lista encadeada
class Node {
public:
    int data; // Valor do nó (ou vértice)
    int color; // Cor do nó (ou vértice)
    Node* next; // Ponteiro para o próximo elemento
};
class Graph {
public:
    int numVertices; // Número de vértices
    int* colors; // array o colors;
    Node** adjList; // Lista de adjacência

    Graph(); // Construtor
    ~Graph(); // Destrutor
    void insertVertex(); // Inserir um vértice no grafo
    void insertEdge(int v, int w); // Inserir uma aresta no grafo
    int getNumberOfVertices() const; // Retorna o número de vértices
    int getNumberOfEdges() const; // Retorna o número de arestas
    void printNeighbors(int v) const; // Imprime um vértice e seus "vizinhos"
    void addColor(int v, int c); // Atribui a cor 'c' ao vértice 'v'
    bool isGreedy(int v, int c); // Retorna se a coloração é gulosa ou não
};

#endif // GRAPH_HPP