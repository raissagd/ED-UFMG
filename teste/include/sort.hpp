#ifndef SORT_HPP
#define SORT_HPP

struct Vertix {
    int item;
    int color;
};

class Sort{
private:
    int tam;
    void swap(Vertix *xp, Vertix *yp);

public:
    Sort(int maxtam);
    ~Sort();
    void printVerticesByValue(Vertix* vertices, int numVertices);
    void bubblesort(Vertix* arr, int n);
    void quicksort(Vertix* array);
    void mergesort(Vertix* array, int start, int end);
    void selectionsort(Vertix* array);
    void insertionsort(Vertix* array);
    void heapsort(Vertix* array);
    void customsort(Vertix* array);
};

#endif