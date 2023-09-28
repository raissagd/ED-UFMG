//---------------------------------------------------------------------
// Arquivo      : tempo.c
// Conteudo     : implementacao das funções do arquivo tempo.h
// Autor	: Raissa Diniz
// Historico	: 2023-08-31 - arquivo criado
//---------------------------------------------------------------------

#include <stdio.h>
#include "../include/clock.h"

double getUserTime()
{
	struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    double user_time = (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0;
    return  user_time;

}

double getSystemTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double) tv.tv_sec + (double) tv.tv_usec / 1000000.0;
}