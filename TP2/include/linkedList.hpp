//---------------------------------------------------------------------
// Arquivo      : list.hpp
// Conteúdo     : arquivo de cabeçario de list.hpp
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Histórico    : 28/10/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

struct Node {
    int data; // O valor armazenado em cada nó
    int color; // A cor associada a cada nó
    Node* next; // Ponteiro para o próximo nó na lista
};

class LinkedList {
private:
    Node* head; // O primeiro nó da lista
    int listSize; // Mantém o tamanho atual da lista

public:
    LinkedList(); // Construtor
    ~LinkedList(); // Destrutor
    Node* getHead(); // Retorna o ponteiro para o primeiro nó da lista
    void insert(int value); // Insere um novo nó no final da lista
    bool remove(int value); // Remove um nó com o valor especificado da lista
    int size(); // Retorna o tamanho da lista
};

#endif // LINKEDLIST_HPP
