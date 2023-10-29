#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

struct Node {
    int data; // The data each node will hold
    int color;
    Node* next; // Pointer to the next node in the list
};

class LinkedList {
private:
    Node* head; // The starting node of the list
    int listSize; // Track the size of the list

public:
    LinkedList(); // Constructor
    ~LinkedList(); // Destructor
    void insert(int value); // Insert a node at the end of the list
    bool remove(int value); // Remove a node with the specified value
    int size(); // Get the size of the list
    void print(); // Print the contents of the list
    void setColor(int v, int c);
    int getColor(int value); 
};

#endif //LINKEDLIST_HPP