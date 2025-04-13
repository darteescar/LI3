/**
 * @file querie_iter_4.h
 * @author Grupo 25
 * @brief Header file do módulo da quarta query iterativa
 */
#ifndef QUERIE_ITER_4_H
#define QUERIE_ITER_4_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ficheiros
#include "general_manager.h"
#include "parser.h"

/** 
 * @brief Função que trata da versão iterativa da quarta query
 * 
 * Função que imprime no terminal a resposta à query 4.
 * A query 4 consiste em determinar qual foi o artista que esteve mais vezes no top 10 semanal
 * 
 * No terminal é escrito o nome do artista, o tipo de artista
 * e o número de vezes que esteve no top 10 semanal.
 * 
 * Caso seja passado um intervalo de semanas, a resposta à querie 4 é calculada
 * apenas para as semanas que pertencem ao intervalo de semanas pedido.
 * 
 * @param data_de_inicio (Data de início do intervalo de semanas)
 * @param data_de_fim (Data de fim do intervalo de semanas)
 * @param gestor (Gestor principal)
 */
void fourth_querie_iter(char *data_de_inicio, char *data_de_fim, Gestor *gestor);

#endif