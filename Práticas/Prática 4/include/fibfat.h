//---------------------------------------------------------------------
// Arquivo      : fibfat.h
// Conteudo     :  assinaturas das funções do arquivo fibfat.c
// Autor	: Raissa Diniz
// Historico	: 2023-08-31 - arquivo criado
//---------------------------------------------------------------------
#ifndef FIBFAT_H
#define FIBFAT_H

#include <math.h>

typedef struct {
} FibFat;

// Função para calcular o fatorial de um número de forma iterativa
unsigned long long iterativeFactorial(int n);

// Função para calcular o fatorial de um número de forma recursiva
unsigned long long recursiveFactorial(int n);

// Função para calcular o número de Fibonacci de forma iterativa
unsigned long long iterativeFibonacci(int n);

// Função para calcular o número de Fibonacci de forma recursiva
unsigned long long recursiveFibonacci(int n);

#endif