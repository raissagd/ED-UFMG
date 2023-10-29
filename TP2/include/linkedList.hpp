//---------------------------------------------------------------------
// Arquivo      : list.hpp
// Conteúdo     : arquivo de cabeçario de list.hpp
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Histórico    : 28/10/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef LINKEDLIST_HPP
#define NodeLINKEDLIST_HPP

struct Node {
    int data; // valor do vértice
    int* nbd; // vizinhos
    int color; // cor
    int numConex; // número de conexões

    Node* next; // próximo nó
};
 

class LinkedList {
private:
    Node* head;
    int numV;
public:
    LinkedList();
    ~LinkedList();

    void pushBack(int data);
    int size();
    bool empty();
    Node* begin();  // Provides a pointer to the first element (if needed)
    void clear();  // Deletes all nodes, used in the destructor and if needed elsewhere
};

#endif // LINKEDLIST_HPP
