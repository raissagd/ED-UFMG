//---------------------------------------------------------------------
// Arquivo      : expEvaluator.hpp
// Conteudo     : arquivo de cabeçario de expEvaluator.hpp
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 23/09/2023 - arquivo criado
//---------------------------------------------------------------------

#ifndef EXP_EVALUATOR_HPP
#define EXP_EVALUATOR_HPP

#include <iostream>
#include <string>
#include <cmath>
#include "Stacks.hpp"
#include "StringVector.hpp"

// Classe que lida com a avaliação de uma expressão
class ExpEvaluator {
public:
    // Avalia uma expressão lógica com base em uma valoração
    static int evaluate(std::string option, std::string exp, std::string values);

    // Conta o número de variáveis na expressão
    static int countVariables(const std::string& exp);

private:
    // Inicializa os valores das variáveis com base na valoração
    static void initializeVariableValues(const std::string& values, int variableValues[]);

    // Lida com números com mais de um dígito na expressão
    static size_t handleMultiDigitNumber(const std::string& exp, size_t i, NumStack& operands, int variableValues[]);

    // Lida com o caractere ')' na expressão
    static void handleClosingParenthesis(NumStack& operands, CharStack& operations);

    // Lida com operadores lógicos na expressão
    static void handleOperator(char c, NumStack& operands, CharStack& operations);

    // Realiza uma operação lógica
    static int performOperation(NumStack& operands, CharStack& operations);

    // Determina a precedência de um operador
    static int precedence(char c);

    // Verifica se um caractere é um operador lógico válido
    static bool isOperator(char c);

    // Verifica se um caractere é um dígito numérico
    static bool isDigit(char c);
};

#endif // EXP_EVALUATOR_HPP