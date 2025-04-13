/**
 * @file musics.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da estrutura Music
 */
#ifndef MUSICS_H
#define MUSICS_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da Música
typedef struct music Music;

/**
 * @brief Inicializa a estrutura Music
 * 
 * Função que aloca espaço para a estrutura Music
 * e para todos os seus campos
 * 
 * @return Music* 
 */
Music *init_music();

//-------------------------ID------------------------
/**
 * @brief Retorna o id da música
 * 
 * Função que retorna a cópia do id de uma determinada música
 * passada como argumento
 * 
 * @param music (Música a ser consultada)
 * @return char* (Id da música) 
 */
char *get_music_id(Music *music);

/**
 * @brief Define o id da música
 * 
 * Função que liberta a memória alocada para o id da música atual
 * e define o novo id passado como argumento
 * 
 * @param music (Música a ser alterada)
 * @param id (Id a ser definido)
 */
void set_music_id(Music *music, char *id);

//--------------------------TITLE---------------------
/**
 * @brief Retorna o título da música
 * 
 * Função que retorna a cópia do título de uma determinada música
 * passada como argumento
 * 
 * @param music (Música a ser consultada)
 * @return char* (Título da música) 
 */
char *get_music_title(Music *music);

/**
 * @brief Define o título da música
 * 
 * Função que liberta a memória alocada para o título da música atual
 * e define o novo título passado como argumento
 * 
 * @param music (Música a ser alterada)
 * @param title (Título a ser definido)
 */
void set_music_title(Music *music, char *title);

//--------------------------ARTIST_ID---------------------
/**
 * @brief Retorna o id dos artistas da música
 * 
 * Função que retorna o array dos ids artistas de uma determinada música
 * passada como argumento
 * 
 * @param music (Música a ser consultada)
 * @return char** (Array dos ids dos artistas da música) 
 */
char **get_music_artist_id(Music *music);

/**
 * @brief Define o id dos artistas da música
 * 
 * Função que liberta a memória alocada para o array dos ids dos artistas da música atual
 * e define o novo array de ids passado como argumento
 * 
 * @param music (Música a ser alterada)
 * @param artist_id (Array dos ids dos artistas a ser definido)
 */
void set_music_artist_id(Music *music, char **artist_id);

//-------------------------DURATION------------------------
/**
 * @brief Retorna a duração da música
 * 
 * Função que retorna a cópia da duração de uma determinada música
 * passada como argumento
 * 
 * @param music (Música a ser consultada)
 * @return char* (Duração da música) 
 */
char *get_music_duration(Music *music);

/**
 * @brief Define a duração da música
 * 
 * Função que liberta a memória alocada para a duração da música atual
 * e define a nova duração passada como argumento
 * 
 * @param music (Música a ser alterada)
 * @param duration (Duração a ser definida)
 */
void set_music_duration(Music *music, char* duration);

//--------------------------------GENRE---------------------
/**
 * @brief Retorna o género da música
 * 
 * Função que retorna a cópia do género de uma determinada música
 * passada como argumento
 * 
 * @param music (Música a ser consultada)
 * @return char* (Género da música) 
 */
char *get_music_genre(Music *music);

/**
 * @brief Define o género da música
 * 
 * Função que liberta a memória alocada para o género da música atual
 * e define o novo género passado como argumento
 * 
 * @param music (Música a ser alterada)
 * @param genre (Género a ser definido)
 */
void set_music_genre(Music *music, char *genre);

//-----------------------YEAR-------------------------
/**
 * @brief Retorna o ano da música
 * 
 * Função que retorna o ano de uma determinada música
 * passada como argumento
 * 
 * @param music (Música a ser consultada)
 * @return int (Ano da música) 
 */
int get_music_year(Music *music);

/**
 * @brief Define o ano da música
 * 
 * Função que define o ano de uma determinada música
 * passada como argumento
 * 
 * @param music (Música a ser alterada)
 * @param year (Ano a ser definido)
 */
void set_music_year(Music *music, int year);

//-------------------------LYRICS--------------------------
/**
 * @brief Retorna a letra da música
 * 
 * Função que retorna a cópia da letra de uma determinada música
 * passada como argumento
 * 
 * @param music (Música a ser consultada)
 * @return char* (Letra da música) 
 */
char *get_music_lyrics(Music *music);

/**
 * @brief Define a letra da música
 * 
 * Função que liberta a memória alocada para a letra da música atual
 * e define a nova letra passada como argumento
 * 
 * @param music (Música a ser alterada)
 * @param lyrics (Letra a ser definida)
 */
void set_music_lyrics(Music *music, char *lyrics);

//-----------------------N_ARTISTS--------------------------
/**
 * @brief Retorna o número de artistas da música
 * 
 * Função que retorna o número de artistas que fizeram de uma determinada música
 * 
 * @param music (Música a ser consultada)
 * @return int (Número de artistas da música) 
 */
int get_music_n_artists(Music *music);

/**
 * @brief Define o número de artistas da música
 * 
 * Função que define o número de artistas que fizeram de uma determinada música
 * 
 * @param music (Música a ser alterada)
 * @param n_artists (Número de artistas a ser definido)
 */

void set_music_n_artists(Music *music, int n_artists);

//------------------ALBUM_ID----------------
/**
 * @brief Retorna o id do album à qual a música pertence
 * 
 * Função que retorna  uma cópia do id do album à qual  uma determinada música pertence
 * 
 * @param music (Música a ser consultada) 
 * @return char* (Id do album à qual a música pertence)
 */
char *get_music_album_id(Music *music);

/**
 * @brief Define o id do album à qual a música pertence
 * 
 * Função que liberta a memória alocada para o id do album à qual a música pertence
 * e define o novo id passado como argumento
 * 
 * @param music (Música a ser alterada)
 * @param album_id (Id do album a ser definido)
 */
void set_music_album_id(Music *music, char *album_id);

/**
 * @brief Liberta uma música
 * 
 * Função que liberta a memória alocada para a estrutura Music
 * e para todos os seus campos
 * 
 * @param music (Música a ser libertada)
 */
void free_music (Music *music);

/**
 * @brief Imprime uma música
 * 
 * Função que imprime no terminal todos os campos de uma determinada música
 * 
 * @param music (Música a ser impressa)
 */
void print_music(Music *music);

/**
 * @brief Copia uma música
 * 
 * Função que copia todos os campos de uma música
 * 
 * @param m (Música a ser copiada)
 * @return Music* (Cópia da música)
 */
Music *copy_music (Music *m);

#endif