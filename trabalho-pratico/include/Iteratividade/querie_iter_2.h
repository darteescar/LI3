/**
 * @file querie_iter_2.h
 * @author Grupo 25
 * @brief Header file do módulo da segunda query iterativa
 */
#ifndef QUERIE_ITER_2_H
#define QUERIE_ITER_2_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ficheiros
#include "general_manager.h"
#include "parser.h"

/**
 * @brief Função que trata da versão iterativa da segunda query
 * 
 * Função que trata da segunda query interativa, que consiste em imprimir no terminal 
 * os N artistas com maior discografia, podendo ser filtrados por país 
 * 
 * A função recebe como argumentos o país ,o número de artistas a mostrar e o gestor principal
 * Se o country(char*) for NULL, não há restrição de país
 * 
 * @param country (País dos artistas a mostrar(Se country for NULL, não há restrição))
 * @param N (Número de artistas a mostrar)
 * @param gestor (Gestor principal)
 */
void second_querie_iter(char* country, int N, Gestor* gestor);

#endif