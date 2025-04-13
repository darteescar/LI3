/**
 * @file TOP_Music.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da estrutura TOP_Music
 */
#ifndef TOP_MUSIC_H
#define TOP_MUSIC_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

typedef struct artist_discografia Artist_Discografia;

/**
 * @brief Inicializa a HashTable TOP
 * 
 * Função que aloca memória para a HashTable TOP
 * 
 * @return GHashTable* HashTable TOP
 */
GHashTable *init_TOP();

/**
 * @brief Initializa a HashTable de artistas por país
 * 
 * Função que aloca memória para a HashTable de artistas por país
 * 
 * @return GHashTable* HashTable de artistas por país
 */
GHashTable *init_artists_country();

/**
 * @brief Liberta a Hash Table de artistas por país
 * 
 * Função que liberta a memória alocada para a Hash Table de artistas por país
 * 
 * @param table Hash Table de artistas por país
 */
void free_ARTIST_COUNTRY_TOP(void *table);

/**
 * @brief Liberta a estrutura Artist_Discografia
 * 
 * Função que liberta a memória alocada para os campos da estrutura Artist_Discografia
 * 
 * @param adisc Apontador para a estrutura Artist_Discografia
 */
void free_ARTIST_DISCOGRAFIA (void *adisc);

/**
 * @brief Liberta a Hash Table TOP
 * 
 * Função que liberta a memória alocada para a Hash Table TOP
 * 
 * @param country_top Hash Table TOP
 */
void free_TOP (GHashTable *country_top);

/**
 * @brief Adiciona um artista à Hash Table TOP
 * 
 * Função que adiciona um artista à Hash Table TOP,
 * tendo em conta o país
 * 
 * @param top Hash Table TOP
 * @param artists_id ID do artista
 * @param country País do artista
 * @param duration Duração da música
 */
void add_TOP_M (GHashTable *top, char *artists_id, char *country, int duration);

/**
 * @brief Imprime a Hash Table TOP
 * 
 * Função que imprime no terminal a Hash Table TOP
 * 
 * @param top Hash Table TOP
 */
void print_TOP (GHashTable *top);

/**
 * @brief Retorna o tempo de discografia de um artista
 * 
 * Função que retorna o tempo de discografia de um artista
 * 
 * @param ad Apontador para a estrutura Artist_Discografia
 * @return int Tempo de discografia de um artista
 */
int get_Artist_Discografia_t_reproducao(Artist_Discografia *ad);

/**
 * @brief Retorna o ID de um artista
 * 
 * Função que retorna o ID de um artista
 * 
 * @param ad Apontador para a estrutura Artist_Discografia
 * @return char* ID de um artista
 */
char *get_Artist_Discografia_id(Artist_Discografia *ad);

//---------Encapsulamento

/**
 * @brief Guarda os resultados da query 2 em arreios
 * 
 * Função auxiliar usada na query 2 que guarda os resultados da query em arreios,
 * resultados esses que serão imprimidos em ficheiros de texto
 * 
 * Versão da função onde a query 2 é restringida a um país
 * 
 * @param top (HashTable TOP)
 * @param country (País)
 * @param artists (Arreio de ids de artistas)
 * @param countries (Arreio dos países dos artistas)
 * @param discography (Arreio das discografias dos artistas)
 */
void iter_top(GHashTable *top, char *country, char **artists, char **countries, int *discography, int N);

/**
 * @brief Guarda os resultados da query 2 em arreios
 * 
 * Função auxiliar usada na query 2 que guarda os resultados da query em arreios,
 * resultados esses que serão imprimidos em ficheiros de texto
 * 
 * Versão da função onde a query 2 não é restringida a um país
 * 
 * @param top (HashTable TOP)
 * @param artists (Arreio de ids de artistas)
 * @param countries (Arreio dos países dos artistas)
 * @param discography (Arreio das discografias dos artistas)
 */
void iter_top_sem_pais(GHashTable *top, char **artists, char **countries, int *discography, int N);

/**
 * @brief Verifica se existe uma Hash Table no TOP de um país
 * 
 * Função que verifica se existe uma Hash Table no TOP de um país
 * 
 * @param top Hash Table TOP
 * @param country País
 * @return int Resultado (1 - Existe, 0 - Não existe)
 */
int country_TOP_exists (GHashTable *top, char *country);

#endif