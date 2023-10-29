#include "../include/sort.hpp"
#include <iostream>

Sort::Sort(int maxtam) {
    tam = maxtam;
}

Sort::~Sort() {
}

void Sort::printVerticesByValue(Vertix* vertices, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        std::cout << vertices[i].item << " ";
    }
    std::cout << std::endl; // Newline at the end of printing all values.
}

void Sort::swap(Vertix *xp, Vertix *yp) {
    Vertix temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Sort::bubblesort(Vertix* arr, int n) {
  int i, j;
    for (i = 0; i < n-1; i++) {    
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++) {
            if (arr[j].color > arr[j+1].color) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void Sort::selectionsort(Vertix* array) {
    // to do
}

void Sort::insertionsort(Vertix* array) {
    // to do
}

void Sort::mergesort(Vertix* array, int start, int end) {
    // to do
}

void Sort::quicksort(Vertix* array) {
    // to do
}

void Sort::heapsort(Vertix* array) {
    // to do
}

void Sort::customsort(Vertix* array) {
    // to do
}