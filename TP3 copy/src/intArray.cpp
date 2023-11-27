//---------------------------------------------------------------------
// Arquivo      : intArray.cpp
// Conteudo     : Implementação de intArray.hpp
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 25/11/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/intArray.hpp"

// Construtor padrão que cria um vetor vazio
IntArray::IntArray() : array(nullptr), capacity(0), length(0) {}

// Destrutor que libera a memória alocada pelo vetor
IntArray::~IntArray() {
    delete[] array;
}

// Construtor de cópia que cria um vetor como uma cópia de outro vetor
IntArray::IntArray(const IntArray& other) : array(nullptr), capacity(other.capacity), length(other.length) {
    array = new unsigned long long[capacity];
    for (size_t i = 0; i < length; i++) {
        array[i] = other.array[i];
    }
}

// Operador de acesso a elementos para leitura
unsigned long long IntArray::operator[](size_t index) const {
    if (index >= length) {
        throw std::out_of_range("Index out of range"); // Lança exceção se o índice estiver fora do intervalo
    }
    return array[index];
}

// Método para adicionar um novo elemento ao final do vetor
void IntArray::push_back(unsigned long long element) {
    if (length >= capacity) {
        size_t newCapacity = capacity == 0 ? 1 : capacity * 2; // Dobra a capacidade se necessário
        unsigned long long* newArray = new unsigned long long[newCapacity];
        for (size_t i = 0; i < length; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }
    array[length++] = element;
}

// Operador de acesso a elementos para modificação
unsigned long long& IntArray::operator[](size_t index) {
    if (index >= length) {
        throw std::out_of_range("Index out of range"); // Lança exceção se o índice estiver fora do intervalo
    }
    return array[index];
}

// Retorna o tamanho atual do vetor
size_t IntArray::size() const {
    return length;
}

// Limpa o vetor, removendo todos os elementos e reiniciando sua capacidade
void IntArray::clear() {
    delete[] array;
    array = nullptr;
    capacity = 0;
    length = 0;
}

// Imprime todos os elementos do vetor
void IntArray::print() const {
    for (size_t i = 0; i < length; ++i) {
        std::cout << array[i] << (i < length - 1 ? " " : "\n");
    }
}

// Sobrecarga do operador de atribuição para copiar os elementos de outro vetor
IntArray& IntArray::operator=(const IntArray& other) {
    if (this != &other) {
        delete[] array; // Libera o recurso existente
        length = other.length;
        capacity = other.capacity;
        array = new unsigned long long[capacity];
        for (size_t i = 0; i < length; i++) {
            array[i] = other.array[i];
        }
    }
    return *this;
}