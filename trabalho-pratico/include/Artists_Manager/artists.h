/**
 * @file artists.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da estrutura Artist
 */
#ifndef ARTISTS_H
#define ARTISTS_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do Artista
typedef struct artist Artist;

/**
 * @brief Inicializa um artista
 * 
 * Inicializa um artista alocando memória para todos os seus campos
 * 
 * @return Artist* 
 */
Artist *init_artist();

//-----------------------ID--------------------------------
/**
 * @brief Retorna o id do artista
 * 
 * Retorna uma cópia do id do artista passado como argumento
 * 
 * @param artist Artista cujo id se pretende obter
 * @return char* (id do artista)
 */
char *get_artist_id(Artist *artist);

/**
 * @brief Define o id do artista
 * 
 * É dado free ao id atual e é definido um novo id para o artista
 * como sendo o id passado como argumento
 * 
 * @param artist Artista cujo id se pretende definir
 * @param id Id do artista
 */
void set_artist_id(Artist *artist, char *id);

//---------------------------NAME------------------------------
/**
 * @brief Retorna o nome do artista
 * 
 * Retorna uma cópia do nome do artista passado como argumento
 * 
 * @param artist Artista cujo nome se pretende obter
 * @return char* (nome do artista)
 */
char *get_artist_name(Artist *artist);

/**
 * @brief Define o nome do artista
 * 
 * É dado free ao nome atual e é definido um novo nome para o artista
 * como sendo o nome passado como argumento
 * 
 * @param artist Artista cujo nome se pretende definir
 * @param name Nome do artista
 */
void set_artist_name(Artist *artist, char *name);

//---------------------------RECIPE PER STREAM--------------------------
/**
 * @brief Retorna a receita por stream do artista
 * 
 * Retorna a receita por stream do artista passado como argumento
 * 
 * @param artist Artista cuja receita por stream se pretende obter
 * @return double (receita por stream do artista)
 */
double get_artist_recipe_per_stream(Artist *artist);

/**
 * @brief Define a receita por stream do artista
 * 
 * Define a receita por stream do artista 
 * como sendo a receita por stream passada como argumento
 * 
 * @param artist Artista cuja receita por stream se pretende definir
 * @param recipe_per_stream Receita por stream do artista
 */
void set_artist_recipe_per_stream(Artist *artist, double recipe_per_stream);

//-----------------------------COUNTRY--------------------------------
/**
 * @brief Retorna o país do artista
 * 
 * Retorna uma cópia do país do artista passado como argumento
 * 
 * @param artist Artista cujo país se pretende obter
 * @return char* (país do artista)
 */
char *get_artist_country(Artist *artist);

/**
 * @brief Define o país do artista
 * 
 * É dado free ao país atual e é definido um novo país para o artista
 * como sendo o país passado como argumento
 * 
 * @param artist Artista cujo país se pretende definir
 * @param country País do artista
 */
void set_artist_country(Artist *artist, char *country);

//------------------------ID CONSTITUENT-------------------------
/**
 * @brief Retorna os ids dos músicos do artista
 * 
 * Retorna os ids dos músicos do artista passado como argumento
 * 
 * @param artist Artista cujos ids dos músicos se pretende obter
 * @return char** (array com os ids dos músicos do artista)
 */
char **get_artist_id_constituent(Artist *artist);

/**
 * @brief Define os ids dos músicos do artista
 * 
 * É dado free aos ids dos músicos atuais e são definidos novos ids para o artista
 * como sendo os ids passados como argumento
 * 
 * @param artist Artista cujos ids dos músicos se pretende definir
 * @param id_constituent Array com os ids dos músicos do artista
 */
void set_artist_id_constituent(Artist *artist, char **id_constituent);

//----------------------------N CONSTITUENT-------------------------
/**
 * @brief Retorna o número de músicos do artista
 * 
 * Retorna o número de músicos do artista passado como argumento
 * 
 * @param artist Artista cujo número de músicos se pretende obter
 * @return int (número de músicos do artista)
 */
int get_artist_n_constituent(Artist *artist);

/**
 * @brief Define o número de músicos do artista
 * 
 * Define o número de músicos do artista como sendo o número passado como argumento
 * 
 * @param artist Artista cujo número de músicos se pretende definir
 * @param n_constituent Número de músicos do artista
 */
void set_artist_n_constituent(Artist *artist, int n_constituent);

//-----------------------------TYPE--------------------------------
/**
 * @brief Retorna o tipo do artista
 * 
 * Retorna uma cópia do tipo do artista passado como argumento
 * 
 * @param artist Artista cujo tipo se pretende obter
 * @return char* (tipo do artista, pode ser indivudual ou group)
 */
char *get_artist_type(Artist *artist);

/**
 * @brief Define o tipo do artista
 * 
 * É dado free ao tipo atual e é definido um novo tipo para o artista
 * como sendo o tipo passado como argumento
 * 
 * @param artist Artista cujo tipo se pretende definir
 * @param type Tipo do artista
 */
void set_artist_type(Artist *artist, char *type);

//---------------------NUM_ALBUNS_INDIVIDUAL---------------------------
/**
 * @brief Retorna o número de albuns individuais do artista
 * 
 * Retorna o número de albuns que um artista participou individualmente
 * 
 * @param artist Artista cujo número de albuns individuais se pretende obter 
 * @return int (número de albuns individuais do artista)
 */
int get_artist_n_albums_individual(Artist *artist);

/**
 * @brief Define o número de albuns individuais do artista
 * 
 * Define o número de albuns individuais que um artista participou individualmente
 * 
 * @param artist Artista cujo número de albuns individuais se pretende definir
 * @param num_albuns_individual Número de albuns individuais do artista
 */
void set_artist_n_albums_individual(Artist *artist, int num_albuns_individual);

//----------------------------REPRODUCTIONS----------------------------
/**
 * @brief Retorna o a receita total do artista
 * 
 * Retorna a receita total do artista de acordo com o número de reproduções
 * de músicas que o artista tem
 * 
 * @param artist Artista cuja receita total se pretende obter
 * @return double 
 */
double get_artist_reproductions(Artist *artist);

/**
 * @brief Define a receita total do artista
 * 
 * Define a receita total do artista de acordo com o número de reproduções
 * de músicas que o artista tem
 * 
 * @param artist Artista cuja receita total se pretende definir
 * @param reproductions Receita total do artista
 */
void set_artist_reproductions(Artist *artist, double reproductions);

/**
 * @brief Retorna uma cópia de um artista
 * 
 * Retorna uma cópia de um artista passado como argumento
 * 
 * @param artist Artista a ser copiado
 * @return Artist* (cópia do artista)
 */
Artist *copy_artist(Artist *artist);

/**
 * @brief Liberta a memória alocada para um artista
 * 
 * Função que liberta a memória alocada para um artista,
 * incluindo todos os seus campos
 * 
 * @param artist Artista a ser libertado
 */
void free_artist(Artist *artist);

/**
 * @brief Imprime um artista
 * 
 * Função que imprime no terminal todos os campos de um artista
 * 
 * @param artist Artista a ser impresso
 */
void print_artist(Artist *artist);

#endif