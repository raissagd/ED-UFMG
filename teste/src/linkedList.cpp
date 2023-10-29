#include "../include/linkedList.hpp"

// Constructor
LinkedList::LinkedList() : head(nullptr), listSize(0) {}

// Destructor
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr; // Safeguard
}

Node* LinkedList::getHead() {
    return head;
}

// Method to insert a new node at the end of the list
void LinkedList::insert(int value) {
    // Including color in aggregate initialization, assuming '0' as default color.
    Node* newNode = new Node{value, -1, nullptr};  // '-1' is a placeholder

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    listSize++;
}


// Method to remove a node from the list based on value
bool LinkedList::remove(int value) {
    if (head == nullptr) return false; // List is empty

    if (head->data == value) {
        Node* tempNode = head;
        head = head->next;
        delete tempNode;
        listSize--;
        return true;
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->data == value) {
            Node* tempNode = current->next;
            current->next = current->next->next;
            delete tempNode;
            listSize--;
            return true;
        }
        current = current->next;
    }
    return false; // If we reach here, the value was not found
}

// Method to get the size of the list
int LinkedList::size() {
    return listSize;
}

// Method to print the list contents
void LinkedList::print() {
     Node* temp = head; // assuming 'head' points to the start of your linked list

    while (temp != nullptr) {
        std::cout << temp->data; // assuming your node's data is an integer
        if (temp->next != nullptr) {
            std::cout << " "; // separate the numbers by spaces
        }
        temp = temp->next;
    }
    std::cout << std::endl; 
}
