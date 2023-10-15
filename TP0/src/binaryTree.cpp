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
        p->result  = obj.evaluate(expression, str); // Evaluate the expression using the ExpEvaluator object.
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
            //infix(root);
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

void BinaryTree::applyOperationRecursive(NodeType* p, char operation, int level) {
    if (p == nullptr || level == 0) {
        return;
    }

    // Recursively apply the operation to the child nodes
    applyOperationRecursive(p->left, operation, level - 1);
    applyOperationRecursive(p->right, operation, level - 1);

    // Store the result in the parent
    if (operation == 'a') {
        // AND operation
        std::cout << "AND OP" << std::endl;
        p->result = (p->left ? p->left->result : 0) & (p->right ? p->right->result : 0);
    } else if (operation == 'e') {
        // OR operation
        std::cout << "OR OP" << std::endl;
        p->result = (p->left ? p->left->result : 0) | (p->right ? p->right->result : 0);
    }
}

void BinaryTree::applyOperationsFromBottom(const std::string& operations) {
    int level = getHeight(root) - 1; // Start from the last level (the leaf nodes).

    for(int i = operations.length() - 1; i >= 0; i--) {
        std::cout << "LEVEL: " << level << std::endl;
        applyOperationRecursive(root, operations[i], level);
        level--;
    }   
}

std::string BinaryTree::evaluateRootChildren() {
    if (root == nullptr || root->left == nullptr || root->right == nullptr) {
        return "";  // Return an empty string if the tree or root's children are not properly initialized.
    }

    int leftResult = root->left->result;
    int rightResult = root->right->result;

    if (root->result == 0) {
        return "";  
    } else if (root->result == 1) {
        if (leftResult == 0 && rightResult == 1) {
            return getLeafItems(root->right, 1);  // If the left child's result is 0, return items of the right subtree with a result of 1.
        } else if (leftResult == 1 && rightResult == 0) {
            return getLeafItems(root->left, 1);  // If the right child's result is 0, return items of the left subtree with a result of 1.
        } else if (leftResult == 1 && rightResult == 1) {
            return getLeafItems(root, 1);  // If both children's results are 1, return items of all leaf nodes with a result of 1.
        }
    }
    
    return "";  // Default return an empty string.
}

std::string BinaryTree::getLeafItems(NodeType* p, int targetResult) {
    if (p == nullptr) {
        return "";
    }

    if (p->left == nullptr && p->right == nullptr && p->result == targetResult) {
        return p->item + " ";  // Return the item if it's a leaf node with the target result.
    } else {
        return getLeafItems(p->left, targetResult) + getLeafItems(p->right, targetResult);  // Recursively accumulate items from leaf nodes with the target result.
    }
}

void BinaryTree::printTree(NodeType* p, int indent) {
    if (p != nullptr) {
        if (p->right) {
            printTree(p->right, indent + 4);
        }
        if (indent > 0) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right) {
            std::cout << " /\n" << std::setw(indent) << ' ';
        }
        std::cout << p->item << "\n";
        if (p->left) {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            printTree(p->left, indent + 4);
        }
    }
}

void BinaryTree::printTree1(NodeType* p, int indent) {
     if (p != nullptr) {
        if (p->right) {
            printTree1(p->right, indent + 4);
        }
        if (indent > 0) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right) {
            std::cout << " /\n" << std::setw(indent) << ' ';
        }
        std::cout << p->result << "\n";
        if (p->left) {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            printTree1(p->left, indent + 4);
        }
    }
}

std::string BinaryTree::aNotation(std::string input) {
    std::stringstream ss(input);
    int num;
    
    // Try to extract a single number from the input
    if (ss >> num) {
        // Check if there are any other characters in the input
        char c;
        if (!(ss >> c)) {
            return input; // Return the input as is.
        }
    }

    // If there's more than one number or extra characters, perform the standard logic

    const int MAX_NUMBERS = 100;  // Maximum number of numbers supported
    int numbers[MAX_NUMBERS];
    int numCount = 0;

    ss.clear(); // Clear the stream state.
    ss.seekg(0); // Reset the stream position.

    while (ss >> num) {
        numbers[numCount++] = num;
    }

    if (numCount == 0) {
        return ""; // No numbers to combine.
    }

    int maxDigits = 0;

    // Find the maximum number of digits in the input numbers
    for (int i = 0; i < numCount; i++) {
        int digits = static_cast<int>(log10(numbers[i])) + 1;
        maxDigits = std::max(maxDigits, digits);
    }

    char result[maxDigits + 1];
    result[maxDigits] = '\0';  // Null-terminate the string

    // Initialize the result with spaces
    for (int i = 0; i < maxDigits; i++) {
        result[i] = ' ';
    }

    // Iterate over each digit position
    for (int digitPos = maxDigits - 1; digitPos >= 0; digitPos--) {
        char commonDigit = '\0';  // Initialize with an invalid value

        for (int i = 0; i < numCount; i++) {
            int divisor = static_cast<int>(pow(10, digitPos));
            int digit = (numbers[i] / divisor) % 10;

            if (commonDigit == '\0') {
                commonDigit = static_cast<char>(digit + '0');
            } else if (digit != (commonDigit - '0')) {
                commonDigit = 'a';
                break;
            }
        }

        result[maxDigits - digitPos - 1] = commonDigit;
    }

    return result;
}