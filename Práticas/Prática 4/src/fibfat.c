//---------------------------------------------------------------------
// Arquivo      : fibfat.c
// Conteudo     : implementação das funções Fibonnaci (iterativo e recursivo) e Fatorial (iterativo e recursivo)
// Autor	: Raissa Diniz
// Historico	: 2023-08-31 - arquivo criado
//---------------------------------------------------------------------

// Para o algoritmo recursivo, insira, na chamada recursiva, uma função que consuma recursos computacionais 
// (por exemplo calcule o seno de um número 1 milhão de vezes), e repita as medições do item 5.


#include "../include/fibfat.h"

static int recurso = 0;

unsigned long long iterativeFactorial(int n) {
        if (n < 0) {
            return 0; 
        }
        
        unsigned long long resultado = 1;
        for (int i = 1; i <= n; i++) {
            resultado *= i;
        }
        return resultado;
    }

unsigned long long recursiveFactorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        // Função que consome recursos computacionais (cálculo do seno)
        double seno_atual = sin(recurso);
        double result = 0.0; 
        for (int i = 1; i <= 1000000; i++) {
            result += seno_atual; 
        }
        
        recurso++;
        return n * recursiveFactorial(n - 1);
    }
}


unsigned long long iterativeFibonacci(int n) {
        if (n <= 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            unsigned long long fibNMinus2 = 0;
            unsigned long long fibNMinus1 = 1;
            unsigned long long fibN = 0;
            
            for (int i = 2; i <= n; i++) {
                fibN = fibNMinus1 + fibNMinus2;
                fibNMinus2 = fibNMinus1;
                fibNMinus1 = fibN;
            }
            
            return fibN;
        }
    }

unsigned long long recursiveFibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        // Função que consome recursos computacionais (cálculo do seno)
        double seno_atual = sin(recurso);
        double result = 0.0; 
        for (int i = 1; i <= 1000000; i++) {
            result += seno_atual; 
        }
        
        recurso++;
        return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
    }
}