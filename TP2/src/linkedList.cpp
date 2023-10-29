//---------------------------------------------------------------------
// Arquivo      : list.cpp
// Conteudo     : 
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 28/10/2023 - arquivo criado
//---------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "../include/linkedList.hpp"

LinkedList::LinkedList() {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::pushBack(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int LinkedList::size() {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

bool LinkedList::empty() {
    return head == nullptr;
}

Node* LinkedList::begin() {
    return head;
}

void LinkedList::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
