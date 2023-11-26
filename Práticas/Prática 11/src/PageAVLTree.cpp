#include "../include/PageAVLTree.hpp"
#include <algorithm>
#include <iostream>

PageAVLNode::PageAVLNode(int p) : page(p), height(1), left(nullptr), right(nullptr) {}

PageAVLTree::PageAVLTree() : root(nullptr) {}

PageAVLTree::~PageAVLTree() {
    freeNode(root);
}

void PageAVLTree::freeNode(PageAVLNode* node) {
    if (node != nullptr) {
        freeNode(node->left);
        freeNode(node->right);
        delete node;
    }
}

int PageAVLTree::getHeight(PageAVLNode* N) {
    if (N == nullptr) return 0;
    return N->height;
}

void PageAVLTree::updateHeight(PageAVLNode* N) {
    N->height = std::max(getHeight(N->left), getHeight(N->right)) + 1;
}

PageAVLNode* PageAVLTree::rightRotate(PageAVLNode* y) {
    PageAVLNode* x = y->left;
    PageAVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

PageAVLNode* PageAVLTree::leftRotate(PageAVLNode* x) {
    PageAVLNode* y = x->right;
    PageAVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

int PageAVLTree::getBalance(PageAVLNode* N) {
    if (N == nullptr) return 0;
    return getHeight(N->left) - getHeight(N->right);
}

PageAVLNode* PageAVLTree::insert(PageAVLNode* node, int page) {
    if (node == nullptr) return new PageAVLNode(page);

    if (search(root, page)) {
        return node;
    }

    if (page < node->page) {
        node->left = insert(node->left, page);
    } else if (page > node->page) {
        node->right = insert(node->right, page);
    }

    updateHeight(node);

    int balance = getBalance(node);

    if (balance > 1 && page < node->left->page) {
        return rightRotate(node);
    }
    if (balance < -1 && page > node->right->page) {
        return leftRotate(node);
    }
    if (balance > 1 && page > node->left->page) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && page < node->right->page) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void PageAVLTree::insert(int page) {
    root = insert(root, page);
}

void PageAVLTree::printInOrder() {
    inOrder(root);
}

void PageAVLTree::inOrder(PageAVLNode* node) {
    if (node != nullptr) {
        inOrder(node->left);
        std::cout << node->page << " ";
        inOrder(node->right);
    }
}

PageAVLNode* PageAVLTree::search(PageAVLNode* node, int page) {
    if (node == nullptr || node->page == page)
        return node;

    if (node->page < page)
        return search(node->right, page);

    return search(node->left, page);
}

bool PageAVLTree::search(int page) {
    return search(root, page) != nullptr;
}