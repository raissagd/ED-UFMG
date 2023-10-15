//---------------------------------------------------------------------
// Arquivo      : binaryTree.hpp
// Conteudo     : arquivo de cabeçario de binaryTree.hpp
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 12/10/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
struct NodeType {
    std::string item;
    NodeType* left;
    NodeType* right;
    int result = -1; // initialize with something
    NodeType* parent; // Added parent reference
};

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();
    void buildTree(std::string item);
    void clear(NodeType* &p);
    void traverseAndEvaluate(std::string expression, NodeType *p);
    

    std::string evaluateRootChildren();
    std::string getLeafItems(NodeType* p, int targetResult);

    void printTree(NodeType* p, int indent);
    void printTree1(NodeType* p, int indent);

    std::string aNotation(std::string input);

    //void processString(const std::string& input);
    std::string extractEAndA(const std::string& input);

    void applyOperationRecursive(NodeType* p, char operation, int levelToApply);
    void applyOperationsFromBottom(const std::string& operations);
    
    NodeType* getRoot();

private:
    void buildRecursive(NodeType* &p, std::string item, int pos, NodeType* parent); // Remove default argument
    void traverse(int type);
    void prefix(NodeType* p);
    void postfix(NodeType* p);
    void levelOrder();
    int getHeight(NodeType* node);
    void printLevel(NodeType* node, int level);


    NodeType *root;
};

#endif
