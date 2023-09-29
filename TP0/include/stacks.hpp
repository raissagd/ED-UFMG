//---------------------------------------------------------------------
// Arquivo      : stacks.hpp
// Conteudo     : arquivo de cabeçario de stacks.hpp
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 23/09/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef STACKS_HPP
#define STACKS_HPP

#include <iostream>

// Estrutura usada na pilha
struct Node {
    char charData;
    int intData;
    Node* next;
};

// Pilha encadeada para caracteres (usada para os operadores)
class CharStack {
public:
    CharStack();
    ~CharStack();
    void push(char value);
    char pop();
    bool isEmpty();
    char peek();

private:
    Node* top;
};

// Pilha encadeada para números inteiros (usada para os operandos)
class NumStack {
public:
    NumStack();
    ~NumStack();
    void push(int value);
    int pop();
    bool isEmpty();
    int peek();

private:
    Node* top;
};

#endif // STACKS_HPP