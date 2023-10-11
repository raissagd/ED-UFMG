//---------------------------------------------------------------------
// Arquivo      : stringVector.hpp
// Conteudo     : arquivo de cabeçario de stringVector.cpp
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 23/09/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef STRINGVECTOR_HPP
#define STRINGVECTOR_HPP

#include <iostream>
#include <string>

// Vetor de strings
class StringVector {
public:
    // Construtor
    StringVector();

    // Destrutor
    ~StringVector();

    // Adiciona uma string no final do vetor
    void push_back(const std::string& str);

    // Remove um elemento pelo index dele
    void remove(size_t index); 

    // Acessa um elemento pelo index dele
    std::string& operator[](size_t index);

    // Get do tamanho do vetor
    size_t getSize() const;

    // Checar se o vetor está vazio
    bool isEmpty() const;

private:
    std::string* data;
    size_t size;
    size_t capacity;
};

#endif


