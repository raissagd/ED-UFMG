#include "../include/graph.hpp"

Graph::Graph() : V(0), adjList(nullptr) {}

Graph::~Graph() {
    delete[] adjList; // deallocate memory used by the adjacency lists
}

void Graph::insertVertex() {
    LinkedList* newAdjList = new LinkedList[V + 1]; // Create a new array of linked lists with an additional slot for the new vertex

    // Copy existing adjacency lists into the new array
    for (int i = 0; i < V; ++i) {
        newAdjList[i] = adjList[i]; // This assumes you have a copy constructor or an appropriate method in LinkedList to handle this operation.
    }

    delete[] adjList; // Delete the old array
    adjList = newAdjList; // Point to the new array
    ++V; // Increase the number of vertices
}

void Graph::insertEdge(int v, int w) {
    if (v < V && w < V) { // check if the vertices exist
        adjList[v].insert(w); // add w to v’s list, but not v to w’s list
    }
}


int Graph::numVertices() {
    return V;
}

int Graph::numEdges() {
    int totalEdges = 0;
    for (int i = 0; i < V; ++i) {
        totalEdges += adjList[i].size(); // Assumes 'size' gives the number of elements in the linked list
    }
    return totalEdges / 2; // Each edge is counted twice, so we divide by 2.
}

int Graph::minimumDegree() {
    if (V == 0) {
        return 0; // If there are no vertices, return 0
    }

    int minDegree = adjList[0].size(); // Initialize with the degree of the first vertex

    // Iterate through all vertices
    for (int i = 1; i < V; ++i) {
        int currentDegree = adjList[i].size();
        if (currentDegree < minDegree) {
            minDegree = currentDegree; // Update minDegree if the current one is lower
        }
    }

    return minDegree;
}

int Graph::maximumDegree() {
    int maxDegree = 0; // Initially, set to 0

    // Iterate through all vertices
    for (int i = 0; i < V; ++i) {
        int currentDegree = adjList[i].size();
        if (currentDegree > maxDegree) {
            maxDegree = currentDegree; // Update maxDegree if the current one is higher
        }
    }

    return maxDegree;
}

void Graph::printNeighbors(int v) {
    if (v < V) {
        std::cout << "Neighbors of vertex " << v << ": ";
        adjList[v].print(); // Assumes 'print' is a method in LinkedList that prints its elements.
    }
}

void Graph::addColor(int v, int c) {
     if(v >= 0 && v < V) {
        adjList[v].setColor(v, c); // Assumes setColor exists in LinkedList
    }
}

int Graph::getVertexColor(int v) {
    return adjList[v].getColor(v); // use the linked list's getColor method
}

bool Graph::isGreedy(int v, int c) {
    // to do
}