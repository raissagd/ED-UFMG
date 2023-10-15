//---------------------------------------------------------------------
// Arquivo      : binaryTree.cpp
// Conteúdo     : Implementação da lógica usada na árvore binária
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Histórico    : 12/10/2023 - arquivo criado
//---------------------------------------------------------------------

#include "../include/binaryTree.hpp"
#include "../include/stacks.hpp"
#include "../include/expEvaluator.hpp"

BinaryTree::BinaryTree() {
    root = nullptr; // Inicializa a raiz da árvore binária como nula.
}

BinaryTree::~BinaryTree() {
    clear(root); // Destrutor para BinaryTree, que limpa toda a árvore binária.
}

void BinaryTree::buildTree(std::string item) {
    buildRecursive(root, item, 0, nullptr);  // Método público para construir a árvore binária chamando a função recursiva buildRecursive.
}

void BinaryTree::buildRecursive(NodeType* &p, std::string item, int pos, NodeType* parent = nullptr) {
    if (item[pos] == '\0') {
        p = new NodeType();
        p->item = item;
        p->left = nullptr;
        p->right = nullptr;
        p->parent = parent; // Define a referência para o pai
        return;
    }

    p = new NodeType();
    p->item = item;
    p->parent = parent; // Define a referência para o pai

    char c = item[pos];
    if (c == 'a' || c == 'e') {
        item[pos] = '0';
        buildRecursive(p->left, item, pos + 1, p); // Passa p como pai
        item[pos] = '1';
        buildRecursive(p->right, item, pos + 1, p); // Passa p como pai
    } else {
        buildRecursive(p, item, pos + 1, p); // Continua a construção da árvore
    }
}

void BinaryTree::clear(NodeType* &p) {
    if (p != nullptr) {
        clear(p->left); // Limpa recursivamente a subárvore esquerda.
        clear(p->right); // Limpa recursivamente a subárvore direita.
        delete p; // Exclui o nó atual.
        p = nullptr; // Define o ponteiro como nulo.
    }
}

void BinaryTree::traverseAndEvaluate(std::string expression, NodeType *p) {
    ExpEvaluator obj; // Cria um objeto da classe ExpEvaluator para avaliação da expressão.

    if (p == nullptr) {
        std::cout << "A raiz é nula." << std::endl; // Imprime uma mensagem se o nó raiz for nulo.
        return;
    }

    if (p->left == nullptr && p->right == nullptr) { // AVALIA AS FOLHAS DA ÁRVORE!! (nós que contém as possibilidades)
        std::string str = p->item;
        p->result  = obj.evaluate(expression, str); // Avalia cada possibilidade usando o objeto ExpEvaluator, e salva se aquela possibilidade satisfaz a equação
    } else {
        traverseAndEvaluate(expression, p->left); // Avalia recursivamente a subárvore esquerda.
        traverseAndEvaluate(expression, p->right); // Avalia recursivamente a subárvore direita.
    }
}

NodeType* BinaryTree::getRoot() {
    return root; // Obtém a raiz da árvore
}

// Obtem a altura da árvore
int BinaryTree::getHeight(NodeType* node) {
    if (node == nullptr)
        return 0;

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// Extrai os quantificadores da valoração passada e transforma em uma string
std::string BinaryTree::extractEAndA(const std::string& input) {
    std::string eAndA;
    for (char c : input) {
        if (c == 'e' || c == 'a') {
            eAndA += c;
        }
    }
    return eAndA;
}

// Aplica uma operação específica para todos os pares de nós de um nível
void BinaryTree::applyOperationRecursive(NodeType* p, char operation, int level) {
    if (p == nullptr || level == 0) {
        return;
    }

    // Aplica a operação recursivamente aos nós filhos
    applyOperationRecursive(p->left, operation, level - 1);
    applyOperationRecursive(p->right, operation, level - 1);

    // Armazena o resultado no pai
    if (operation == 'a') {
        // Operação AND
        p->result = (p->left ? p->left->result : 0) & (p->right ? p->right->result : 0);
    } else if (operation == 'e') {
        // Operação OR
        p->result = (p->left ? p->left->result : 0) | (p->right ? p->right->result : 0);
    }
}

void BinaryTree::applyOperationsFromBottom(const std::string& operations) {
    int level = getHeight(root) - 1; // Começa a partir do último nível (os nós folha).

    for(int i = operations.length() - 1; i >= 0; i--) {
        applyOperationRecursive(root, operations[i], level);
        level--;
    }   
}

std::string BinaryTree::evaluateRootChildren() {
    if (root == nullptr || root->left == nullptr || root->right == nullptr) {
        return "";  // Retorna uma string vazia se a árvore ou os filhos da raiz não estiverem inicializados corretamente.
    }

    int leftResult = root->left->result;
    int rightResult = root->right->result;

    if (root->result == 0) {
        return "";  
    } else if (root->result == 1) {
        if (leftResult == 0 && rightResult == 1) {
            return getLeafItems(root->right, 1);  // Se o resultado do filho esquerdo for 0, retorne os itens da subárvore direita com um resultado de 1.
        } else if (leftResult == 1 and rightResult == 0) {
            return getLeafItems(root->left, 1);  // Se o resultado do filho direito for 0, retorne os itens da subárvore esquerda com um resultado de 1.
        } else if (leftResult == 1 and rightResult == 1) {
            return getLeafItems(root, 1);  // Se o resultado de ambos os filhos for 1, retorne os itens de todos os nós folha com resultado 1.
        }
    }
    
    return "";  // Retorna uma string vazia padrão.
}

std::string BinaryTree::getLeafItems(NodeType* p, int targetResult) {
    if (p == nullptr) {
        return "";
    }

    if (p->left == nullptr and p->right == nullptr and p->result == targetResult) {
        return p->item + " ";  // Retorna o item se for um nó folha com o resultado desejado.
    } else {
        return getLeafItems(p->left, targetResult) + getLeafItems(p->right, targetResult);  // Acumula recursivamente itens de nós folha com o resultado desejado.
    }
}

std::string BinaryTree::aNotation(std::string input) {
    std::stringstream ss(input);
    int num;
    
    // Tenta extrair um único número da entrada
    if (ss >> num) {
        // Verifica se há outros caracteres na entrada
        char c;
        if (!(ss >> c)) {
            return input; // Retorna a entrada como está, caso só haja uma resposta
        }
    }

    // Se houver mais de um número ou caracteres extras, execute a lógica padrão

    const int MAX_NUMBERS = 1000;
    int numbers[MAX_NUMBERS];
    int numCount = 0;

    ss.clear(); // Limpa o estado do fluxo.
    ss.seekg(0); // Redefine a posição do fluxo.

    while (ss >> num) {
        numbers[numCount++] = num;
    }

    if (numCount == 0) {
        return ""; // Nenhum número para combinar.
    }

    int maxDigits = 0;

    // Encontra o número máximo de dígitos nos números de entrada
    for (int i = 0; i < numCount; i++) {
        int digits = static_cast<int>(log10(numbers[i])) + 1;
        maxDigits = std::max(maxDigits, digits);
    }

    char result[maxDigits + 1];
    result[maxDigits] = '\0';  // Termina a string com nulo

    // Inicializa o resultado com espaços
    for (int i = 0; i < maxDigits; i++) {
        result[i] = ' ';
    }

    // Itera sobre cada posição de dígito
    for (int digitPos = maxDigits - 1; digitPos >= 0; digitPos--) {
        char commonDigit = '\0';  // Inicializa com um valor inválido

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
