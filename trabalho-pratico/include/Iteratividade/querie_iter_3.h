/**
 * @file querie_iter_3.h
 * @author Grupo 25
 * @brief Header file do módulo da terceira query iterativa
 */
#ifndef QUERIE_ITER_3_H
#define QUERIE_ITER_3_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ficheiros
#include "general_manager.h"
#include "parser.h"

/**
 * @brief Função que trata da versão iterativa da terceira query
 * 
 * Função que imprime no terminal a resposta à query 3
 * A query 3 consiste em mostrar os géneros de música mais populares
 * numa determinada faxa etária
 * 
 * No terminal irá ser impresso o nome do género
 * e o número de likes que esse género, tudo isto por ordem decrescente
 * Caso a faxa etária não seja válida, deverá ser impresso uma linha vazia
 * 
 * @param min (Idade mínima da faixa etária)
 * @param max (Idade máxima da faixa etária)
 * @param gestor (Gestor principal)
 */
void third_querie_iter(int min, int max, Gestor* gestor);

#endif