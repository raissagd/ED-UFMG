//---------------------------------------------------------------------
// Arquivo      : sort.hpp
// Conteúdo     : arquivo de cabeçario de sort.hpp
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Histórico    : 28/10/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef SORT_HPP
#define SORT_HPP

// Uma estrutura representando um vértice com um item e uma cor associada.
struct Vertix {
    int item;  // O valor do item armazenado no vértice
    int color; // A cor atribuída ao vértice
};

class Sort {
private:
    int tam; // Tamanho que pode ser usado para limitar operações ou como um limite superior
    void swap(Vertix *xp, Vertix *yp); // Função auxiliar para trocar dois vértices
    void merge(Vertix* arr, int start, int mid, int end);
    int partition(Vertix* arr, int low, int high); // função auxiliar 
    void heapify(Vertix* arr, int n, int i); // função auxiliar

public:
    Sort(int maxtam); // Construtor
    ~Sort(); // Destrutor
    void printVerticesByValue(Vertix* vertices, int numVertices); // Imprime os valores dos vértices
    void bubblesort(Vertix* arr, int n); // Método para ordenar usando Bubble Sort
    void selectionsort(Vertix* arr, int n); // Método para ordenar usando Selection Sort
    void insertionsort(Vertix* arr, int n); // Método para ordenar usando Insertion Sort
    void mergesort(Vertix* arr, int start, int end); // Método para ordenar usando Merge Sort
    void quicksort(Vertix* arr, int low, int high);  // Método para ordenar usando Quick Sort
    void heapsort(Vertix* arr, int n); // Método para ordenar usando Heap Sort
    void customsort(Vertix* arr, int n); // Método para uma ordenação personalizada
};

#endif // SORT_HPP