//---------------------------------------------------------------------
// Arquivo      : intArray.hpp
// Conteudo     : Arquivo de cabeçário - Implementação de um vetor de inteiros (to tipo unsigned long long)
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 25/11/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef INTARRAY_HPP
#define INTARRAY_HPP

#include <iostream>
#include <cstddef> 
#include <stdexcept>

class IntArray {
private:
    unsigned long long* array; // Ponteiro para o array dinâmico de inteiros
    size_t capacity; // Capacidade total do array (quantidade máxima de elementos que podem ser armazenados)
    size_t length; // Número atual de elementos no array

public:
    IntArray(); // Construtor que inicializa um IntArray vazio
    ~IntArray(); // Destrutor para desalocar a memória utilizada pelo array
    IntArray(const IntArray& other); // Construtor de cópia
    unsigned long long operator[](size_t index) const; // Sobrecarga do operador [] para acesso constante a elementos
    void push_back(unsigned long long element); // Método para adicionar um elemento ao final do array
    unsigned long long& operator[](size_t index); // Sobrecarga do operador [] para acesso e modificação de elementos
    size_t size() const; // Retorna o número de elementos no array
    void clear(); // Limpa o array, removendo todos os elementos e reiniciando sua capacidade
    void print() const; // Imprime todos os elementos do array
    IntArray& operator=(const IntArray& other); // Sobrecarga do operador de atribuição
};

#endif // INTARRAY_HPP
