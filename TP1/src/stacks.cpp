#include "Stacks.hpp"

// ----------- stack de caracteres ----------- //

CharStack::CharStack() {
    top = -1; // Inicializa o índice do topo como -1 (pilha vazia)
}

CharStack::~CharStack() {
    // Não é necessário desalocar memória para arrays que não são dinâmicos
}

void CharStack::push(char value) {
    if (top >= maxSize - 1) {
        // Verifica se a pilha está cheia e exibe uma mensagem de erro se estiver
        std::cerr << "Error: Stack is full, cannot push more elements." << std::endl;
        exit(1);
    }
    stack[++top] = value; // Incrementa o topo e insere o valor na pilha
}

char CharStack::pop() {
    if (isEmpty()) {
        // Verifica se a pilha está vazia e exibe uma mensagem de erro se estiver
        std::cerr << "Error: Attempted to pop from an empty stack." << std::endl;
        exit(1);
    }
    return stack[top--]; // Retorna o valor do topo e decrementa o topo
}

bool CharStack::isEmpty() {
    return top == -1; // Retorna true se o topo for igual a -1, indicando pilha vazia
}

char CharStack::peek() {
    if (isEmpty()) {
        // Verifica se a pilha está vazia e exibe uma mensagem de erro se estiver
        std::cerr << "Error: Attempted to access the top of an empty stack." << std::endl;
        exit(1);
    }
    return stack[top]; // Retorna o valor no topo da pilha
}

// ----------- stack de números inteiros ----------- //

NumStack::NumStack() {
    top = -1; // Inicializa o índice do topo como -1 (pilha vazia)
}

NumStack::~NumStack() {
    // Não é necessário desalocar memória para arrays que não são dinâmicos
}

void NumStack::push(int value) {
    if (top >= maxSize - 1) {
        // Verifica se a pilha está cheia e exibe uma mensagem de erro se estiver
        std::cerr << "Error: Stack is full, cannot push more elements." << std::endl;
        exit(1);
    }
    stack[++top] = value; // Incrementa o topo e insere o valor na pilha
}

int NumStack::pop() {
    if (isEmpty()) {
        // Verifica se a pilha está vazia e exibe uma mensagem de erro se estiver
        std::cerr << "Error: Attempted to pop from an empty stack." << std::endl;
        exit(1);
    }
    return stack[top--]; // Retorna o valor do topo e decrementa o topo
}

bool NumStack::isEmpty() {
    return top == -1; // Retorna true se o topo for igual a -1, indicando pilha vazia
}

int NumStack::peek() {
    if (isEmpty()) {
        // Verifica se a pilha está vazia e exibe uma mensagem de erro se estiver
        std::cerr << "Error: Attempted to access the top of an empty stack." << std::endl;
        exit(1);
    }
    return stack[top]; // Retorna o valor no topo da pilha
}