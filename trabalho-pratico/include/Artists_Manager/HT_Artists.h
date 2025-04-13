/**
 * @file HT_Artists.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da Hash Table de Artistas
 */
#ifndef HT_ARTIST_H
#define HT_ARTIST_H

//Ficheiros
#include "artists.h"

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

/**
 * @brief Inicializa uma Hash Table de Artistas
 * 
 * Função que aloca memória para uma Hash Table de Artistas
 * 
 * @return GHashTable* (Hash Table de Artistas)
 */
GHashTable *init_HT_A ();

/**
 * @brief Liberta a memória alocada para um artista na Hash Table
 * 
 * Função que liberta a memória alocada para um artista na Hash Table,
 * incluindo todos os seus campos
 * 
 * @param Artist Artista a ser libertado
 */
void free_HT_A_value (void *Artist);

/**
 * @brief Adiciona um artista à Hash Table de Artistas
 * 
 * Função que adiciona um artista à Hash Table de Artistas
 * 
 * @param a Artista a ser adicionado
 * @param ht Hash Table de Artistas
 */
void add_HT_A (Artist *a, GHashTable *ht);

/**
 * @brief Liberta a memória alocada para a Hash Table de Artistas
 * 
 * Função que liberta a memória alocada para a Hash Table de Artistas
 * 
 * @param ht Hash Table de Artistas
 */
void free_HT_A (GHashTable *ht);

/**
 * @brief Procura um artista numa Hash Table de Artistas
 * 
 * Função que procura um artista numa Hash Table de Artistas
 * dado o id do artista pretendido
 * 
 * @param ht Hash Table de Artistas
 * @param id Id do artista a procurar
 * @return Artist* (cópia do Artista encontrado, NULL caso não exista)
 */
Artist *search_HT_A (GHashTable *ht, char *id);

/**
 * @brief Imprime uma Hash Table de Artistas
 * 
 * Função que imprime no terminal todos os ids dos artistas
 * presentes na Hash Table de Artistas
 * 
 * @param ht Hash Table de Artistas
 */
void print_HT_A (GHashTable *ht);

/**
 * @brief Incrementa o número de álbuns de um artista
 * 
 * Função que incrementa em uma unidade o número de álbuns
 * onde o artista participa com sendo um artista individual
 * 
 * @param ht Hash Table de Artistas
 * @param artist_id Id do artista a incrementar
 */
void increment_HT_A_artist_n_albums(GHashTable *ht,char *artist_id);

/**
 * @brief Verifica se um artista é individual
 * 
 * Função que verifica se um artista é individual
 * dado um char* que representa o tipo do artista
 * 
 * @param type Tipo do artista
 * @return int (1 se for individual, 0 caso contrário)
 */
int e_individual(char * type);

/**
 * @brief Verifica se um artista é de grupo
 * 
 * Função que verifica se um artista é de grupo
 * dado um char* que representa o tipo do artista
 * 
 * @param type Tipo do artista
 * @return int (1 se for de group, 0 caso contrário)
 */
int e_group(char * type);

/**
 * @brief Incrementa a receita total de um artista
 * 
 * Função que incrementa a receita de um array de artistas que participaram numa música
 * Nesse array, se o artista for individual, incrementa a receita no valor do seu recipe per stream
 * Se o artista for coletivo, o grupo em si é aumentado na sua recipe per stream,
 * mas se cada um dos artistas que compõem o grupo for individual, então cada um desses artistas
 * vai ser incrementado na receita do grupo dividida pelo número de artistas individuais que compõem o grupo
 * 
 * @param am Hash Table de Artistas
 * @param artists_id Ids dos artistas a incrementar
 * @param n_artists Número de artistas a incrementar
 */
void increment_HT_A_artist_reproductions (GHashTable *am, char **artists_id, int n_artists);

#endif