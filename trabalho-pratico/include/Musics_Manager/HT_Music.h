/**
 * @file HT_Musics.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da Hash Table de Músicas
 */
#ifndef HT_MUSIC_H
#define HT_MUSIC_H

// Ficheiro
#include "musics.h"

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

/**
 * @brief Inicializa a Hash table de músicas
 * 
 * Função que aloca memória para a Hash Table de músicas
 * 
 * @return GHashTable* 
 */
GHashTable *init_HT_M();

/**
 * @brief Liberta uma música
 * 
 * Função que liberta a memória alocada para uma música
 * 
 * @param Music Musica a ser libertada
 */
void free_HT_M_value (void *Music);

/**
 * @brief Adiciona uma música à Hash table
 * 
 * Função que adiciona uma determinada música passada como argumento à Hash Table
 * 
 * @param m Música a ser adicionada
 * @param ht Hash Table onde a música será adicionada
 */
void add_HT_M (Music *m, GHashTable *ht);

/**
 * @brief Liberta a Hash Table de músicas
 * 
 * Função que liberta a memória alocada para a Hash Table de músicas
 * 
 * @param ht Hash Table a ser libertada
 */
void free_HT_M(GHashTable *ht);

/**
 * @brief Retorna a música procurando pelo id
 * 
 * Função que retorna uma cópia da música procurando pelo id passado como argumento
 * 
 * @param ht Hash Table onde a música será procurada
 * @param id Id da música a ser procurada
 * @return Music* (Música procurada, NULL caso não exista)
 */
Music *search_HT_M(GHashTable *ht, char *id);

/**
 * @brief Imprime os ids das músicas
 * 
 * Função que imprime no terminal os ids de todas as músicas presentes na Hash Table
 * 
 * @param ht Hash Table a ser imprimida
 */
void print_HT_M(GHashTable *ht);

/**
 * @brief Itera sobre a HashTable de músicas
 * 
 * Função que itera sobre a HashTable de músicas e chama a função de callback
 * 
 * @param ht (Hash Table de músicas)
 * @param callback (Função de callback)
 * @param user_data (Dados do utilizador)
 */
void iterate_HT_M(GHashTable *ht, void (*callback)(Music *m, void *user_data), void *user_data);

/**
 * @brief Retorna o número de artistas de uma música na Hash Table de músicas
 * 
 * Função que retorna o número de artistas de uma música na Hash Table de músicas
 * 
 * @param ht (Hash Table de músicas)
 * @param music_id (Id da música a procurar)
 * @return int (Número de artistas)
 */
int search_HT_get_music_n_artists (GHashTable *ht, char *music_id);

/**
 * @brief Retorna os artistas de uma música na Hash Table de músicas
 * 
 * Função que retorna os artistas de uma música na Hash Table de músicas
 * 
 * @param ht (Hash Table de músicas)
 * @param music_id (Id da música a procurar)
 * @return char** (Array de ids dos artistas)
 */
char **search_HT_get_music_artist_id (GHashTable *ht, char *music_id);

#endif