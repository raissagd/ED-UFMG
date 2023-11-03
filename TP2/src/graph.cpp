//---------------------------------------------------------------------
// Arquivo      : graph.cpp
// Conteudo     : Implementação do grafo
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 28/10/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/graph.hpp"

Graph::Graph() : numVertices(0), colors(nullptr), adjList(nullptr) {}

Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i) {
        Node* current = adjList[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] adjList;
    delete[] colors;  // Delete the colors array
}

void Graph::insertVertex() {
    Node** newAdjList = new (std::nothrow) Node*[numVertices + 1];
    if (newAdjList) {
        for (int i = 0; i < numVertices; ++i) {
            newAdjList[i] = adjList[i];
        }
        newAdjList[numVertices] = nullptr;

        delete[] adjList;
        adjList = newAdjList;
        numVertices++;

         // Resize the color array
        int* newColors = new int[numVertices];
        for (int i = 0; i < numVertices - 1; ++i) {
            newColors[i] = colors[i];
        }
        newColors[numVertices - 1] = -1;
        delete[] colors;
        colors = newColors;
    }
}

void Graph::insertEdge(int v, int w) {
    if (v >= 0 && v < numVertices && w >= 0 && w < numVertices) {
        Node* newNode = new Node{w, -1, nullptr};
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }
}

int Graph::getNumberOfVertices() const {
    return numVertices;
}

int Graph::getNumberOfEdges() const {
    int edgeCount = 0;
    for (int i = 0; i < numVertices; ++i) {
        for (Node* current = adjList[i]; current != nullptr; current = current->next) {
            edgeCount++;
        }
    }
    return edgeCount / 2; // Since every edge is counted twice
}

void Graph::printNeighbors(int v) const {
    if (v >= 0 && v < numVertices) {
        Node* current = adjList[v];
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

void Graph::addColor(int v, int c) {
    if (v >= 0 && v < numVertices) {  // Use numVertices instead of V
        colors[v] = c;
    }
}

bool Graph::isGreedy(int v, int c) {
    if (v < 0 || v >= numVertices) {
        return false; // Invalid vertex number
    }
    
    // Get the color of vertex v
    int vertexColor = colors[v];
    
    // If the vertex has no color or the color is greater than 'c', it cannot be part of a greedy coloring.
    if (vertexColor == -1 || vertexColor > c) {
        return false;
    }

    // For each color 'i' less than 'vertexColor'
    for (int i = 1; i < vertexColor; ++i) {
        bool colorFound = false;
        
        // Check the neighbors of 'v'
        for (Node* current = adjList[v]; current != nullptr; current = current->next) {
            int neighborColor = colors[current->data];
            
            // If a neighbor has color 'i', set colorFound to true and break
            if (neighborColor == i) {
                colorFound = true;
                break;
            }
        }
        
        // If we didn't find a neighbor with color 'i', it's not a greedy coloring
        if (!colorFound) {
            return false;
        }
    }

    // If all conditions are satisfied, then it's a greedy coloring
    return true;
}