/**
 * @file querie_2.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da segunda query
 */
#ifndef QUERIE_2_H
#define QUERIE_2_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Ficheiros
#include "general_manager.h"

/**
 * @brief Tranforma a duração em segundos para um formato específico
 * 
 * Função que recebe um inteiro que representa a duração 
 * em segundos e devolve uma string com o formato HH:MM:SS
 * 
 * @param duration Duração em segundos
 * @return char* (string) com a duração no formato HH:MM:SS
 */
char* duration_format(int duration);

/**
 * @brief Resposta a query 2
 * 
 * Função que imprime num ficheiro de texto a resposta à query 2
 * A query 2 consiste em listar os TOP N artistas com mais discografia
 * 
 * Caso seja dado um país como um parâmetro opcional para a query
 * a lista deverá ser filtrada por esse país
 * 
 * @param line Linha que contém o número de artistas a listar e o país e o identificador da query
 * @param cont Número para identificar o ficheiro de output
 * @param gestor Gestor de dados
 */
void second_querie(char *line, int cont, Gestor *gestor);

#endif