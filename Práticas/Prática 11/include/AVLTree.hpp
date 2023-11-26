#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <string>
#include <vector>

struct AVLNode {
    std::string word;
    std::vector<int> pages;
    int height;
    AVLNode *left;
    AVLNode *right;

    AVLNode(std::string w, int page);
};

class AVLTree {
private:
    AVLNode *root;

    AVLNode* insert(AVLNode* node, std::string word, int page);
    AVLNode* rightRotate(AVLNode *y);
    AVLNode* leftRotate(AVLNode *x);
    int getHeight(AVLNode *N);
    void updateHeight(AVLNode *N);
    int getBalance(AVLNode *N);
    void inOrder(AVLNode *root);

public:
    AVLTree();
    ~AVLTree();
    void insert(std::string word, int page);
    void printInOrder();
    // Declarar outras funções públicas aqui, se necessário.
};

#endif // AVL_TREE_HPP