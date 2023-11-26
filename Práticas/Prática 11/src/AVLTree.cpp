#include "../include/AVLTree.hpp"
#include <iostream>
#include <algorithm>

AVLNode::AVLNode(std::string w, int page) : word(w), height(1), left(nullptr), right(nullptr) {
    pages.push_back(page);
}

// Funções de utilidade para obter a altura e atualizar a altura de um nó
int AVLTree::getHeight(AVLNode *N) {
    if (N == nullptr) return 0;
    return N->height;
}

void AVLTree::updateHeight(AVLNode *N) {
    if (N != nullptr) {
        N->height = 1 + std::max(getHeight(N->left), getHeight(N->right));
    }
}

// Funções de rotação da árvore AVL
AVLNode* AVLTree::rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

AVLNode* AVLTree::leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

int AVLTree::getBalance(AVLNode *N) {
     if (N == nullptr) return 0;
    return getHeight(N->left) - getHeight(N->right);
}

// Inserir um novo nó na árvore AVL
AVLNode* AVLTree::insert(AVLNode* node, std::string word, int page) {
    // Inserção normal de uma árvore de busca binária
    if (node == nullptr) return new AVLNode(word, page);

    if (word < node->word)
        node->left = insert(node->left, word, page);
    else if (word > node->word)
        node->right = insert(node->right, word, page);
    else {
        // The word already exists, add the page to the vector of pages if it's not already there
        auto it = std::lower_bound(node->pages.begin(), node->pages.end(), page);
        if (it == node->pages.end() || *it != page) { // Check if the page is not already in the vector
            node->pages.insert(it, page); // Insert the page at the correct sorted position
        }
        return node;
    }

    // Atualizar a altura do nó ancestral
    updateHeight(node);

    // Obter o fator de equilíbrio para verificar se este nó se tornou desequilibrado
    int balance = getBalance(node);

    // Se o nó se tornou desequilibrado, então há 4 casos

    // Left Left Case
    if (balance > 1 && word < node->left->word)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && word > node->right->word)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && word > node->left->word) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && word < node->right->word) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Retorna o ponteiro do nó (inalterado)
    return node;
}

void AVLTree::inOrder(AVLNode *root) {
    if (root != nullptr) {
        inOrder(root->left);
        std::cout << root->word << ": ";
        for (int page : root->pages) {
            std::cout << page << " ";
        }
        std::cout << std::endl;
        inOrder(root->right);
    }
}

// Construtor e destrutor da AVLTree
AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    // Implementação do destrutor para liberar a memória
    // ...
}

// Funções públicas da AVLTree
void AVLTree::insert(std::string word, int page) {
    root = insert(root, word, page);
}

void AVLTree::printInOrder() {
    inOrder(root);
}