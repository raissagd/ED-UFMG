//---------------------------------------------------------------------
// Arquivo      : stacks.cpp
// Conteudo     : Implementacao do arquivo com as pilhas de carcteres e números inteiros
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 23/09/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/stacks.hpp"

// ----------- Pilha encadeada para caracteres ----------- //

// Construtor
CharStack::CharStack() {
    top = nullptr;
}

// Destrutor
CharStack::~CharStack() {
    while (!isEmpty()) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

// Add um caractere na pilha
void CharStack::push(char value) {
    Node* newNode = new Node;
    newNode->charData = value;
    newNode->intData = 0; // Iniciliaza intData como '\0'
    newNode->next = top;
    top = newNode;
}

// Retirar um elemento da pilha
char CharStack::pop() {
    if (!isEmpty()) {
        Node* temp = top;
        char value = temp->charData;
        top = top->next;
        delete temp;
        return value;
    }
    return '\0';
}

// Checar se a pilha está vazia
bool CharStack::isEmpty() {
    return top == nullptr;
}

// Retornar o caractere do topo, sem removê-lo
char CharStack::peek() {
    if (!isEmpty()) {
        return top->charData;
    }
    return '\0';
}

// ----------- Pilha encadeada para números inteiros ----------- //

// Construtor
NumStack::NumStack() {
    top = nullptr;
}

// Destrutor
NumStack::~NumStack() {
    while (!isEmpty()) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

// Add um caractere na pilha
void NumStack::push(int value) {
    Node* newNode = new Node;
    newNode->charData = '\0'; // Iniciliaza intData como '\0'
    newNode->intData = value;
    newNode->next = top;
    top = newNode;
}

// Retirar um elemento da pilha
int NumStack::pop() {
    if (!isEmpty()) {
        Node* temp = top;
        int value = temp->intData;
        top = top->next;
        delete temp;
        return value;
    }
    return 0;
}

// Checar se a pilha está vazia
bool NumStack::isEmpty() {
    return top == nullptr;
}

// Retornar o caractere do topo, sem removê-lo
int NumStack::peek() {
    if (!isEmpty()) {
        return top->intData;
    }
    return 0;
}