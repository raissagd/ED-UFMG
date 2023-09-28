//---------------------------------------------------------------------
// Arquivo      : tempo.h
// Conteudo     : assinaturas das funções do arquivo tempo.c
// Autor	: Raissa Diniz
// Historico	: 2023-08-31 - arquivo criado
//---------------------------------------------------------------------
#ifndef CLOCK_H
#define CLOCK_H

#include "sys/resource.h"
#include <time.h>

double getUserTime(); //função para calcular o tempo de usuario decorrido em segundos
double getSystemTime(); //função para calcular o tempo do sistema decorrido em segundos

#endif