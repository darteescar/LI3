/**
 * @file querie_4.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da quarta query
 */
#ifndef QUERIE_4_H
#define QUERIE_4_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ficheiros
#include "general_manager.h"

typedef struct top_semanal TOP_SEMANAL;

/**
 * @brief Inicializa a hash table TOP_SEMANAL
 * 
 * Função que aloca memória para uma nova hash table TOP_SEMANAL.
 * 
 * @return TOP_SEMANAL* 
 */
GHashTable *init_TOP_SEMANAL_INTERVALADO(Gestor *gestor);

/**
 * @brief Devolve o ID do artista da estrutura TOP_SEMANAL
 * 
 * Função que devolve o ID do artista da estrutura TOP_SEMANAL.
 * 
 * @param top Estrutura TOP_SEMANAL
 * @return char* 
 */
char *get_TOP_SEMANAL_artist_id(TOP_SEMANAL *top);

/**
 * @brief Devolve o número de vezes que o artista esteve no top 10 semanal da estrutura TOP_SEMANAL
 * 
 * Função que devolve o número de vezes que o artista esteve no top 10 semanal da estrutura TOP_SEMANAL.
 * 
 * @param top Estrutura TOP_SEMANAL
 * @return int 
 */
int get_TOP_SEMANAL_vezes(TOP_SEMANAL *top);

/**
 * @brief Liberta a hash table TOP_SEMANAL
 * 
 * Função que liberta a memória alocada para a hash table TOP_SEMANAL.
 * 
 * @param tabela Estrutura TOP_SEMANAL
 */
void free_TOP_SEMANAL_INTERVALADO(GHashTable *tabela);

/**
 * @brief Adiciona um novo artista à hash table TOP_SEMANAL
 * 
 * Função que adiciona um novo artista à hash table TOP_SEMANAL,
 * se o artista já existir, incrementa em 1 unidade o número de vezes que esteve no top 10 semanal.
 * caso contrário, cria um novo artista que esteve pela primeira vez no top 10 semanal.
 * 
 * @param tabela Hash Table TOP_SEMANAL
 * @param artist_id ID do artista
 */
void add_TOP_SEMANAL_INTERVALADO(GHashTable *tabela, char *artist_id);

/**
 * @brief Calcula o número de semanas entre duas semanas
 * 
 * Função que calcula o número de semanas, que existem entre duas semanas,
 * uma semana de início e uma semana de fim.
 * 
 * @param semana_de_inicio Semana de início
 * @param semana_de_fim Semana de fim
 * @return int (Número de semanas)
 */
int calcula_n_semanas(char *semana_de_inicio, char *semana_de_fim);

/**
 * @brief Resposta à querie 4
 * 
 * Função que imprime num ficheiro de texto a resposta à query 4.
 * A query 4 consiste em determinar qual foi o artista que esteve mais vezes no top 10 semanal
 * 
 * No ficheiro de output é escrito o nome do artista, o tipo de artista
 * e o número de vezes que esteve no top 10 semanal.
 * 
 * Caso seja passado um intervalo de semanas, a resposta à querie 4 é calculada
 * apenas para as semanas que pertencem ao intervalo de semanas pedido.
 * 
 * @param line Linha que contém o intervalo de semanas e o identificador da query
 * @param cont Número para identificar o ficheiro de output
 * @param gestor Gestor de dados
 */
void fourth_querie (char *line, int cont, Gestor *gestor);



#endif