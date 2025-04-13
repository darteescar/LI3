/**
 * @file general_manager.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo de general_manager
 */
#ifndef GENERAL_MANAGER_H
#define GENERAL_MANAGER_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ficheiros
#include "recomendador.h"
#include "Musics_Manager/musics_manager.h"
#include "Users_Manager/users_manager.h"
#include "Artists_Manager/artists_manager.h"
#include "Albums_Manager/albums_manager.h"
#include "History_Manager/history_manager.h"

typedef struct gestor Gestor;

//----------------------------------------Funções do Gestor------------------------------------------

/**
 * @brief Inicializa o Gestor
 * 
 * Função que aloca memória para o Gestor Principal, alocando memória para 
 * os gestores de músicas, utilizadores, artistas, albuns e históricos
 * 
 * @return Gestor* (Apontador para uma estrutura de dados do tipo Gestor)
 */
Gestor *init_GP();

/**
 * @brief Imprime o gestor no terminal
 * 
 * Função que imprime no terminal o Gestor Principal, imprimindo
 * os gestores de músicas, utilizadores, artistas, albuns e históricos
 * 
 * @param g (Gestor)
 */
void print_GP(Gestor *g);

/**
 * @brief Liberta a memória ocupada pelo Gestor
 * 
 * Função que liberta a memória alocada para o Gestor, libertando também
 * a memória alocada para os gestores de músicas, utilizadores, artistas, albuns e históricos
 * 
 * @param g (Gestor)
 */
void free_GP(Gestor *g);

//---------------------------------------------Músicas---------------------------------------------

/**
 * @brief Adiciona uma música ao Gestor
 * 
 * Função que adiciona uma música ao Gestor Principal
 * 
 * @param g (Gestor)
 * @param m (Música a adicionar)
 */
void add_GP_M(Gestor *g, Music *m);

/**
 * @brief Procura uma música no Gestor Principal
 * 
 * Função que procura uma música no Gestor Principal
 * dado o seu id
 * 
 * @param g (Gestor)
 * @param id (Id da música a procurar)
 * @return Music* (Música encontrada, NULL caso não exista)
 */
Music* search_GP_M (Gestor *g, char *id);

/**
 * @brief Verifica se uma música existe no Gestor Principal
 * 
 * Função que verifica se uma música existe no Gestor Principal
 * 
 * @param g (Gestor)
 * @param id (Id da música a procurar)
 * @return int (1 caso exista, 0 caso contrário)
 */
const int musica_existe_GP(Gestor *g, char *id);

/**
 * @brief Procura os artistas de uma música no Gestor Principal
 * 
 * Função que procura o número de artistas de uma música no Gestor Principal
 * 
 * @param g (Gestor)
 * @param music_id (Id da música a procurar)
 * @return char** (Array de ids dos artistas)
 */
int search_GP_get_music_n_artists(Gestor *g, char *music_id);

/**
 * @brief Procura os artistas de uma música no Gestor Principal
 * 
 * Função que procura os artistas de uma música no Gestor Principal
 * 
 * @param g (Gestor)
 * @param music_id (Id da música a procurar)
 * @return char** (Array de ids dos artistas)
 */
char **search_GP_get_music_artist_id(Gestor *g, char *music_id);

//-----------------------------------------Utilizadores----------------------------------------------

/**
 * @brief Adiciona um utilizador ao Gestor
 * 
 * Função que adiciona um utilizador ao Gestor Principal
 * 
 * @param g (Gestor)
 * @param u (Utilizador a adicionar)
 */
void add_GP_U (Gestor *g, User *u);

/**
 * @brief Devolve a Hash Table de utilizadores
 * 
 * Função que devolve a Hash Table de utilizadores do Gestor Principal
 * 
 * @param g (Gestor)
 * @return GHashTable* (Hash Table de utilizadores)
 */
GHashTable *get_GP_HT_U(Gestor *g);

/**
 * @brief Procura um utilizador no Gestor Principal
 * 
 * Função que procura um utilizador no Gestor Principal
 * dado o seu id
 * 
 * @param g (Gestor)
 * @param id (Id do utilizador a procurar)
 * @return User* (Utilizador encontrado, NULL caso não exista)
 */
User* search_GP_HT_U (Gestor *g,char *id);

//--------------------------------------------Artistas----------------------------------------------

/**
 * @brief Adiciona um artista ao Gestor
 * 
 * Função que adiciona um artista ao Gestor Principal
 * 
 * @param g (Gestor)
 * @param a (Artista a adicionar)
 */
void add_GP_A (Gestor *g, Artist *a);

/**
 * @brief Procura um artista no Gestor Principal
 * 
 * Função que procura um artista no Gestor Principal
 * dado o seu id
 * 
 * @param g (Gestor)
 * @param id (Id do artista a procurar)
 * @return Artist* (Artista encontrado, NULL caso não exista)
 */
Artist *search_GP_HT_A (Gestor *gestor, char *id);

//----------------------------------------------Albuns----------------------------------------------

/**
 * @brief Adiciona um album ao Gestor
 * 
 * Função que adiciona um album ao Gestor Principal
 * 
 * @param g (Gestor)
 * @param a (Album a adicionar)
 */
void add_GP_Al (Gestor *g, Album *a);

/**
 * @brief Procura um album no Gestor Principal
 * 
 * Função que procura um album no Gestor Principal
 * dado o seu id
 * 
 * @param g (Gestor)
 * @param id (Id do album a procurar)
 * @return Album* (Album encontrado, NULL caso não exista)
 */
Album *search_GP_Al (Gestor *g, char *id);

//----------------------------------------------Histórico----------------------------------------------

/**
 * @brief Adiciona um histórico ao Gestor
 * 
 * Função que adiciona um histórico ao Gestor Principal
 * 
 * @param g (Gestor)
 * @param h (Histórico a adicionar)
 */
void add_GP_H (Gestor *g, History *h);

//----------------------------------------------free's antecipados----------------------------------------------

/**
 * @brief Liberta a memória ocupada pela Hash Table TOP
 * 
 * Função que liberta a memória alocada para a Hash Table TOP,
 * onde se encontram os artistas e os suas discografias por país
 * organizados em Hash Tables
 * 
 * @param g (Gestor)
 */
void free_GP_TOP(Gestor *g);

/**
 * @brief Liberta a memória ocupada pela Hash Table de géneros por idades
 * 
 * Função que liberta a memória alocada para a Hash Table de géneros por idades,
 * onde se encontram os géneros e as suas contagens de likes por idades
 * 
 * @param g (Gestor)
 */
void free_GP_HT_GC(Gestor *g);

/**
 * @brief Liberta a memória ocupada pela Hash Table ArtTOP
 * 
 * Função que liberta a memória alocada para a Hash Table ArtTOP,
 * onde se encontram os artistas e os seus tempos de reprodução por semana
 * organizados em outra Hash Table
 * 
 * @param g (Gestor)
 */
void free_GP_tabela_principal(Gestor *g);

/**
 * @brief Liberta a memória ocupada pela Hash Table ALL_TOP_10s
 * 
 * Função que liberta a memória alocada para a Hash Table ALL_TOP_10s,
 * onde se encontram os artistas top 10 de cada semana em minHeaps
 * 
 * @param g (Gestor)
 */
void free_GP_ALL_TOP_10s(Gestor *g);

//----------------------------------------------preenchimentos atrasados----------------------------------------------

/**
 * @brief Preenche a Hash Table TOP
 * 
 * Função que preenche a Hash Table TOP do Gestor Principal
 * onde se encontram os artistas e os suas discografias por país
 * organizados em Hash Tables
 * 
 * @param g (Gestor)
 */
void preenche_GP_TOP(Gestor *g);

/**
 * @brief Preenche a Hash Table ALL_TOP_10s
 * 
 * Função que preenche a Hash Table ALL_TOP_10s do Gestor Principal,
 * onde se encontram os artistas top 10 de cada semana em minHeaps
 * 
 * @param g (Gestor)
 */
void preenche_GP_ALL_TOP_10s(Gestor *g);

//---------Encapsulamento 

/**
 * @brief Guarda os resultados da query 2 em arrays
 * 
 * Função auxiliar usada na query 2 que guarda os resultados da query em arrays,
 * resultados esses que serão imprimidos em ficheiros de texto
 * 
 * Versão da função onde a query 2 é restringida a um país
 * 
 * 
 * @param gestor (Gestor)
 * @param country (País)
 * @param artists (Array de ids de artistas)
 * @param countries (Array dos países dos artistas)
 * @param discography (Array das discografias dos artistas)
 */
void iter_GP_top(Gestor *g, char *country, char **artists, char **countries, int *discography, int N);

/**
 * @brief Guarda os resultados da query 2 em arreios
 * 
 * Função auxiliar usada na query 2 que guarda os resultados da query em arrays,
 * resultados esses que serão imprimidos em ficheiros de texto
 * 
 * Versão da função onde a query 2 não é restringida a um país
 * 
 * @param gestor (Gestor)
 * @param artists (Array de ids de artistas)
 * @param countries (Array dos países dos artistas)
 * @param discography (Array das discografias dos artistas)
 */
void iter_GP_top_sem_pais(Gestor *g, char **artists, char **countries, int *discography, int N);

/**
 * @brief Guarda os resultados da query 3 numa lista ligada Genre_Count
 * 
 * Função auxiliar usada na query 3 que guarda os resultados da query,
 * numa lisa ligada de géneros e suas respetivas contagens
 * e os imprimie em ficheiros de texto
 * 
 * @param gestor (Gestor)
 * @param acumulador_head (Lista ligada onde se irão guardar os géneros e as suas contagens)
 * @param minIdade (Idade mínima)
 * @param maxIdade (Idade máxima)
 * @return Genre_Count* (Lista ligada de géneros e suas contagens)
 */
Genre_Count* encapsula_GC_GP (Gestor *gestor, Genre_Count *acumulador_head, int minIdade, int maxIdade);

/**
 * @brief Guarda os resultados da query 4 num array
 * 
 * Função auxiliar usada na query 4 que guarda os resultados da query num array,
 * No array estarão os artistas que estiveram no top 10 semanalmente de todas as semanas
 * consideradas no intervalo de semanas dado, incluindo repetições para contabilizar o número de vezes
 * 
 * @param gestor (Gestor)
 * @param semana_de_inicio (Semana de início)
 * @param semana_de_fim (Semana de fim)
 * @param flag_se_for_adicionado_algo (Flag de atividade e tamanho atual array)
 * @return char** (Array de strings com os resultados da query)
 */
char **encapsula_AT10_GP (Gestor *g, char *semana_de_inicio, char *semana_de_fim, int *flag_se_for_adicionado_algo);

/**
 * @brief Retorna uma cópia de uma Hash Table de históricos de um utilizador
 *
 * Função que retorna uma cópia de uma Hash Table de históricos de um utilizador
 *  
 * @param gestor Gestor
 * @param user_id User ID
 * @return GHashTable* Cópia da Hash Table de históricos de um utilizador 
 */
GHashTable *encapsula_LUS_GP (Gestor *gestor, char *user_id);

/**
 * @brief Processa uma música para a Hash Table TOP
 * 
 * Função que processa uma música para a Hash Table TOP
 * 
 * @param m (Música)
 * @param g (Gestor)
 */
void process_music_for_TOP (Music *m, Gestor *g);

/**
 * @brief Verifica se existe uma Hash Table no TOP referente a um país
 * 
 * @param gestor Gestor
 * @param country País
 * @return int Retorna 1 se o país existe na Hash Table TOP, 0 caso contrário
 */
int country_GP_TOP_exists (Gestor *gestor, char *country);

#endif