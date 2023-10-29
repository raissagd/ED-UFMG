#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include "../include/linkedList.hpp"  
#include "../include/sort.hpp"  

class Graph {
private:
    int V; // Number of vertices
    LinkedList* adjList; // Adjacency list now as an array of linked lists
    int* colors;
    
public:
    Graph(); // Constructor
    ~Graph(); // Destructor
    void insertVertex(); // Add a vertex to the graph
    void insertEdge(int v, int w); // Add an edge to the graph
    int numVertices(); // Returns the number of vertices
    int numEdges(); // Returns the number of edges
    int minimumDegree(); // Returns the degree of the node with the least number of edges
    int maximumDegree(); // Returns the degree of the node with the most number of edges
    void printNeighbors(int v); // Prints the neighbors of a given vertex
    void addColor(int v, int c);
    int getVertexColor(int v);
    bool isGreedy(int v, int c);
};

#endif // GRAPH_HPP