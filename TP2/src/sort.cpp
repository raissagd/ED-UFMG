//---------------------------------------------------------------------
// Arquivo      : sort.cpp
// Conteudo     : Implementação dos métodos de ordenação
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 28/10/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/sort.hpp"
#include <iostream>

// Construtor: inicializa a variável 'tam' com o tamanho máximo fornecido
Sort::Sort(int maxtam) {
    tam = maxtam;
}

// Destrutor
Sort::~Sort() {
    // Não há alocação dinâmica de memória para limpar
}

// Função para imprimir os vértices por valor
void Sort::printVerticesByValue(Vertix* vertices, int numVertices) {
    std::cout << "1" << " "; //
    for (int i = 0; i < numVertices; i++) {
        std::cout << vertices[i].item << " ";
    }
    std::cout << std::endl; // 
}

// Função para trocar dois vértices
void Sort::swap(Vertix *xp, Vertix *yp) {
    Vertix temp = *xp; // Armazena temporariamente o valor de 'xp'
    *xp = *yp; // Atribui o valor de 'yp' a 'xp'
    *yp = temp; // Atribui o valor armazenado temporariamente a 'yp'
}

// Implementação do algoritmo Bubble Sort
void Sort::bubblesort(Vertix* arr, int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {    
        // Os últimos i elementos já estão no lugar
        for (j = 0; j < n-i-1; j++) {
            if (arr[j].color > arr[j+1].color) { // Compara as cores dos vértices
                swap(&arr[j], &arr[j+1]); // Troca se o anterior é maior que o próximo
            }
        }
    }
}

void Sort::selectionsort(Vertix* array) {
    // a implementar
}

void Sort::insertionsort(Vertix* array) {
    // a implementar
}

void Sort::mergesort(Vertix* array, int start, int end) {
    // a implementar
}

void Sort::quicksort(Vertix* array) {
    // a implementar
}

void Sort::heapsort(Vertix* array) {
    // a implementar
}

void Sort::customsort(Vertix* array) {
    // a implementar
}