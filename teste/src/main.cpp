#include "../include/graph.hpp"
#include "../include/sort.hpp"
#include <iostream>
#include <string>
#include <sstream> 

int main(int argc, char* argv[]) {
    std::string op = argv[1];
    int numV;
    std::cin >> numV;
    Graph graph;
    Sort sort(numV);
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

    int* colors = new int[numV]; 
    for (int i = 0; i < numV; ++i) {
        std::cin >> colors[i]; // Read the color for vertex 'i'.
    }

    // Set the color for each vertex in the graph.
    for (int i = 0; i < numV; ++i) {
        vertices[i].color = i;
        graph.addColor(i, colors[i]); // Set the color for vertex 'i'.
    }
    
    if (op == "-b") {
        sort.bubblesort(vertices);
    } else if (op == "-s") { // selection sort
        sort.selectionsort(vertices);
    } else if (op == "-i") { // insertion sort
        sort.insertionsort(vertices);
    } else if (op == "-q") { // quicksort
        sort.quicksort(vertices);
    } else if (op == "-m") { // mergesort
        //sort.mergesort(vertices);
    } else if (op == "-p") { // heapsort
        sort.heapsort(vertices);
    } else if (op == "-y") { // customized sort method
        sort.customsort(vertices);
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
