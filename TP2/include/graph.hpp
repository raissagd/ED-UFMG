//---------------------------------------------------------------------
// Arquivo      : graph.hpp
// Conteúdo     : arquivo de cabeçario de graph.hpp
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Histórico    : 28/10/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include "../include/linkedList.hpp"  
#include "../include/sort.hpp"  

class Graph {
private:
    int V; // Número de vértices
    LinkedList* adjList; // Lista de adjacências
    int* colors; // Array para armazenar as cores atribuídas aos vértices

public:
    Graph(); // Construtor
    ~Graph(); // Destrutor
    void insertVertex(); // Adiciona um vértice ao grafo
    void insertEdge(int v, int w); // Adiciona uma aresta ao grafo (conecta os vértices 'v' e 'w')
    int numVertices(); // Retorna o número de vértices no grafo
    int numEdges(); // Retorna o número de arestas no grafo
    int maximumDegree(); // Retorna o grau maximo de arestas que aquele grafo poderia ter, baseado no num de vértices
    void addColor(int v, int c); // Atribui a cor 'c' ao vértice 'v'
    int getVertexColor(int v); // Obtém a cor atualmente atribuída ao vértice 'v'
    bool isGreedy(int v, int c); // Verifica se a coloração atual é 'gulosa' com base no vértice 'v' e na cor 'c'
};

#endif // GRAPH_HPP