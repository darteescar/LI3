/**
 * @file artists_manager.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo do gestor de artistas
 */
#ifndef ARTISTS_MANAGER_H
#define ARTISTS_MANAGER_H

// Ficheiros
#include "artists.h"
#include "HT_Artists.h"
#include "HT_ArtTOP.h"

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

// Estruturas dos Artistas
typedef struct artists_Manager Artists_Manager;

/**
 * @brief Initializa o Gestor de Artistas
 * 
 * Função que aloca memória para o Gestor de Artistas e inicializa
 * a Hash Table de Artistas, a Hash Table de Artistas Top e os ALL_TOP_10s
 * 
 * @return Artists_Manager* 
 */
Artists_Manager *init_GA();

/**
 * @brief Liberta a memória alocada para o Gestor de Artistas
 * 
 * Função que liberta a memória alocada para o Gestor de Artistas,
 * libertando também a memória alocada para a Hash Table de Artistas
 * 
 * @param am Gestor de Artistas a ser libertado
 */
void free_GA(Artists_Manager *am);

/**
 * @brief Adiciona um artista ao gestor de artistas
 * 
 * Função que adiciona um artista ao gestor de artistas
 * 
 * @param am Gestor de Artistas
 * @param artist Artista a ser adicionado
 */
void add_GA_A(Artists_Manager *am, Artist *artist);

/**
 * @brief Imprime o gestor de artistas
 * 
 * Função que imprime no terminal as Hash Tables: de Artistas e de Artistas Top
 * 
 * @param am Gestor de Artistas
 */
void print_GA(Artists_Manager *am);

/**
 * @brief Procura um artista numa Hash Table de Artistas
 * 
 * Função que procura um artista numa Hash Table de Artistas
 * dado o id do artista pretendido
 * 
 * @param am Gestor de Artistas
 * @param id Id do artista a procurar
 * @return Artist* (cópia do Artista encontrado, NULL caso não exista)
 */
Artist *search_GA_A (Artists_Manager *am, char *id);

/**
 * @brief Incrementa o número de álbuns de um artista
 * 
 * Função que incrementa o número de álbuns onde o artista participa
 * de forma individual
 * 
 * @param am Gestor de Artistas
 * @param id Id do artista
 */
void increment_GA_artist_n_albums (Artists_Manager *am, char *id);

/**
 * @brief Incrementa a receita de um array de artistas
 * 
 * Função que incrementa a receita de um array de artistas
 * usando a função increment_HT_A_artist_reproductions
 * 
 * @param am Gestor de Artistas
 * @param artists_id Array de ids de artistas
 * @param n_artists Número de artistas
 */
void increment_GA_artist_reproductions (Artists_Manager *am, char **artists_id, int n_artists);

/**
 * @brief Adiciona um artista à Hash Table de Artistas Top
 * 
 * Função que adiciona o tempo de reprodução a uma lista de artistas na Hash Table de Artistas Top
 * que está organizada de acordo com a semana que corresponde à data passada como argumento, 
 * através da função add_HT_week_ArtTOP
 * 
 * @param am Gestor de Artistas
 * @param artists_id Array de ids de artistas
 * @param n_artists Número de artistas
 * @param data Data da reprodução
 * @param duration Duração da reprodução
 */
void add_GA_HT_ArtTOP (Artists_Manager *am, char **artists_id, int n_artists, char *data, int duration);

/**
 * @brief Liberta a tabela principal
 * 
 * Função que liberta a memória alocada para a tabela principal
 * 
 * @param am Gestor de Artistas
 */
void free_GA_tabela_principal (Artists_Manager *am);

/**
 * @brief Liberta os ALL_TOP_10s
 * 
 * Função que liberta a memória alocada para os ALL_TOP_10s
 * 
 * @param am 
 */
void free_GA_ALL_TOP_10s (Artists_Manager *am);

/**
 * @brief Preenche os ALL_TOP_10s
 * 
 * Função que preenche os ALL_TOP_10s com as informações necessárias
 * Esta é a Hash Table que contém para cada semana o top 10 dessa semana
 * 
 * @param am Gestor de Artistas
 */
void preenche_GA_ALL_TOP_10s (Artists_Manager *am);

/**
 * @brief Guarda os resultados da query 4 num arreio
 * 
 * Função auxiliar usada na query 4 que guarda os resultados da query num arreio,
 * No arreio estarão os artistas que estiveram no top 10 semanalmente de todas as semanas
 * consideradas no intervalo de semanas dado, incluindo repetições para contabilizar o número de vezes
 * 
 * @param AM (Gestor de Artistas)
 * @param semana_de_inicio (Semana de início)
 * @param semana_de_fim (Semana de fim)
 * @param flag_se_for_adicionado_algo (Flag de atividade e tamanho atual arreio)
 * @return char** (Arreio de strings com os resultados da query)
 */
char **encapsula_AT10_GA(Artists_Manager *AM, char *semana_de_inicio, char *semana_de_fim, int *flag_se_for_adicionado_algo);

#endif