/**
 * @file testes.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo de testes 
 */
#ifndef TESTES_H
#define TESTES_H

// Ficheiros
#include "parser.h"
#include "general_manager.h"
#include "utilidades.h"
#include "Queries/querie_1.h"
#include "Queries/querie_2.h"
#include "Queries/querie_3.h"
#include "Queries/querie_4.h"
#include "Queries/querie_5.h"
#include "Queries/querie_6.h"

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/resource.h>

/**
 * @brief Função principal para o programa de testes
 * 
 * Função que trata do programa de testes
 * A função recebe como argumentos o caminho para a pasta que contém os ficheiros CSV,
 * o caminho para o ficheiro .txt de queries e o caminho para a pasta com os ficheiros de output
 * esperados usados para comparar com os outputs gerados pelo programa
 * 
 * A função também é responsável por calcular o tempo médio de cada query,
 * assim como o tempo total de execução do programa e a quantidade de memória utilizada
 * 
 * @param path_csv (Caminho para a pasta que contém os ficheiro CSV)
 * @param path_querie (Caminho para o ficheiro de queries)
 * @param path_output (Caminho para pasta com os ficheiros de output)
 */
void testes (char* path_csv, char* path_querie, char* path_output);




#endif