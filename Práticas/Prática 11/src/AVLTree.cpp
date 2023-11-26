#include "../include/AVLTree.hpp"
#include <iostream>
#include <algorithm>

AVLNode::AVLNode(const std::string &w, int page) : word(w), height(1), left(nullptr), right(nullptr) {
    pagesTree.insert(page);
}

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    freeNode(root);
}

void AVLTree::freeNode(AVLNode* node) {
    if (node != nullptr) {
        freeNode(node->left);
        freeNode(node->right);
        delete node;
    }
}

int AVLTree::getHeight(AVLNode* N) {
    if (N == nullptr) return 0;
    return N->height;
}

void AVLTree::updateHeight(AVLNode* N) {
    N->height = std::max(getHeight(N->left), getHeight(N->right)) + 1;
}

AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

AVLNode* AVLTree::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

int AVLTree::getBalance(AVLNode* N) {
    if (N == nullptr) return 0;
    return getHeight(N->left) - getHeight(N->right);
}

AVLNode* AVLTree::insert(AVLNode* node, const std::string &word, int page) {
    if (node == nullptr) 
        return new AVLNode(word, page);

    if (word < node->word) 
        node->left = insert(node->left, word, page);
    else if (word > node->word) 
        node->right = insert(node->right, word, page);
    else {
        node->pagesTree.insert(page);
        return node;
    }

    updateHeight(node);

    int balance = getBalance(node);

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

    return node;
}

void AVLTree::insert(const std::string &word, int page) {
    root = insert(root, word, page);
}

void AVLTree::printInOrder() {
    inOrder(root);
}

void AVLTree::inOrder(AVLNode* node) {
    if (node != nullptr) {
        inOrder(node->left);
        std::cout << node->word << ": ";
        node->pagesTree.printInOrder();
        std::cout << std::endl;
        inOrder(node->right);
    }
}
