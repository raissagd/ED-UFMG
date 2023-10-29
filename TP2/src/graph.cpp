//---------------------------------------------------------------------
// Arquivo      : graph.cpp
// Conteudo     : Implementação do grafo
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 28/10/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/graph.hpp"

Graph::Graph() : V(0), adjList(nullptr) {
    colors = new int[V]; // inicializa com o número de vértices
    for (int i = 0; i < V; i++)
        colors[i] = -1; // valor padrão para cor
}

Graph::~Graph() {
    delete[] adjList;
    delete[] colors; 
}

void Graph::insertVertex() {
    LinkedList* newAdjList = new LinkedList[V + 1]; // Cria um novo array de listas ligadas com um espaço adicional para o novo vértice

    // Copia listas de adjacências existentes para o novo array
    for (int i = 0; i < V; ++i) {
        newAdjList[i] = adjList[i]; // Isso presume que você tenha um construtor de cópia ou um método apropriado em LinkedList para lidar com esta operação.
    }

    delete[] adjList; // Deleta o array antigo
    adjList = newAdjList; // Aponta para o novo array
    ++V; // Aumenta o número de vértices
}

void Graph::insertEdge(int v, int w) {
    if (v < V && w < V) { // verifica se os vértices existem
        adjList[v].insert(w); // adiciona w à lista de v, mas não v à lista de w
    }
}

int Graph::numVertices() {
    return V;
}

int Graph::numEdges() {
    int totalArestas = 0;
    for (int i = 0; i < V; ++i) {
        totalArestas += adjList[i].size(); // Presume-se que 'size' forneça o número de elementos na lista ligada
    }
    return totalArestas / 2; // Cada aresta é contada duas vezes, então dividimos por 2.
}

int Graph::maximumDegree() {
    int maxDegree = 0; // Inicialmente, define como 0

    // Itera por todos os vértices
    for (int i = 0; i < V; ++i) {
        int grauAtual = adjList[i].size();
        if (grauAtual > maxDegree) {
            maxDegree = grauAtual; // Atualiza maxDegree se o atual for maior
        }
    }

    return maxDegree;
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
    return -1; // cor inválida
}

bool Graph::isGreedy(int v, int c) {
    if (c == 1) {
        return true;
    }

    // se o grafo é completo, ele é guloso
    if (numEdges() == maximumDegree()) {
        return true;
    }

   // Para cada vértice no grafo
    for (int v = 0; v < V; ++v) {
        // Cria um array booleano para todas as cores menores possíveis, todas inicializadas como falsas.
        int max = 10000; // Max de cores possiveis foi arbitrariamente escolhido
        bool lesserColors[max] = {false};  

        Node* current = adjList[v].getHead(); // Pega a célula cabeça da lista de adjacência para este vértice.

        // Verifica as cores dos vértices adjacentes.
        while (current != nullptr) {
            int adjacent = current->data; // O vértice adjacente.

            // Verifica se um vértice adjacente tem a mesma cor - se sim, não é guloso.
            if (colors[v] == colors[adjacent]) {
                return false;
            }

            // Se a cor do vértice adjacente for menor que a cor deste vértice, registra isso.
            if (colors[adjacent] < colors[v]) {
                lesserColors[colors[adjacent]] = true;
            }

            current = current->next; // Move para o próximo vértice adjacente.
        }

        // Agora verifica se todas as cores menores que a cor deste vértice estão presentes entre os vizinhos.
        for (int i = 1; i < colors[v]; ++i) { // Começa de 1 porque não há cor menor que 1.
            if (!lesserColors[i]) {
                // Se alguma cor menor não estiver presente entre os vizinhos, não é uma coloração gulosa.
                return false;
            }
        }
    }

    // Se todas as condições foram satisfeitas, é uma coloração gulosa.
    return true;
}