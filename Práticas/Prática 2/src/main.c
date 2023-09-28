//---------------------------------------------------------------------
// Arquivo      : main.c
// Conteudo     : arquivo principal
// Autor	: Raissa Diniz
// Historico	: 2023-08-31 - arquivo criado
//---------------------------------------------------------------------
#include "../include/fibfat.h"
#include "../include/clock.h"
#include <stdio.h>

void measureAndPrintFibonacci(int N, unsigned long long (*fib)(int)) {
    struct timespec tp1, tp2;

    clock_gettime(CLOCK_MONOTONIC, &tp1);
    double startTime = getSystemTime();
    unsigned long long result = fib(N);
    double endTime = getSystemTime();
    double elapsedTimeSystem = endTime - startTime;

    startTime = getUserTime();
    result = fib(N);
    endTime = getUserTime();
    double elapsedTimeUser = endTime - startTime;

    clock_gettime(CLOCK_MONOTONIC, &tp2);
    double clockElapsedTime = (double)(tp2.tv_sec - tp1.tv_sec) + (double)(tp2.tv_nsec - tp1.tv_nsec) / 1000000000.0;

    printf("\nThe result is %llu\n", result);
    printf("System time: %.9f seconds\n", elapsedTimeSystem);
    printf("User time: %.9f seconds\n", elapsedTimeUser);
    printf("Clock Time: %.9f seconds\n", clockElapsedTime);

    printf("\n");
}

void measureAndPrintFactorial(int N, unsigned long long (*fact)(int)) {
    struct timespec tp1, tp2;

    clock_gettime(CLOCK_MONOTONIC, &tp1);
    double startTime = getSystemTime();
    unsigned long long result = fact(N);
    double endTime = getSystemTime();
    double elapsedTimeSystem = endTime - startTime;

    startTime = getUserTime();
    result = fact(N);
    endTime = getUserTime();
    double elapsedTimeUser = endTime - startTime;

    clock_gettime(CLOCK_MONOTONIC, &tp2);
    double clockElapsedTime = (double)(tp2.tv_sec - tp1.tv_sec) + (double)(tp2.tv_nsec - tp1.tv_nsec) / 1000000000.0;

    printf("\nThe result is %llu\n", result);
    printf("System time: %.9f seconds\n", elapsedTimeSystem);
    printf("User time: %.9f seconds\n", elapsedTimeUser);
    printf("Clock Time: %.9f seconds\n", clockElapsedTime);

    printf("\n");
}

int main() {
    int N = 5;  // Usando apenas o número 5 para todas as funções, como especificado no Moodle

    printf("\n\nPrática 2: Analisando os diferentes tempos de execução para as funções de Fibonacci/ Fatorial iterativo e recursivo.\n");
    printf("Valor utilizado para o teste: %d\n\n", N);

    printf("--------------------------------- Fibonacci function ---------------------------------\n");

    // Recursive fibonacci
    printf("\n--------- Recursive call ---------");
    measureAndPrintFibonacci(N, recursiveFibonacci);

    // Iterative fibonacci
    printf("\n--------- Iterative call ---------");
    measureAndPrintFibonacci(N, iterativeFibonacci);

    printf("--------------------------------- Factorial function ---------------------------------\n");

    // Recursive Factorial
    printf("\n--------- Recursive call ---------");
    measureAndPrintFactorial(N, recursiveFactorial);

    // Iterative Factorial
    printf("\n--------- Iterative call ---------");
    measureAndPrintFactorial(N, iterativeFactorial);

    return 0;
}