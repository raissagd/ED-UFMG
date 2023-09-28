//---------------------------------------------------------------------
// Arquivo      : fibfat.c
// Conteudo     : implementação das funções Fibonnaci (iterativo e recursivo) e Fatorial (iterativo e recursivo)
// Autor	: Raissa Diniz
// Historico	: 2023-08-31 - arquivo criado
//---------------------------------------------------------------------

#include "../include/fibfat.h"

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
            return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
        }
    }
