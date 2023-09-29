//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Implementacao do arquivo principal
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 23/09/2023 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <string>
#include "ExpEvaluator.hpp"
#include "QuantifierEvaluator.hpp"

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " -a/-s \"formula\" \"valuation\"" << std::endl;
        return 1;
    }

    std::string option = argv[1]; // opção: -a (avaliador de expressões) ou -s (satisfabilidade)
    std::string formula = argv[2]; // expressão avaliada
    std::string valuation = argv[3]; // valoração avaliada

    // Verifica se as strings não excedem os tamanhos máximos permitidos
    const int maxFormulaSize = 1000000; // Tamanho máximo para 'formula'
    const int maxValuationSize = 100;   // Tamanho máximo para 'valuation'

    if (formula.size() > maxFormulaSize || valuation.size() > maxValuationSize) {
        std::cerr << "Tamanho máximo excedido para formula ou valuação." << std::endl;
        return 1;
    }

    if (option == "-a") {
        // Avaliador de expressão lógica
        ExpEvaluator obj;

        try {
            int result = obj.evaluate("noQuant", formula, valuation); // chama a função para avaliar a expressão
            std::cout << "Result: " << result << std::endl;
        } catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

    } else if (option == "-s") {
        // Problema de satisfabilidade
        QuantifierEvaluator obj;

        std::string result = obj.calculateResult(formula, valuation); // chama a função para avaliar a expressão com quantificadores
        std::cout << "Result: " << result << std::endl;

    } else {
        std::cerr << "Opção inválida. Exemplo de entrada: ./bin/main -a '0 | 1 & 2' 010" << std::endl;
        return 1;
    }
    
    return 0;
}