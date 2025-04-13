/**
 * @file GR_User.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da Hash Table de Géneros 
 */
#ifndef GR_USER_H
#define GR_USER_H

#include "Users_Manager/users.h"
#include "Musics_Manager/HT_Music.h"

typedef struct genre_count Genre_Count;

/**
 * @brief Inicializa a Hash table de géneros
 * 
 * Função que aloca memória para a Hash Table de géneros
 * 
 * @return GHashTable* 
 */
GHashTable *init_HT_GR ();

/**
 * @brief Liberta a lista ligada de géneros
 * 
 * Função que liberta a memória alocada para uma lista ligada de géneros
 * 
 * @param gc Género a ser libertado
 */
void free_HT_GR_value(Genre_Count *gc);

/**
 * @brief Liberta a Hash Table de géneros
 * 
 * Função que liberta a memória alocada para a Hash Table de géneros
 * 
 * @param table Hash Table a ser libertada
 */
void free_HT_GR (GHashTable *table);

/**
 * @brief Incrementa o contador de um género
 * 
 * Função que incrementa o contador de um género
 * 
 * @param gc Lista ligada de géneros
 * @param genre Género a ser incrementado
 * @return int (1 caso tenha incrementado, 0 caso contrário)
 */
int increment_GR (Genre_Count *gc, char *genre);

/**
 * @brief Adiciona um género à lista ligada
 * 
 * Função que adiciona um género à lista ligada
 * 
 * @param gc Lista ligada de géneros
 * @param genre Género a ser adicionado
 * @return Genre_Count* (Lista ligada de géneros atualizada)
 */
Genre_Count* add_GR_genre (Genre_Count *gc, char *genre) ;

/**
 * @brief Adiciona um utilizador à Hash Table de géneros
 * 
 * Função que incrementa o contador de um género de acordo com as músicas que o 
 * utilizador gosta (tendo em conta a sua idade).
 * 
 * @param table Hash Table de géneros
 * @param genre Género a ser incrementado
 * @param idade_ptr Idade do utilizador
 */
void add_HT_GR_User_Songs(GHashTable *table, char *genre, int *idade_ptr);

/**
 * @brief Imprime a Hash Table de géneros
 * 
 * Função que imprime no terminal a Hash Table de géneros
 * 
 * @param table Hash Table de géneros
 */
void print_HT_GR (GHashTable *table);

/**
 * @brief Ordena a lista ligada de géneros
 * 
 * Função que ordena a lista ligada de géneros de acordo com o contador
 * 
 * @param gr Lista ligada de géneros
 */
void ordena_GR_LL (Genre_Count *gr);

/**
 * @brief Cria um novo nó da lista ligada de géneros
 * 
 * Função que aloca memória para um novo nó da lista ligada de géneros
 * 
 * @param genre Género a ser adicionado
 * @param count Contador do género
 * @return Genre_Count* (Novo nó da lista ligada de géneros)
 */
Genre_Count* create_GR (char *genre, int count);

/**
 * @brief Retorna o contador de um género
 * 
 * Função que retorna o contador de um género
 * 
 * @param gr Lista ligada de géneros
 * @return int (Contador do género)
 */
int get_count_GR (Genre_Count *gr);

/**
 * @brief Retorna o género de um nó da lista ligada
 * 
 * Função que retorna o género de um nó da lista ligada
 * 
 * @param gr Lista ligada de géneros
 * @return char* (Género do nó)
 */
char *get_genre_GR (Genre_Count *gr);

/**
 * @brief Adiciona um contador a um género
 * 
 * Função que atualiza o valor do contador a um género
 * 
 * @param gr Lista ligada de géneros
 * @param count Contador a ser adicionado
 */
void add_count_GR (Genre_Count *gr, int count);

/**
 * @brief Atualiza o próximo nó da lista ligada
 * 
 * Função que atualiza o próximo nó da lista ligada
 * 
 * @param gr Nó atual
 * @param next Próximo nó
 */
void update_next_GR (Genre_Count *gr, Genre_Count *next);

/**
 * @brief Retorna o próximo nó da lista ligada
 * 
 * Função que retorna o próximo nó da lista ligada
 * 
 * @param gr Nó atual
 * @return Genre_Count* (Próximo nó)
 */
Genre_Count* get_next_GR (Genre_Count *gr);

/**
 * @brief Guarda os resultados da query 3 em arreios
 * 
 * Função auxiliar usada na query 3 que guarda os resultados da query,
 * numa lisa ligada de géneros e suas respetivas contagens
 * e os imprimie em ficheiros de texto
 * 
 * @param table (Hash Table de géneros)
 * @param acumulador_head (Lista ligada onde se irão guardar os géneros e as suas contagens)
 * @param minIdade (Idade mínima)
 * @param maxIdade (Idade máxima)
 * @return Genre_Count* (Lista ligada de géneros e suas contagens)
 */
Genre_Count* encapsula_GC (GHashTable *table, Genre_Count *acumulador_head, int minIdade, int maxIdade);

#endif