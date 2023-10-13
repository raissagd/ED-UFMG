//---------------------------------------------------------------------
// Arquivo      : quantifierEvaluator.cpp
// Conteudo     : Implementacao da lógica para avaliar expressões com quantificadores
// Autor        : Raissa Gonçalves Diniz (raissagdiniz@gmail.com)
// Historico    : 23/09/2023 - arquivo criado
//---------------------------------------------------------------------
#include "../include/quantifierEvaluator.hpp"

// Função para calcular todos os possíveis resultados binários, dado n quantificadores
StringVector QuantifierEvaluator::generateOutcomes(std::string formula, std::string& valuation) {
    ExpEvaluator obj;
    StringVector outcomes; // Vetor com todos os possíveis resultados
    int numLetters = 0;

    // Conta o número de letras (quantificadores) na string de valuação
    for (char c : valuation) {
        if (c == 'e' || c == 'a') {
            numLetters++;
        } 
    }

    // Não pode haver mais de 5 quantificadores (especificação do enunciado)
    if (numLetters > 5) {
        throw std::runtime_error("O número de quantificadores não pode ser maior que 5.");
    }

    // Verificação se o número de variáveis na expressão corresponde ao número na valoração
    int numVariables = obj.countVariables(formula);
    if (numVariables != static_cast<int>(valuation.length())) {
        throw std::runtime_error("O número de variáveis na expressão não corresponde à valoração.");
    }

    // Para o problema de satisfabilidade, precisam existir quantificadores
    if (numLetters == 0) {
        throw std::runtime_error("A expressão deve conter quantificadores.");
    }
 
    // Calcular a quantidade de possíveis saídas (2^numLetters)
    int numOutcomes = pow(2, numLetters);

    // Gerar todos os resultados possíveis, substituindo 'e' e/ou 'a' por valores binários 
    for (int i = 0; i < numOutcomes; i++) {
        std::string outcome = valuation;
        int value = i;
        
        for (std::string::size_type j = 0; j < valuation.size(); j++) {
            if (valuation[j] == 'e' || valuation[j] == 'a') {
                outcome[j] = '0' + (value % 2);
                value /= 2;
            }
        }
        outcomes.push_back(outcome); // Adiciona ao vetor de resultados
    }

    // Ordena o vetor de resultados em ordem crescente
    outcomes.sort();

    return outcomes;
}

// Avalia cada um dos possíveis resultados na expressão e verifica se algum deles a torna verdadeira
StringVector QuantifierEvaluator::evaluateOutcomes(std::string formula, std::string valuation) {
    StringVector outcomes = generateOutcomes(formula, valuation); // Gera os outcomes
    ExpEvaluator obj; // Usa o método de avaliação de expressões para isso
    StringVector results; // Vetor para armazenar os resultados do avaliador (0 ou 1)

    for (std::string::size_type i = 0; i < outcomes.getSize(); i++) {
        int result = obj.evaluate("quant", formula, outcomes[i]); // Avalia cada possibilidade
        std::string resultStr = std::to_string(result); // Converte de int para string
        results.push_back(resultStr);
    }

    return results;
}

// Gera a expressão lógica baseada nos quantificadores
std::string QuantifierEvaluator::generateExpressionP(std::string formula, std::string valuation) {
    try {
        StringVector possibilities = generateOutcomes(formula, valuation);
        StringVector results = evaluateOutcomes(formula, valuation);

        std::string seqA = "P & P"; // Sequência para o quantificador 'a'
        std::string seqE = "P | P";  // Sequência para o quantificador 'e'
        std::string initialExpression = "P";
        //std::string firstPExp = "";

        StringVector quantifiers;
        for (char c : valuation) {
            if (std::isalpha(c)) {
                // Converte a letra para uma string e adiciona no vetor de quantificadores
                quantifiers.push_back(std::string(1, c));
            }
        }

        for (size_t k = 0; k < quantifiers.getSize(); k++) {
            std::string nextQuant = quantifiers[k]; // Pega o próximo quantificador
            std::string newExpression = "";

            size_t pos = initialExpression.find("P"); // Acha a posição de 'P' na expressão inicial
            size_t prevPos = 0;

            while (pos != std::string::npos) {
                newExpression += initialExpression.substr(prevPos, pos - prevPos); // Anexa caracteres antes de 'P'

                if (nextQuant == "e") {
                    newExpression += seqE; // Concatena seqE a newExpression
                } else if (nextQuant == "a") {
                    newExpression += seqA; // Concatena seqA a newExpression
                }

                prevPos = pos + 1; // Atualiza a posição anterior
                pos = initialExpression.find("P", prevPos); // Encontra o próximo 'P' na expressão restante
            }
            newExpression += initialExpression.substr(prevPos); // Anexa qualquer caractere restante na expressão inicial
            initialExpression = newExpression; // Atualiza initialExpression para o próximo quantificador

             /* if (k == 0) {
                firstPExp = initialExpression;
            } */
        }
        //std::cout << firstPExp << std::endl; 
        //std::cout << initialExpression << std::endl;
        return initialExpression; // Retorna o resultado final
    } catch (const std::runtime_error& e) {
        return std::string(e.what());
    }
}

// Gera a expressão com números em vez de 'P's
std::string QuantifierEvaluator::generateExpression(std::string formulaP) {
    unsigned int currentNum = 0;  // Inicializa o número atual como 0

    for (unsigned int i = 0; i < formulaP.length(); i++) {
        if (formulaP[i] == 'P') {
            formulaP[i] = '0' + currentNum; // Substitui 'P' pelo número atual
            currentNum++; // Incrementa o número atual
        }
    }

    return formulaP;
}

// Função que, caso o valor de uma variável não importa, retorna 'a' no lugar da variável
std::string QuantifierEvaluator::switchToA(std::string answerString) {
     std::string compactedAnswer = "";
    std::string currentAnswer;

    std::istringstream iss(answerString);

    while (iss >> currentAnswer) {
        if (compactedAnswer.empty()) {
            compactedAnswer = currentAnswer;
        } else {
            for (size_t i = 0; i < currentAnswer.length(); i++) {
                if (i >= compactedAnswer.length() || (currentAnswer[i] != compactedAnswer[i] && currentAnswer[i] != 'a')) {
                    compactedAnswer[i] = 'a';
                }
            }
        }
    }

    return compactedAnswer;
}

// Calcula o resultado final da expressão quantificada
std::string QuantifierEvaluator::calculateResult(std::string formula, std::string valuation) {
    try {
        std::string pFormula = generateExpressionP(formula, valuation);
        std::string expression = generateExpression(pFormula);
        std::string finalResult = "0"; // Resultado padrão é "0"

        // Avalia todos os resultados
        StringVector evaluationResults = evaluateOutcomes(formula, valuation);

        // Encontra e avalia os resultados com um valor de 1
        ExpEvaluator obj;
        StringVector outcomes = generateOutcomes(formula, valuation);

        // Cria uma cópia da expressão para trabalhar com ela
        std::string modifiedExpression = expression;

        // Substitui cada número na string de expressão modificada por uma linha de evaluationResults
        for (size_t i = 0; i < evaluationResults.getSize(); ++i) {
            // Substitui a i-ésima ocorrência de um número na expressão modificada pela linha correspondente
            size_t found = modifiedExpression.find(std::to_string(i));
            while (found != std::string::npos) {
                modifiedExpression.replace(found, 1, evaluationResults[i]);
                found = modifiedExpression.find(std::to_string(i), found + evaluationResults[i].length());
            }
        }

        // Concatena todos os elementos de evaluationResults em uma única string
        std::string concatenatedResults = "";
        for (size_t i = 0; i < evaluationResults.getSize(); ++i) {
            std::string currentNumber = std::to_string(i);
            size_t found = modifiedExpression.find(currentNumber);
            while (found != std::string::npos) {
                concatenatedResults += currentNumber;
                found = modifiedExpression.find(currentNumber, found + currentNumber.length());
            }
        }

        // Passa a expressão modificada para a função obj.evaluate
        int evaluationResult = obj.evaluate("quant", modifiedExpression, concatenatedResults);

        // Define finalResult com base no resultado da avaliação
        if (evaluationResult == 0) {
            finalResult = "0";
            } else {
                finalResult = "1";

                
            // Contar os caracteres na string expression
            int expressionLength = expression.length();

            // Encontrar o caractere do meio
            size_t middleIndex = expressionLength / 2;

            // Dividir a string em duas partes
            //std::cout << modifiedExpression << std::endl; 
            std::string firstHalf = modifiedExpression.substr(0, middleIndex);
             //std::cout << firstHalf << std::endl; 
            std::string middleCharacter = modifiedExpression.substr(middleIndex, 1);
             //std::cout << middleCharacter << std::endl; 
            std::string secondHalf = modifiedExpression.substr(middleIndex + 2);
             //std::cout << secondHalf << std::endl; 


            int concatenatedResultsLength = concatenatedResults.length();

            // Encontrar o caractere do meio
            int middleIndexConcatenated = concatenatedResultsLength / 2;

            // Dividir a string em duas partes
            //std::cout << concatenatedResults << std::endl; 
            std::string firstHalfConcatenated = concatenatedResults.substr(0, middleIndexConcatenated);
            //std::cout << firstHalfConcatenated << std::endl; 
            std::string secondHalfConcatenated = concatenatedResults.substr(middleIndexConcatenated);
            //std::cout << secondHalfConcatenated << std::endl; 

            int evaluationResult1 = obj.evaluate("quant", firstHalf, firstHalfConcatenated);
            //std::cout << evaluationResult1 << std::endl; 
            int evaluationResult2 = obj.evaluate("quant", secondHalf, secondHalfConcatenated);
            //std::cout << evaluationResult2 << std::endl; 

            if(evaluationResult1 == 1 && evaluationResult2 == 1) {
                std::string outcomesConcatenated = "";
                    for (size_t i = 0; i < outcomes.getSize(); ++i) {
                        if (evaluationResults[i] == "1") {
                            outcomesConcatenated += outcomes[i] + " ";
                        }
                    }

                    // Remove the trailing space if there is any outcome
                    if (!outcomesConcatenated.empty()) {
                        outcomesConcatenated.pop_back();
                    }

                    std::string answer = switchToA(outcomesConcatenated);

                    // Append the concatenated outcomes to finalResult
                    finalResult += " " + answer;

            } else if (evaluationResult1 == 1 && evaluationResult2 == 0) {
                std::string outcomesConcatenated = "";
                    for (size_t i = 0; i < middleIndex; ++i) {
                        if (evaluationResults[i] == "1") {
                            outcomesConcatenated += outcomes[i] + " ";
                        }
                    }

                    // Remove the trailing space if there is any outcome
                    if (!outcomesConcatenated.empty()) {
                        outcomesConcatenated.pop_back();
                    }

                    // Append the concatenated outcomes to finalResult
                     std::string answer = switchToA(outcomesConcatenated);

                    // Append the concatenated outcomes to finalResult
                    finalResult += " " + answer;

            } else if (evaluationResult1 == 0 && evaluationResult2 == 1) {
                std::string outcomesConcatenated = "";
                    for (size_t i = outcomes.getSize() / 2;  i < outcomes.getSize(); ++i) {
                        if (evaluationResults[i] == "1") {
                            outcomesConcatenated += outcomes[i] + " ";
                        }
                    }

                    // Remove the trailing space if there is any outcome
                    if (!outcomesConcatenated.empty()) {
                        outcomesConcatenated.pop_back();
                    }

                    // Append the concatenated outcomes to finalResult
                     std::string answer = switchToA(outcomesConcatenated);

                    // Append the concatenated outcomes to finalResult
                    finalResult += " " + answer;
            }
        }
        //return switchToA(finalResult);
        return finalResult;
    } catch (const std::runtime_error& e) {
        return std::string(e.what());
    }
}