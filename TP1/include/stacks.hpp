#ifndef STACKS_HPP
#define STACKS_HPP

#include <iostream>

// Classe para pilha de caracteres (usada nos operadores)
class CharStack {
private:
    static const int maxSize = 1000000;
    char stack[maxSize];
    int top;

public:
    CharStack();
    ~CharStack();

    // Insere um caractere na pilha
    void push(char value);

    // Remove e retorna o caractere do topo da pilha
    char pop();

    // Verifica se a pilha está vazia
    bool isEmpty();

    // Retorna o caractere do topo da pilha sem removê-lo
    char peek();
};

// Classe para pilha de números inteiros (usada nos operandos)
class NumStack {
private:
    static const int maxSize = 1000000;
    int stack[maxSize];
    int top;

public:
    NumStack();
    ~NumStack();

    // Insere um número inteiro na pilha
    void push(int value);

    // Remove e retorna o número inteiro do topo da pilha
    int pop();

    // Verifica se a pilha está vazia
    bool isEmpty();

    // Retorna o número inteiro do topo da pilha sem removê-lo
    int peek();
};

#endif // STACKS_HPP