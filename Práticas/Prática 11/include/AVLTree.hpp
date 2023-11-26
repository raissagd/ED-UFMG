#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "PageAVLTree.hpp"
#include <string>

class AVLNode {
public:
    std::string word;
    int height;
    AVLNode *left, *right;
    PageAVLTree pagesTree;

    AVLNode(const std::string &w, int page);
};

class AVLTree {
private:
    AVLNode* insert(AVLNode* node, const std::string &word, int page);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    int getBalance(AVLNode* N);
    int getHeight(AVLNode* N);
    void updateHeight(AVLNode* N);
    void inOrder(AVLNode* node);
    void freeNode(AVLNode* node);

public:
    AVLNode* root;

    AVLTree();
    ~AVLTree(); // Destructor to free memory
    void insert(const std::string &word, int page);
    void printInOrder();
};

#endif // AVL_TREE_HPP