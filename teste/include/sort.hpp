#ifndef SORT_HPP
#define SORT_HPP

struct Vertix {
    int item;
    int color;
};

class Sort{
private:
    int tam;

public:
    Sort(int maxtam);
    ~Sort();
    void quicksort(Vertix* array);
    void mergesort(Vertix* array, int start, int end);
    void bubblesort(Vertix* array);
    void selectionsort(Vertix* array);
    void insertionsort(Vertix* array);
    void heapsort(Vertix* array);
    void customsort(Vertix* array);
};

#endif