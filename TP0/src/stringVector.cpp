//---------------------------------------------------------------------
// Arquivo      : stringVector.cpp
// Conteudo     : Implementacao do vetor de strings
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 26/09/2023 - arquivo criado
//---------------------------------------------------------------------

#include "StringVector.hpp"

// Construtor 
StringVector::StringVector() : size(0), capacity(1000) {
    data = new std::string[capacity];
}

// Destrutor 
StringVector::~StringVector() {
    delete[] data;
}

// Função para adicionar uma string no final do vetor
void StringVector::push_back(const std::string& str) {
    if (size >= capacity) {
        capacity *= 2; // Dobra a capacidade do vetor se estiver cheio
        std::string* newData = new std::string[capacity]; // Cria um novo vetor com a capacidade aumentada

        // Copia os elementos do vetor original para o novo vetor
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        delete[] data; // Libera a memória alocada para o vetor original
        data = newData; // Atualiza o ponteiro para apontar para o novo vetor
    }

    data[size++] = str; // Insere a string no final do vetor e incrementa o tamanho
}

// Função para remover um elemento pelo índice
void StringVector::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range"); // Lança uma exceção se o índice estiver fora do intervalo
    }

    // Após um elemento ser removido, desloca os outros elementos 1 posição para a esquerda
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }

    --size; // Reduz o tamanho do vetor após a remoção
}

// Operador [] para acessar elementos pelo índice
std::string& StringVector::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range"); // Lança uma exceção se o índice estiver fora do intervalo
    }
    return data[index]; // Retorna a referência para o elemento no índice especificado
}

// Função para obter o tamanho do vetor
size_t StringVector::getSize() const {
    return size; 
}

// Função para verificar se o vetor está vazio
bool StringVector::isEmpty() const {
    return size == 0;
}