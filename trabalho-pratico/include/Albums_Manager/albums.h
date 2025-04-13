/**
 * @file albums.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da estrutura Album
 */
#ifndef ALBUMS_H
#define ALBUMS_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do Artista
typedef struct album Album;

/**
 * @brief Inicializa um album
 * 
 * Inicializa um album alocando memória para todos os seus campos
 * 
 * @return Album* 
 */
Album *init_album();


//------------------------------ID--------------------------------
/**
 * @brief Retorna o id do album
 * 
 * Retorna uma cópia do id do album passado como argumento
 * 
 * @param album Album cujo id se pretende obter
 * @return char* (id do album)
 */
char *get_album_id(Album *album);

/**
 * @brief Define o id do album
 * 
 * É dado free ao id atual e é definido um novo id para o album
 * como sendo o id passado como argumento
 * 
 * @param album Album cujo id se pretende definir
 * @param id Id do album
 */
void set_album_id(Album *album, char *id);

//------------------------------TITLE--------------------------------
/**
 * @brief Retorna o título do album
 * 
 * Retorna uma cópia do título do album passado como argumento
 * 
 * @param album Album cujo título se pretende obter
 * @return char* (título do album)
 */
char *get_album_title(Album *album);

/**
 * @brief Define o título do album
 * 
 * É dado free ao título atual e é definido um novo título para o album
 * como sendo o título passado como argumento
 * 
 * @param album Album cujo título se pretende definir
 * @param title Título do album
 */
void set_album_title(Album *album, char *title);

//-----------------------------ARTISTS ID----------------------------
/**
 * @brief Retorna os ids dos artistas do album
 * 
 * Retorna os ids dos artistas do album passado como argumento
 * 
 * @param album Album cujos ids dos artistas se pretende obter
 * @return char** (array com os ids dos artistas do album)
 */
char **get_album_artists_id(Album *album);

/**
 * @brief Define os ids dos artistas do album
 * 
 * Define os ids dos artistas do album como sendo os ids passados como argumento
 * 
 * @param album Album cujos ids dos artistas se pretende definir
 * @param artists_id Array com os ids dos artistas do album
 */
void set_album_artists_id(Album *album, char **artists_id);

//---------------------------N ARTISTS--------------------------------
/**
 * @brief Retorna o número de artistas do album
 * 
 * Retorna o número de artistas do album passado como argumento
 * 
 * @param album Album cujo número de artistas se pretende obter
 * @return int (número de artistas do album)
 */
int get_album_n_artists(Album *album);

/**
 * @brief Define o número de artistas do album
 * 
 * Define o número de artistas do album como sendo o número passado como argumento
 * 
 * @param album Album cujo número de artistas se pretende definir
 * @param n_artists Número de artistas do album
 */
void set_album_n_artists(Album *album, int n_artists);

//----------------------------YEAR--------------------------------
/**
 * @brief Retorna o ano do album
 * 
 * Retorna o ano do album passado como argumento
 * 
 * @param album Album cujo ano se pretende obter
 * @return int (ano do album)
 */
int get_album_year(Album *album);

/**
 * @brief Define o ano do album
 * 
 * Define o ano do album como sendo o ano passado como argumento
 * 
 * @param album Album cujo ano se pretende definir
 * @param year Ano do album
 */
void set_album_year(Album *album, int year);

//-------------------------------PRODUCERS--------------------------
/**
 * @brief Retorna os produtores do album
 * 
 * Retorna os produtores do album passado como argumento
 * 
 * @param album Album cujos produtores se pretende obter
 * @return char** (array com os produtores do album) 
 */
char **get_album_producers(Album *album);

/**
 * @brief Define os produtores do album
 * 
 * Define os produtores do album como sendo os produtores passados como argumento
 * 
 * @param album Album cujos produtores se pretende definir
 * @param producers Array com os produtores do album
 */
void set_album_producers(Album *album, char **producers);

//-----------------------N PRODUCERS--------------------------------
/**
 * @brief Retorna o número de produtores do album
 * 
 * Retorna o número de produtores do album passado como argumento
 * 
 * @param album Album cujo número de produtores se pretende obter
 * @return int (número de produtores do album)
 */
int get_album_n_producers(Album *album);

/**
 * @brief Define o número de produtores do album
 * 
 * Define o número de produtores do album como sendo o número passado como argumento
 * 
 * @param album Album cujo número de produtores se pretende definir
 * @param n_producers Número de produtores do album
 */
void set_album_n_producers(Album *album, int n_producers);

/**
 * @brief Liberta a memória alocada para um album
 * 
 * Liberta a memória alocada para um album, incluindo os seus campos
 * 
 * @param album Album cuja memória se pretende libertar
 */
void free_album(Album *album);

/**
 * @brief Imprime um album
 * 
 * Imprime no terminal os campos de um album
 * 
 * @param album Album a imprimir
 */
void print_album(Album *album);

#endif