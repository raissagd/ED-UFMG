#include "../include/graph.hpp"

Graph::Graph() : V(0), adjList(nullptr) {
    colors = new int[V]; // initialize with the number of vertices
    for (int i = 0; i < V; i++)
        colors[i] = -1; // default color value
}

Graph::~Graph() {
    delete[] adjList;
    delete[] colors; 
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
    if (v >= 0 && v < V) {
        colors[v] = c;
    }
}

int Graph::getVertexColor(int v) {
    if (v >= 0 && v < V) {
        return colors[v];
    }
    return -1; // or some other invalid color indicator
}

bool Graph::isGreedy(int v, int c) {
    if (c == 1) {
        return true;
    }

    // se o grafo é completo, ele é guloso
    if (numEdges() == maximumDegree()) {
        return true;
    }

   // For each vertex in the graph
    for (int v = 0; v < V; ++v) {
        // Create a boolean array for all possible lesser colors, all initialized to false.
        int max = 10000;
        bool lesserColors[max] = {false};  // Assumes MAX_COLOR is defined as the maximum possible color + 1.

        Node* current = adjList[v].getHead(); // Get the head of the adjacency list for this vertex.

        // Check the colors of the adjacent vertices.
        while (current != nullptr) {
            int adjacent = current->data; // The adjacent vertex.

            // Check if an adjacent vertex has the same color - if so, it's not greedy.
            if (colors[v] == colors[adjacent]) {
                return false;
            }

            // If the color of the adjacent vertex is less than this vertex's color, record that.
            if (colors[adjacent] < colors[v]) {
                lesserColors[colors[adjacent]] = true;
            }

            current = current->next; // Move to the next adjacent vertex.
        }

        // Now check that all colors less than this vertex's color are present among the neighbors.
        for (int i = 1; i < colors[v]; ++i) { // Start from 1 because there's no color less than 1.
            if (!lesserColors[i]) {
                // If any lesser color is not present among the neighbors, it's not a greedy coloring.
                return false;
            }
        }
    }

    // If we've satisfied all the conditions, it's a greedy coloring.
    return true;
}