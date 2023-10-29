#include "../include/graph.hpp"
#include "../include/sort.hpp"
#include <iostream>
#include <string>
#include <sstream> 
#include <limits>
#include <vector>


int main(int argc, char* argv[]) {
    std::string op = argv[1];
    int numV;
    std::cin >> numV;
    Graph graph;
    Vertix* vertices = new Vertix[numV];

    // Insert vertices into the graph
    for (int i = 0; i < numV; ++i) {
        vertices[i].item = i;
        graph.insertVertex();
    }

    // Read the neighbors.
    for (int i = 0; i < numV; ++i) {
        int numNeighbors;
        std::cin >> numNeighbors; // the number of neighbors for vertex i
        
        for (int j = 0; j < numNeighbors; ++j) {
            int neighbor;
            std::cin >> neighbor; // the specific neighbor
            graph.insertEdge(i, neighbor); // this adds an edge from vertex i to vertex 'neighbor'
        }
    }

    std::vector<int> colors(numV); // Vector to hold the colors.
    for (int i = 0; i < numV; ++i) {
        std::cin >> colors[i]; // Read the color for vertex 'i'.
    }

    // Now, we set the color for each vertex in the graph.
    for (int i = 0; i < numV; ++i) {
        graph.addColor(i, colors[i]); // Set the color for vertex 'i'.
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
    } else if (op == "-n") {
        // Operation to print the neighborhoods of the vertices
        for (int i = 0; i < graph.numVertices(); ++i) { 
            graph.printNeighbors(i);
        }

         for (int i = 0; i < graph.numVertices(); ++i) {
            int color = graph.getVertexColor(i);
            std::cout << "Vertex " << i << " has color: " << color << std::endl;
         }
    }

   delete[] vertices;

    return 0;
}
