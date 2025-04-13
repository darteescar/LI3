/**
 * @file querie_6.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da sexta query
 */
#ifndef QUERIE_6_H
#define QUERIE_6_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Ficheiros
#include "general_manager.h"
#include "utilidades.h"

typedef struct artist_list Artist_List;

/**
 * @brief Devolve o ID do artista da estrutura Artist_List
 * 
 * Função que devolve o ID do artista da estrutura Artist_List.
 * 
 * @param artist_list (Estrutura Artist_List)
 * @return char* 
 */
char* get_ArtistList_artist_id(Artist_List *artist_list);

/**
 * @brief Devolve o tempo ouvido do artista da estrutura Artist_List
 * 
 * Função que devolve o tempo ouvido do artista da estrutura Artist_List.
 * 
 * @param artist_list (Estrutura Artist_List)
 * @return int 
 */
int get_ArtistList_time_listened(Artist_List *artist_list);

/**
 * @brief Devolve o array de músicas ouvidas do artista da estrutura Artist_List
 * 
 * Função que devolve o array de músicas ouvidas do artista da estrutura Artist_List.
 * 
 * @param artist_list (Estrutura Artist_List)
 * @return char** 
 */
char** get_ArtistList_music_id(Artist_List *artist_list);

/**
 * @brief Devolve o número de músicas ouvidas do artista da estrutura Artist_List
 * 
 * Função que devolve o número de músicas ouvidas do artista da estrutura Artist_List.
 * 
 * @param artist_list (Estrutura Artist_List)
 * @return int 
 */
int get_ArtistList_n_musics(Artist_List *artist_list);

/**
 * @brief Devolve a flag da estrutura Artist_List
 * 
 * Função que devolve a flag, sendo ela um caracter, da estrutura Artist_List.
 * 
 * @param artist_list (Estrutura Artist_List)
 * @return char 
 */
char get_ArtistList_flag(Artist_List *artist_list);

/**
 * @brief Altera a flag da estrutura Artist_List
 * 
 * Função que altera a flag, sendo ela um caracter, da estrutura Artist_List.
 * 
 * @param artist_list (Estrutura Artist_List)
 * @param flag (Nova Flag)
 */
void set_ArtistList_flag(Artist_List *artist_list, char flag);

/**
 * @brief Imprime a hash table de Artist_List
 * 
 * Função que imprime a hash table de Artist_List.
 * 
 * @param ht (Hash Table de artistas)
 */
void print_artist_list (GHashTable *ht);

/**
 * @brief Inicializa a hash table de Artist_List
 * 
 * Função que aloca memória para uma nova hash table de Artist_List.
 * 
 * @return GHashTable* 
 */
GHashTable *init_HT_Artist_List();

/**
 * @brief Liberta a hash table de Artist_List
 * 
 * Função que liberta a memória alocada para a hash table de Artist_List.
 * 
 * @param ht (Hash Table de artistas)
 */
void free_HT_Artist_List(GHashTable *ht);

/**
 * @brief Liberta a memória alocada para a estrutura Artist_List
 * 
 * Função que liberta a memória alocada para a estrutura Artist_List.
 * 
 * @param artist_list (Estrutura Artist_List)
 */
void free_HT_Artist_List_value(Artist_List *artist_list);

/**
 * @brief Adiciona vários artistas à hash table de Artist_List
 * 
 * Função que adiciona vários artistas à hash table de Artist_List.
 * 
 * @param ht (Hash Table de Artist_List)
 * @param artist_id (IDs dos artistas)
 * @param n_artists (Número de artistas)
 * @param max_artist_n_listened (Máximo de tempo ouvido)
 * @param max_artist_id (ID do artista com mais tempo ouvido)
 * @param duration (Duração da música)
 * @param music_id (ID da música)
 */
void add_artist_to_listened_artists(GHashTable *ht, char **artist_id, int n_artists, int *max_artist_n_listened, char *max_artist_id, int duration, char *music_id);

typedef struct music_list Music_List;

/**
 * @brief Inicializa a hash table de Music_List
 * 
 * Função que aloca memória para uma nova hash table de Music_List.
 * 
 * @return GHashTable* 
 */
GHashTable *init_HT_Music_List();

/**
 * @brief Liberta a hash table de Music_List
 * 
 * Função que liberta a memória alocada para a hash table de Music_List.
 * 
 * @param ht (Hash Table de músicas)
 */
void free_HT_Music_List(GHashTable *ht);

/**
 * @brief Liberta a memória alocada para a estrutura Music_List
 * 
 * Função que liberta a memória alocada para a estrutura Music_List.
 * 
 * @param music_list (Estrutura Music_List)
 */
void free_HT_Music_List_value(Music_List *music_list);

/**
 * @brief Adiciona uma música à hash table de Music_List
 * 
 * Função que adiciona uma música à hash table de Music_List.
 * 
 * @param ht (Hash Table de Music_List)
 * @param music_id (ID da música)
 * @param num_musicas_ouvidas_sem_repeticao (Número de músicas ouvidas sem repetição)
 */
void add_music_to_listened_musics(GHashTable *ht, char *music_id, int *num_musicas_ouvidas_sem_repeticao);

/**
 * @brief Função que trata do caso de um user não existir ou estar vazio
 * 
 * Função que trata do caso de um user não existir ou estar vazio,
 * imprimindo um "\n" no ficheiro de output correspondente à variável cont
 * 
 * @param cont (Contador do ficheiro de output)
 */
void user_vazio_ou_inexistente(int cont);

/**
 * @brief Função que verifica se um ano é bissexto
 * 
 * Função que verifica se um ano é bissexto.
 * 
 * @param year (Ano)
 * @return bool 
 */
bool is_leap_year(int year);

/**
 * @brief Calcula os dias totais passados de ano
 * 
 * Função que calcula os dias totais passados de ano,
 * dado uma data
 * 
 * @param data (Data)
 * @return int 
 */
int calcula_dia (char *data);

typedef struct genre_list Genre_List;

/**
 * @brief Inicializa a hash table de Genre_List
 * 
 * Função que aloca memória para uma nova hash table de Genre_List.
 * 
 * @return GHashTable* 
 */
GHashTable *init_HT_Genre_List();

/**
 * @brief Liberta a hash table de Genre_List
 * 
 * Função que liberta a memória alocada para a hash table de Genre_List.
 * 
 * @param ht (Hash Table de géneros)
 */
void free_HT_Genre_List(GHashTable *ht);

/**
 * @brief Liberta a memória alocada para a estrutura Genre_List
 * 
 * Função que liberta a memória alocada para a estrutura Genre_List.
 * 
 * @param genre_list (Estrutura Genre_List)
 */
void free_HT_Genre_List_value(Genre_List *genre_list);

/**
 * @brief Adiciona um género à hash table de Genre_List
 * 
 * Função que adiciona um género à hash table de Genre_List.
 * 
 * @param ht (Hash Table de Genre_List)
 * @param genre (Género)
 * @param max_genre_n_listened (Máximo de tempo ouvido)
 * @param max_genre (Género com mais tempo ouvido)
 * @param durationn (Duração do género de música ouvido)
 */
void add_genre_to_listened_genres(GHashTable *ht, char *genre, int *max_genre_n_listened, char *max_genre, int durationn);

/**
 * @brief Reconstroi uma data
 * 
 * Função que reconstroi uma data,
 * dado um ano e o total de dias passados nesse ano
 * 
 * @param ano (Ano)
 * @param dia (Dias passados)
 * @param data (Data)
 */
void reconstroi_data (int ano, int dia, char *data);

typedef struct album_list Album_List;

/**
 * @brief Inicializa a hash table de Album_List
 * 
 * Função que aloca memória para uma nova hash table de Album_List.
 * 
 * @return GHashTable* 
 */
GHashTable *init_HT_Album_List();

/**
 * @brief Liberta a hash table de Album_List
 * 
 * Função que liberta a memória alocada para a hash table de Album_List.
 * 
 * @param ht (Hash Table de álbuns)
 */
void free_HT_Album_List(GHashTable *ht);

/**
 * @brief Liberta a memória alocada para a estrutura Album_List
 * 
 * Função que liberta a memória alocada para a estrutura Album_List.
 * 
 * @param album_list (Estrutura Album_List)
 */
void free_HT_Album_List_value(Album_List *album_list);

/**
 * @brief Adiciona um álbum à hash table de Album_List
 * 
 * Função que adiciona um álbum à hash table de Album_List.
 * 
 * @param ht (Hash Table de Album_List)
 * @param album_id (ID do álbum)
 * @param max_album_n_listened (Máximo de tempo ouvido)
 * @param max_album_id (ID do álbum com mais tempo ouvido)
 * @param durationn (Duração do álbum ouvida)
 */
void add_album_to_listened_albums(GHashTable *ht, char *album_id, int *max_album_n_listened, char *max_album_id, int durationn);

/**
 * @brief Resposta à sexta query
 * 
 * Função que imprime a resposta à sexta query num ficheiro de texto
 * A query 6 consiste em apresentar um resumo anual de um utilizador num certo ano
 * 
 * No ficheiro output, é escrito o tempo total de audição do utilizador, o número de
 * músicas ouvidas, o artista mais ouvido, o dia em que reproduziu mais músicas, 
 * o género de música mais ouvido, o seu álbum favorito e a hora do dia em que costuma ouvir mais música
 * 
 * Pode ainda ser passado um argumento opcional numérico, N, 
 * sendo que em tal caso devem-se imprimir em linhas consecutivas os
 * N artistas mais ouvidos pelo utilizador nesse ano, 
 * 
 * @param line (Linha com o comando da query)
 * @param cont (Contador do ficheiro de output)
 * @param gestor (Gestor principal)
 */
void sixth_querie(char *line, int cont, Gestor *gestor);

#endif