//---------------------------------------------------------------------
// Arquivo      : binaryTree.hpp
// Conteúdo     : Arquivo de cabeçalho para a classe BinaryTree
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Histórico    : 12/10/2023 - Arquivo criado
//---------------------------------------------------------------------

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

// Estrutura dos nós da árvore
struct NodeType {
    std::string item; 
    NodeType* left; // ponteiro para o nó da esquerda
    NodeType* right; // ponteiro para o nó da direita
    int result = -1; // armazena se é resultado ou não
    NodeType* parent; // ponteiro para o pai
};

// Classe árvore binária
class BinaryTree {
public:
    BinaryTree(); // Construtor da classe BinaryTree.
    ~BinaryTree(); // Destrutor da classe BinaryTree.
    void buildTree(std::string item); // Método para construir a árvore.
    void clear(NodeType* &p); // Método para limpar a árvore.
    void traverseAndEvaluate(std::string expression, NodeType *p); // Método para avaliar se as possibilidads satisfazem a expressão.
    std::string evaluateRootChildren(); // Método para avaliar as folhas da árvore.
    std::string aNotation(std::string input); // Método para a utilizar notação 'a' nas respostas.
    std::string extractEAndA(const std::string& input); // Método para extrair os quantificadores da valoração.
    void applyOperationsFromBottom(const std::string& operations); // Método para aplicar operações, linha a linha, de baixo para cima.
    
    NodeType* getRoot(); // Método para obter a raiz da árvore.

private:
    void buildRecursive(NodeType* &p, std::string item, int pos, NodeType* parent); // Função para construir a árvore de forma recursiva.
    int getHeight(NodeType* node); // Função para obter a altura da árvore.
    std::string getLeafItems(NodeType* p, int targetResult); // Função para obter os itens dos nós folha com um resultado específico.
    void applyOperationRecursive(NodeType* p, char operation, int levelToApply); // Função para aplicar operações de forma recursiva.

    NodeType *root; // A raiz da árvore binária.
};

#endif