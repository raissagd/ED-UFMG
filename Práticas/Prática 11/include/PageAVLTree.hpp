#ifndef PAGE_AVL_TREE_HPP
#define PAGE_AVL_TREE_HPP

class PageAVLNode {
public:
    int page;
    int height;
    PageAVLNode *left, *right;

    explicit PageAVLNode(int p);
};

class PageAVLTree {
private:
    PageAVLNode* insert(PageAVLNode* node, int page);
    PageAVLNode* rightRotate(PageAVLNode* y);
    PageAVLNode* leftRotate(PageAVLNode* x);
    int getBalance(PageAVLNode* N);
    int getHeight(PageAVLNode* N);
    void updateHeight(PageAVLNode* N);
    void inOrder(PageAVLNode* node);
    void freeNode(PageAVLNode* node);
    PageAVLNode* search(PageAVLNode* node, int page);
    bool search(int page);

public:
    PageAVLNode* root;

    PageAVLTree();
    ~PageAVLTree(); 
    void insert(int page);
    void printInOrder();
};

#endif // PAGE_AVL_TREE_HPP