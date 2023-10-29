//---------------------------------------------------------------------
// Arquivo      : list.cpp
// Conteudo     : Implementação da lista encadeada usada para armazenar os elementos do grafo
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 28/10/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/linkedList.hpp"

// Construtor
LinkedList::LinkedList() : head(nullptr), listSize(0) {}

// Destrutor
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current; // Libera a memória alocada para o nó
        current = next;
    }
    head = nullptr;
}

Node* LinkedList::getHead() {
    return head; // Retorna o início da lista
}

// Método para inserir um novo nó no final da lista
void LinkedList::insert(int value) {
    Node* newNode = new Node{value, -1, nullptr};

    if (head == nullptr) {
        head = newNode; // Se a lista está vazia, o novo nó é agora a cabeça
    } else {
        Node* current = head;
        while (current->next != nullptr) { // Navega pela lista até encontrar o último nó
            current = current->next;
        }
        current->next = newNode; // Insere o novo nó no final da lista
    }
    listSize++; // Incrementa o contador de tamanho da lista
}

// Método para remover um nó da lista com base no valor
bool LinkedList::remove(int value) {
    if (head == nullptr) return false; // A lista está vazia

    if (head->data == value) {
        Node* tempNode = head;
        head = head->next; // O segundo nó agora é a cabeça
        delete tempNode; // Libera a memória do nó antigo
        listSize--;
        return true;
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->data == value) {
            Node* tempNode = current->next;
            current->next = current->next->next; // Desvincula o nó a ser removido
            delete tempNode; // Libera a memória do nó desvinculado
            listSize--;
            return true;
        }
        current = current->next; // Continua a navegação pela lista
    }
    return false; // Se o valor não foi encontrado
}

// Método para obter o tamanho da lista
int LinkedList::size() {
    return listSize;
}