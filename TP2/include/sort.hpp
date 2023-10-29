//---------------------------------------------------------------------
// Arquivo      : sort.hpp
// Conteúdo     : arquivo de cabeçario de sort.hpp
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Histórico    : 28/10/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef SORT_HPP
#define SORT_HPP
struct V {
    int item;
    int color;
};
class Sort{
private:
    int tam;

public:
    Sort(int maxtam);
    ~Sort();

    void quicksort(V* g);
    void mergesort(V* g, int start, int end);
    void bubblesort(V* g);
    void selectionsort(V* g);
    void insertionsort(V* g);
    void heapsort(V* g);
    void custom(V* g);
};

#endif