#ifndef QUANTIFIEREVALUATOR_HPP
#define QUANTIFIEREVALUATOR_HPP

#include <string>
#include <cmath>
#include <iostream>
#include "Stacks.hpp"
#include "StringVector.hpp"
#include "ExpEvaluator.hpp"

// Classe que lida com a avaliação de uma expressão quando há quantificadores
class QuantifierEvaluator {
public:
    // Função para calcular o resultado final da expressão com quantificadores
    std::string calculateResult(std::string formula, std::string valuation);

private:
    // Função para gerar todas as possíveis possibilidades, dado um número x de quantificadores
    StringVector generateOutcomes(std::string formula, std::string& valuation);

    // Função para avaliar todas as possíveis possibilidades na expressão passada
    StringVector evaluateOutcomes(std::string formula, std::string valuation);

    // Função para gerar a expressão com 'P's de acordo com os operadores passados na valuação
    std::string generateExpressionP(std::string formula, std::string valuation);

    // Função para transformar a expressão em 'P's em números crescentes
    std::string generateExpression(std::string formulaP);

    // Função que, caso o valor de uma variável não importa, retorna 'a' no lugar da variável
    std::string switchToA(std::string valuation);
};

#endif // QUANTIFIEREVALUATOR_HPP