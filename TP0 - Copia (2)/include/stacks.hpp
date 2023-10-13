//---------------------------------------------------------------------
// Arquivo      : stacks.hpp
// Conteúdo     : arquivo de cabeçario de stacks.hpp
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Histórico    : 23/09/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef STACKS_HPP
#define STACKS_HPP

#include <iostream>

// Estrutura usada na pilha
struct Node {
    char charData;   // Dado do tipo caractere (usado na pilha de caracteres)
    int intData;     // Dado do tipo inteiro (usado na pilha de números inteiros)
    Node* next;      // Ponteiro para o próximo nó na pilha
};

// Pilha encadeada para caracteres (usada para os operadores)
class CharStack {
public:
    CharStack();     // Construtor da classe CharStack
    ~CharStack();    // Destrutor da classe CharStack
    void push(char value);   // Adiciona um caractere à pilha
    char pop();              // Remove e retorna o caractere do topo da pilha
    bool isEmpty();          // Verifica se a pilha de caracteres está vazia
    char peek();             // Retorna o caractere do topo da pilha sem removê-lo

private:
    Node* top;      // Ponteiro para o topo da pilha de caracteres
};

// Pilha encadeada para números inteiros (usada para os operandos)
class NumStack {
public:
    NumStack();      // Construtor da classe NumStack
    ~NumStack();     // Destrutor da classe NumStack
    void push(int value);   // Adiciona um número inteiro à pilha
    int pop();              // Remove e retorna o número inteiro do topo da pilha
    bool isEmpty();         // Verifica se a pilha de números inteiros está vazia
    int peek();            // Retorna o número inteiro do topo da pilha sem removê-lo

private:
    Node* top;      // Ponteiro para o topo da pilha de números inteiros
};

#endif // STACKS_HPP
