//---------------------------------------------------------------------
// Arquivo      : binaryTree.cpp
// Conteudo     : Implementacao da lógica usada na árvore binária
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 12/10/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/binaryTree.hpp"
#include "../include/stacks.hpp"
#include "../include/expEvaluator.hpp"



BinaryTree::BinaryTree() {
    root = nullptr; // Initialize the root of the binary tree to null.
}

BinaryTree::~BinaryTree() {
    clear(root); // Destructor for BinaryTree, which clears the entire binary tree.
}

void BinaryTree::buildTree(std::string item) {
    buildRecursive(root, item, 0, nullptr);  // Public method to build the binary tree by calling the recursive buildRecursive function.
}

void BinaryTree::buildRecursive(NodeType* &p, std::string item, int pos, NodeType* parent = nullptr) {
    if (item[pos] == '\0') {
        p = new NodeType();
        p->item = item;
        p->left = nullptr;
        p->right = nullptr;
        p->parent = parent; // Set the parent reference
        return;
    }

    p = new NodeType();
    p->item = item;
    p->parent = parent; // Set the parent reference

    char c = item[pos];
    if (c == 'a' || c == 'e') {
        item[pos] = '0';
        buildRecursive(p->left, item, pos + 1, p); // Pass p as the parent
        item[pos] = '1';
        buildRecursive(p->right, item, pos + 1, p); // Pass p as the parent
    } else {
        buildRecursive(p, item, pos + 1, p); // Continue building the tree
    }
}


void BinaryTree::clear(NodeType* &p) {
    if (p != nullptr) {
        clear(p->left); // Recursively clear the left subtree.
        clear(p->right); // Recursively clear the right subtree.
        delete p; // Delete the current node.
        p = nullptr; // Set the pointer to null.
    }
}

void BinaryTree::traverseAndEvaluate(std::string expression, NodeType *p) {
    ExpEvaluator obj; // Create an object of the ExpEvaluator class for expression evaluation.

    if (p == nullptr) {
        std::cout << "A raíz é nula." << std::endl; // Print a message if the root node is null.
        return;
    }

    if (p->left == nullptr && p->right == nullptr) { // AVALIA AS FOLHAS DA ÁRVORE!!
        std::string str = p->item;
        int result = obj.evaluate(expression, str); // Evaluate the expression using the ExpEvaluator object.
        p->isAnswer = result;
    } else {
        traverseAndEvaluate(expression, p->left); // Recursively evaluate the left subtree.
        traverseAndEvaluate(expression, p->right); // Recursively evaluate the right subtree.
    }
}

NodeType* BinaryTree::getRoot() {
    return root; // Get the root of the binary tree.
}

void BinaryTree::traverse(int type) {
    switch (type) {
        case 1: // Prefix traversal
            prefix(root);
            break;
        case 2: // Infix traversal
            infix(root);
            break;
        case 3: // Postfix traversal
            postfix(root);
            break;
        case 4: // Level order traversal
            levelOrder();
            break;
        default:
            std::cerr << "Tipo de navegação inválido." << std::endl;
    }
}

void BinaryTree::prefix(NodeType* p) {
    if (p != nullptr) {
        std::cout << p->item << " ";
        prefix(p->left);
        prefix(p->right);
    }
}

void BinaryTree::infix(NodeType* p) {
    if (p != nullptr) {
        infix(p->left);
        std::cout << p->item << " ";
        infix(p->right);
    }
}

void BinaryTree::infix1(NodeType* p) {
    if (p != nullptr) {
        infix1(p->left);
        std::cout << p->isAnswer << " ";
        infix1(p->right);
    }
}

void BinaryTree::infix2(NodeType* p) {
    if (p != nullptr) {
        infix2(p->left);
        std::cout << p->result << " ";
        infix2(p->right);
    }
}

void BinaryTree::postfix(NodeType* p) {
    if (p != nullptr) {
        postfix(p->left);
        postfix(p->right);
        std::cout << p->item << " ";
    }
}

void BinaryTree::levelOrder() {
    int height = getHeight(root);
    for (int i = 1; i <= height; i++) {
        printLevel(root, i);
    }
}

int BinaryTree::getHeight(NodeType* node) {
    if (node == nullptr)
        return 0;

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

void BinaryTree::printLevel(NodeType* node, int level) {
    if (node == nullptr)
        return;

    if (level == 1)
        std::cout << node->item << " ";
    else if (level > 1) {
        printLevel(node->left, level - 1);
        printLevel(node->right, level - 1);
    }
}

std::string BinaryTree::extractEAndA(const std::string& input) {
    std::string eAndA;
    for (char c : input) {
        if (c == 'e' || c == 'a') {
            eAndA += c;
        }
    }
    return eAndA;
}

void BinaryTree::processOperations(NodeType* p, const std::string& eAndA) {
    if (p == nullptr) {
        return;
    }

    // Ensure eAndAIndex starts at the beginning of the string
    std::string::size_type eAndAIndex = 0;

    processOperations(p->left, eAndA);  // Recursively process left subtree
    processOperations(p->right, eAndA); // Recursively process right subtree

    if (p->left == nullptr && p->right == nullptr) {
        // Leaf node
        int leafValue = p->isAnswer;

        if (eAndAIndex < eAndA.length()) {
            char op = eAndA[eAndAIndex];
            eAndAIndex++;

            if (op == 'a') {
                // Perform & operation
                p->result = leafValue & 1;
            } else if (op == 'e') {
                // Perform | operation
                p->result = leafValue | 0;
            }
        }
    } else {
        // Internal node
        if (eAndAIndex < eAndA.length()) {
            char op = eAndA[eAndAIndex];
            eAndAIndex++;

            if (op == 'a') {
                // Perform & operation
                p->result = (p->left ? p->left->result : 0) & (p->right ? p->right->result : 0);
            } else if (op == 'e') {
                // Perform | operation
                p->result = (p->left ? p->left->result : 0) | (p->right ? p->right->result : 0);
            }
        }
    }
}

void BinaryTree::processString(const std::string& input) {
    std::string eAndA = extractEAndA(input);
    if (!eAndA.empty()) {
        processOperations(root, eAndA);
    }
}

std::string BinaryTree::evaluateRootChildren() {
    if (root == nullptr || root->left == nullptr || root->right == nullptr) {
        return "";  // Return an empty string if the tree or root's children are not properly initialized.
    }

    int leftResult = root->left->result;
    int rightResult = root->right->result;

    if (root->result == 0) {
        return "0";  // If both children's results are 0, return "0".
    } else if (root->result == 1) {
        if (leftResult == 0 && rightResult == 1) {
            return getLeafItems(root->right);  // If the left child's result is 0, return items of the right subtree.
        } else if (leftResult == 1 && rightResult == 0) {
            return getLeafItems(root->left);  // If the right child's result is 0, return items of the left subtree.
        } else if (leftResult == 1 && rightResult == 1) {
            return getLeafItems(root);  // If both children's results are 1, return items of all leaf nodes.
        }
    }
    
    return "";  // Default return an empty string.
}

std::string BinaryTree::getLeafItems(NodeType* p) {
    if (p == nullptr) {
        return "";
    }

    if (p->left == nullptr && p->right == nullptr) {
        return p->item + " ";  // Return the item if it's a leaf node.
    } else {
        return getLeafItems(p->left) + getLeafItems(p->right);  // Recursively accumulate items from leaf nodes.
    }
}
