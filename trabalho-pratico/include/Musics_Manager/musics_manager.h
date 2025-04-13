/**
 * @file musics_manager.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo do Gestor de Músicas
 */
#ifndef MUSICS_MANAGER_H
#define MUSICS_MANAGER_H

// Ficheiros
#include "musics.h"
#include "HT_Music.h"
#include "TOP_Music.h"
#include "Musics_Manager/musics_manager.h"
#include "general_manager.h"
#include "Artists_Manager/artists_manager.h"

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

// Estrutura do Gestor de Músicas
typedef struct musics_Manager Musics_Manager;

/**
 * @brief Inicializa o Gestor de Músicas
 * 
 * Função que aloca memória para o Gestor de Músicas
 * e para a HashTable de músicas e para a lista de músicas TOP
 * 
 * @return Musics_Manager* 
 */
Musics_Manager *init_GM();

/**
 * @brief Liberta o Gestor de Músicas
 * 
 * Função que liberta a memória alocada para o Gestor de Músicas
 * 
 * @param mm Gestor de Músicas
 */
void free_GM(Musics_Manager *mm);

/**
 * @brief Imprime o Gestor de Músicas
 * 
 * Função que imprime o Gestor de Músicas
 * ou seja, imprime a HashTable de músicas e a lista de músicas TOP
 * 
 * @param mm Gestor de Músicas
 */
void print_GM(Musics_Manager *mm);

/**
 * @brief Adiciona uma música ao Gestor de Músicas
 * 
 * Função que adiciona uma música ao Gestor de Músicas
 * 
 * @param mm Gestor de Músicas
 * @param m Música
 */
void add_GM_M(Musics_Manager *mm, Music *m);

/**
 * @brief Retorna uma música na HashTable de músicas
 * 
 * Função que procura uma música na HashTable de músicas
 * 
 * @param mm Gestor de Músicas
 * @param id ID da música
 * @return Music* (Música encontrada, NULL caso contrário) 
 */
Music* search_GM_M (Musics_Manager *mm, char *id);

/**
 * @brief Verifica se uma música existe
 * 
 * Função que verifica se uma música existe na Hash Table
 * 
 * @param mm Gestor de Músicas onde se encontra a Hash Table das músicas
 * @param id Id da música a ser procurada
 * @return int (1 caso exista, 0 caso contrário)
 */
const int musica_existe_GM(Musics_Manager *mm, char *id);

/**
 * @brief Liberta a hash table TOP
 * 
 * Função que liberta a memória alocada para a hash table TOP
 * 
 * @param mm Gestor de Músicas
 */
void free_GM_TOP(Musics_Manager *mm);

/**
 * @brief Adiciona uma música à lista de músicas TOP
 * 
 * Função que adiciona uma música à lista de músicas TOP
 * 
 * @param mm Gestor de Músicas
 * @param m Música
 * @param country País do artista
 * @param artist_id ID do artista
 */
void add_GM_TOP_M (Musics_Manager *mm, Music *m, char *country, char *artist_id);

/**
 * @brief Liberta a hash table TOP
 * 
 * Função que liberta a memória alocada para a hash table TOP
 * 
 * @param mm Gestor de Músicas
 */
void free_GM_TOP(Musics_Manager *mm);

/**
 * @brief Calcula a  duração de uma música
 * 
 * Função que calcula a duração de uma música em segundos
 * 
 * @param duration Duaração no formato HH:MM:SS
 * @return int Duração em segundos
 */
int duration_seg3 (char* duration);


//------------Encapsulamento

/**
 * @brief Guarda os resultados da query 2 em arreios
 * 
 * Função auxiliar usada na query 2 que guarda os resultados da query em arreios,
 * resultados esses que serão imprimidos em ficheiros de texto
 * 
 * Versão da função onde a query 2 é restringida a um país
 * 
 * 
 * @param mm (Gestor de Músicas)
 * @param country (País)
 * @param artists (Arreio de ids de artistas)
 * @param countries (Arreio dos países dos artistas)
 * @param discography (Arreio das discografias dos artistas)
 */
void iter_GM_top(Musics_Manager *mm, char *country, char **artists, char **countries, int *discography, int N);

/**
 * @brief Guarda os resultados da query 2 em arreios
 * 
 * Função auxiliar usada na query 2 que guarda os resultados da query em arreios,
 * resultados esses que serão imprimidos em ficheiros de texto
 * 
 * Versão da função onde a query 2 não é restringida a um país
 * 
 * @param mm (Gestor de Músicas)
 * @param artists (Arreio de ids de artistas)
 * @param countries (Arreio dos países dos artistas)
 * @param discography (Arreio das discografias dos artistas)
 */
void iter_GM_top_sem_pais(Musics_Manager *mm, char **artists, char **countries, int *discography, int N);

/**
 * @brief Itera sobre a HashTable de músicas
 * 
 * Função que itera sobre a HashTable de músicas e chama a função de callback
 * 
 * @param mm (Gestor de Músicas)
 * @param callback (Função de callback)
 * @param user_data (Dados do utilizador)
 */
void iterate_GM_HT_Musics(Musics_Manager *mm, void (*callback)(Music *m, void *user_data), void *user_data);

/**
 * @brief Devolve o número de artistas de uma música no Gestor de Músicas
 * 
 * Função devolve o número de artistas de uma música no Gestor de Músicas
 * 
 * @param mm (Gestor de Músicas)
 * @param music_id (Id da música a procurar)
 * @return int (Número de artistas)
 */
int search_GM_get_music_n_artists (Musics_Manager *mm, char *music_id);

/**
 * @brief Devolve os artistas de uma música no Gestor de Músicas
 * 
 * Função devolve os artistas de uma música no Gestor de Músicas
 * 
 * @param mm (Gestor de Músicas)
 * @param music_id (Id da música a procurar)
 * @return char** (Array de ids dos artistas)
 */
char **search_GM_get_music_artist_id (Musics_Manager *mm, char *music_id);

/**
 * @brief Verifica se existe uma HashTable de músicas TOP para um país
 * 
 * Função que verifica se existe uma HashTable de músicas TOP para um país
 * 
 * @param mm Gestor de Músicas
 * @param country País
 * @return int Resultado (1 caso exista, 0 caso contrário)
 */
int country_GM_TOP_exists (Musics_Manager *mm, char *country);

#endif