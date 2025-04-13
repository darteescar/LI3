/**
 * @file HT_ArtTOP.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo das Hash Tables usadas na quarta querie
 */
#ifndef HT_ARTIST_TOP_H
#define HT_ARTIST_TOP_H

//Ficheiros
#include "artists.h"

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

typedef struct artista_top Artist_Top;

/**
 * @brief Inicializa a HashTable de artistas top
 * 
 * Função que aloca memória para a HashTable onde são todos os artistas
 * que foram ouvido durante uma determinada semana, juntamente com o tempo
 * total de reprodução.
 * 
 * @return GHashTable* 
 */
GHashTable *criar_tabela_artista_top();

/**
 * @brief Inicializa a HashTable principal
 * 
 * Função que aloca memória para a HashTable principal onde são guardadas
 * todas as HashTables de artistas top de cada semana.
 * 
 * @return GHashTable* 
 */
GHashTable *criar_tabela_principal();

/**
 * @brief Função que calcula a semana
 * 
 * Função que recebe uma data e devolve a semana correspondente.
 * O formato da semana calculada é NS/ANO, onde NS é o número da semana
 * 
 * @param data Data a ser analisada
 * @return char* (Semana correspondente)
 */
char *calc_semana(char *data);

/**
 * @brief Adiciona os artistas top à HashTable principal
 * 
 * Função que adiciona os artistas top à HashTable principal, sendo eles
 * guardados numa HashTable de artistas top de uma determinada semana.
 * 
 * @param tabela_principal HashTable principal
 * @param artist_id Lista de ids dos artistas
 * @param n_artists Número de artistas
 * @param data Data da semana
 * @param duration Tempo de reprodução
 */
void add_HT_week_ArtTOP (GHashTable *tabela_principal, char **artist_id, int n_artists, char *data, int duration);

/**
 * @brief Liberta a memória alocada para um artista top
 * 
 * Função que liberta a memória alocada para um artista top,
 * incluindo todos os seus campos. Usada na hora de libertar a HashTable
 * 
 * @param dados Artista top a ser libertado
 */
void liberar_artista_top(gpointer dados);

/**
 * @brief Liberta a memória alocada para a HashTable principal
 * 
 * Função que liberta a memória alocada para a HashTable principal,
 * incluindo todos os seus campos
 * 
 * @param tabela_principal HashTable principal a ser libertada
 */
void liberar_tabela_principal(GHashTable *tabela_principal);

/**
 * @brief Imprime a HashTable de artistas top
 * 
 * Função que imprime no terminal a HashTable de artistas top
 * de todas as semanas guardadas na HashTable principal
 * 
 * @param tabela_principal HashTable principal a ser impressa
 */
void print_HT_week_ArtTOP (GHashTable *tabela_principal);

/**
 * @brief Função que devolve o id do artista top
 * 
 * Função que devolve o id do artista top
 * 
 * @param artista_top Artista top
 * @return char* (Id do artista top)
 */
char *get_artist_top_id(Artist_Top *artista_top);

/**
 * @brief Função que devolve o tempo de reprodução do artista top
 * 
 * Função que devolve o tempo de reprodução do artista top
 * 
 * @param artista_top Artista top
 * @return int (Tempo de reprodução do artista top)
 */
int get_artista_top_t_reproducao(Artist_Top *artista_top);

// ----------------------------- ALL_TOP_10s -----------------------------
//estrututa para guardar os artistas top 10 de cada semana

typedef struct topentry TopEntry;

typedef struct minheap MinHeap;

/**
 * @brief Inicializa uma nova MinHeap
 * 
 * Função que aloca memória para uma nova MinHeap, 
 * inicializando o campo size a 0 e o campo capacity ao valor passado como argumento.
 * 
 * @param capacity Capacidade da MinHeap
 * @return MinHeap* 
 */
MinHeap* init_min_heap(int capacity);

/**
 * @brief Troca dois elementos da MinHeap
 * 
 * Função que troca dois elementos da MinHeap.
 * 
 * @param a Elemento a que vai ser trocado
 * @param b Elemento b que vai ser trocado
 */
void swap(TopEntry *a, TopEntry *b);

/**
 * @brief Bubble down
 * 
 * Função que faz bubble down na MinHeap,
 * a partir do índice passado como argumento.
 * 
 * @param heap MinHeap
 * @param index Indice
 */
void heapify_down(MinHeap *heap, int index);

/**
 * @brief Bubble up
 * 
 * Função que faz bubble up na MinHeap,
 * a partir do índice passado como argumento.
 * 
 * @param heap MinHeap
 * @param index Indice
 */
void heapify_up(MinHeap *heap, int index);

/**
 * @brief Insere um novo elemento na MinHeap
 * 
 * Função que insere um novo elemento na MinHeap.
 * 
 * @param heap MinHeap
 * @param artist_id ID do artista
 * @param t_reproducao Tempo de reprodução
 */
void insert_min_heap(MinHeap *heap, char *artist_id, int t_reproducao);

/**
 * @brief Liberta a MinHeap
 * 
 * Função que liberta a memória alocada para a MinHeap.
 * 
 * @param heap MinHeap
 */
void free_min_heap(MinHeap *heap);

/**
 * @brief Inicializa a HashTable ALL_TOP_10s
 * 
 * Função que aloca memória para a HashTable ALL_TOP_10s.
 * 
 * @return GHashTable* 
 */
GHashTable *init_ALL_TOP_10s ();

/**
 * @brief Liberta a HashTable ALL_TOP_10s
 * 
 * Função que liberta a memória alocada para a HashTable ALL_TOP_10s.
 * 
 * @param ALL_TOP_10s 
 */
void free_ALL_TOP_10s (GHashTable *ALL_TOP_10s);

/**
 * @brief Adiciona os artistas top 10 à HashTable ALL_TOP_10s
 * 
 * Função que adiciona os artistas top 10 à HashTable ALL_TOP_10s.
 * 
 * @param ALL_TOP_10s HashTable ALL_TOP_10s
 * @param semana Semana
 * @param heap MinHeap
 */
void add_top_10 (GHashTable *ALL_TOP_10s, char *semana, MinHeap *heap);

/**
 * @brief Liberta a memória alocada para os artistas top 10
 * 
 * Função que liberta a memória alocada para os artistas top 10.
 * 
 * @param dados 
 */
void free_top_10s(void* dados);

/**
 * @brief Preenche a HashTable ALL_TOP_10s
 * 
 * Função que preenche a HashTable ALL_TOP_10s com os artistas 
 * top 10 de todas as semanas.
 * 
 * @param tabela_principal HashTable principal
 * @param ALL_TOP_10s HashTable ALL_TOP_10s
 */
void *preenche_ALL_TOP_10s (GHashTable *tabela_principal, GHashTable *ALL_TOP_10s);

/**
 * @brief Devolve o tamanho da MinHeap
 * 
 * Função que devolve o tamanho da MinHeap
 * 
 * @param heap MinHeap
 * @return int (Tamanho da MinHeap)
 */
int get_MinHeap_size(MinHeap *heap);

/**
 * @brief Devolve o id do artista top
 * 
 * Função que devolve o id de um artista específico da MinHeap (usando a variável index)
 * 
 * @param heap MinHeap
 * @param index Indice
 * @return char* (Id do artista top)
 */
char *get_MinHeap_artist_id (MinHeap *heap, int index);

/**
 * @brief Verifica se uma semana pertence a um intervalo de semanas
 * 
 * Função que verifica se uma semana pertence a um intervalo de semanas.
 * 
 * @param semana Semana
 * @param semana_de_inicio Semana de início
 * @param semana_de_fim Semana de fim
 * @return int 
 */
int semana_pertence_ao_intervalo_de_semanas_pedido(char *semana, char *semana_de_inicio, char *semana_de_fim);

/**
 * @brief Guarda os resultados da query 4 num arreio
 * 
 * Função auxiliar usada na query 4 que guarda os resultados da query num arreio,
 * No arreio estarão os artistas que estiveram no top 10 semanalmente de todas as semanas
 * consideradas no intervalo de semanas dado, incluindo repetições para contabilizar o número de vezes
 * 
 * @param GHashTable (Hash Table de artistas top 10)
 * @param semana_de_inicio (Semana de início)
 * @param semana_de_fim (Semana de fim)
 * @param flag_se_for_adicionado_algo (Flag de atividade e tamanho atual arreio)
 * @return char** (Arreio de strings com os resultados da query)
 */
char **encapsula_AT10 (GHashTable *all_top_10_s, char *semana_de_inicio, char *semana_de_fim, int *flag_se_foi_adicionado_algo);

#endif