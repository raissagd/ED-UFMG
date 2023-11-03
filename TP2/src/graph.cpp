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
    delete[] adjList; // Deletando a lista de adjacência
    delete[] colors;  // Deletando o array de cores
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

         // Redimensiona o array de cores
        int* newColors = new int[numVertices];
        for (int i = 0; i < numVertices - 1; ++i) {
            newColors[i] = colors[i];
        }
        newColors[numVertices - 1] = -1; // Inicializa a nova cor com um valor inválido
        delete[] colors;
        colors = newColors;
    }
}

void Graph::insertEdge(int v, int w) {
    if (v >= 0 && v < numVertices && w >= 0 && w < numVertices) {
        Node* newNode = new Node{w, -1, nullptr}; // Criando novo nó
        newNode->next = adjList[v]; // Inserindo no início da lista
        adjList[v] = newNode; // Atualizando o ponteiro da lista de adjacência
    }
}

int Graph::getNumberOfVertices() const {
    return numVertices; // Retorna o número de vértices
}

int Graph::getNumberOfEdges() const {
    int edgeCount = 0;
    for (int i = 0; i < numVertices; ++i) {
        for (Node* current = adjList[i]; current != nullptr; current = current->next) {
            edgeCount++; // Conta as arestas
        }
    }
    return edgeCount / 2; // Como cada aresta é contada duas vezes
}

void Graph::printNeighbors(int v) const {
    if (v >= 0 && v < numVertices) {
        Node* current = adjList[v];
        while (current != nullptr) {
            std::cout << current->data << " "; // Imprimindo os vizinhos
            current = current->next;
        }
        std::cout << std::endl;
    }
}

void Graph::addColor(int v, int c) {
    if (v >= 0 && v < numVertices) {
        colors[v] = c; // Atribui a cor ao vértice
    }
}

bool Graph::isGreedy(int v, int c) {
    if (v < 0 || v >= numVertices) {
        return false; // Número de vértice inválido
    }
    
    // Obtém a cor do vértice v
    int vertexColor = colors[v];
    
    // Se o vértice não tem cor ou a cor é maior que 'c', ele não pode fazer parte de uma coloração gulosa.
    if (vertexColor == -1 || vertexColor > c) {
        return false;
    }

    // Para cada cor 'i' menor que 'vertexColor'
    for (int i = 1; i < vertexColor; ++i) {
        bool colorFound = false;
        
        // Verifica os vizinhos de 'v'
        for (Node* current = adjList[v]; current != nullptr; current = current->next) {
            int neighborColor = colors[current->data];
            
            // Se um vizinho tem a cor 'i', define colorFound como true e interrompe
            if (neighborColor == i) {
                colorFound = true;
                break;
            }
        }
        
        // Se não encontramos um vizinho com a cor 'i', não é uma coloração gulosa
        if (!colorFound) {
            return false;
        }
    }

    // Se todas as condições forem satisfeitas, então é uma coloração gulosa
    return true;
}