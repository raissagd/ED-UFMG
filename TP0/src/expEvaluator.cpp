//---------------------------------------------------------------------
// Arquivo      : expEvaluator.cpp
// Conteudo     : Implementacao da lógica para avaliar uma expressão dada uma valoração
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 23/09/2023 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include "expEvaluator.hpp"

int ExpEvaluator::evaluate(std::string option, std::string exp, std::string values) {
    int variableValues[100]; // Supondo que pode haver até 100 variáveis (0 a 99)

    // Contagem do número de variáveis na expressão
    int numVariables = countVariables(exp);

    // noQuant foi só uma maneira de diferenciar se a expressão passada vai ou não ter quantificadores
    // já que essa função de avaliação é usada para ambos os casos
    if(option == "noQuant") {
        for (char c : values) {
            if (std::isalpha(c)) {
                throw std::runtime_error("Não pode haver quantificadores na valuação.");
            }
        }

        // Verificação se o número de variáveis na expressão corresponde ao número na valoração
        if (numVariables != static_cast<int>(values.length())) {
            throw std::runtime_error("O número de variáveis na expressão não corresponde à valoração.");
        }
    }
    
    // Inicialização dos valores das variáveis
    initializeVariableValues(values, variableValues);

    NumStack operands;    // Pilha de operandos
    CharStack operations; // Pilha de operadores

    for (size_t i = 0; i < exp.length(); ++i) {
        char c = exp[i];

        if (isspace(c)) {
            // Ignora caracteres de espaço em branco
            continue;
        }

        if (isDigit(c)) {
            // Lidar com números com mais de um dígito
            i = handleMultiDigitNumber(exp, i, operands, variableValues);
        } else if (c == '(') {
            // Lidar com o caractere '('
            operations.push(c);
        } else if (c == ')') {
            // Lidar com o caractere ')'
            handleClosingParenthesis(operands, operations);
        } else if (isOperator(c)) {
            // Lidar com operadores lógicos
            handleOperator(c, operands, operations);
        }
    }

    while (!operations.isEmpty()) {
        // Realizar operações pendentes
        int output = performOperation(operands, operations);
        operands.push(output);
    }

    // O resultado final é o topo da pilha de operandos
    return operands.peek();
}

// Contar o número de variáveis na expressão
int ExpEvaluator::countVariables(const std::string& exp) {
    int numVariables = 0;
    for (size_t i = 0; i < exp.length(); ++i) {
        char c = exp[i];
        if (isDigit(c)) {
            while (i < exp.length() && isDigit(exp[i])) {
                i++;
            }
            numVariables++;
            i--;
        }
    }
    return numVariables;
}

// Inicializar o valor das variáveis na expressão baseado os valores da valoração
void ExpEvaluator::initializeVariableValues(const std::string& values, int variableValues[]) {
    for (size_t i = 0; i < values.length(); i++) {
        variableValues[i] = values[i] - '0';
    }
}

size_t ExpEvaluator::handleMultiDigitNumber(const std::string& exp, size_t i, NumStack& operands, int variableValues[]) {
    int num = 0;
    while (i < exp.length() && isDigit(exp[i])) {
        num = num * 10 + (exp[i] - '0');
        i++;
    }
    i--; // Decrementa i (contabiliza o último caractere lido)
    operands.push(variableValues[num]);
    return i;
}

void ExpEvaluator::handleClosingParenthesis(NumStack& operands, CharStack& operations) {
    while (!operations.isEmpty() && operations.peek() != '(') {
        // Realizar operações até encontrar um '('
        int output = performOperation(operands, operations);
        operands.push(output);
    }
    operations.pop(); // Remove '(' da pilha de operadores
}

void ExpEvaluator::handleOperator(char c, NumStack& operands, CharStack& operations) {
    while (!operations.isEmpty() && precedence(c) <= precedence(operations.peek())) {
        // Realizar operações até encontrar um operador de menor prioridade ou igual
        int output = performOperation(operands, operations);
        operands.push(output);
    }
    operations.push(c); // Empilhar o novo operador
}

int ExpEvaluator::performOperation(NumStack& operands, CharStack& operations) {
    int a = operands.peek();
    operands.pop();
    char operation = operations.peek();
    operations.pop();

    if (operation == '~') {
        return !a; // Operação de negação lógica
    }

    int b = operands.peek();
    operands.pop();

    if (operation == '&') {
        return b && a; // Operação lógica "E"
    } else if (operation == '|') {
        return b || a; // Operação lógica "OU"
    }

    throw std::runtime_error("Operador desconhecido: " + operation);
}

int ExpEvaluator::precedence(char c) {
    switch (c) {
        case '~':
            return 3; // Prioridade mais alta para negação lógica
        case '&':
            return 2; // Prioridade intermediária para "E"
        case '|':
            return 1; // Prioridade mais baixa para "OU"
    }
    return -1; // Procedimento padrão para operadores desconhecidos
}

bool ExpEvaluator::isOperator(char c) {
    return (c == '&' || c == '|' || c == '~'); // Verifica se é um operador válido
}

bool ExpEvaluator::isDigit(char c) {
    return (c >= '0' && c <= '9'); // Verifica se é um dígito numérico
}