/**
 * @file history.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da estrutura History
 */
#ifndef HISTORY_H
#define HISTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct history History;

/**
 * @brief Inicializa a estrutura History
 * 
 * Função que aloca memória para a estrutura History
 * e para todos os seus campos
 * 
 * @return History* 
 */
History* init_history();

/**
 * @brief Retorna o ID de um histórico
 * 
 * Retorna uma cópia do ID de um histórico passado como argumento
 * 
 * @param h Histórico do qual se pretende obter o ID
 * @return char* (cópia do ID)
 */
char* get_history_id(History* h);

/**
 * @brief Define o ID de um histórico
 * 
 * Liberta a memória ocupada pelo ID atual e define um novo ID
 * como sendo o passado como argumento
 * 
 * @param h Histórico ao qual se pretende definir o ID
 * @param history_id ID que se pretende definir
 */
void set_history_id(History* h, char* history_id);

/**
 * @brief Retorna o ID do utilizador de um histórico
 * 
 * Retorna uma cópia do ID do utilizador de um histórico passado como argumento
 * 
 * @param h Histórico do qual se pretende obter o ID do utilizador
 * @return char* (cópia do ID do utilizador)
 */
char* get_user_id_history(History* h);

/**
 * @brief Define o ID do utilizador de um histórico
 * 
 * Liberta a memória ocupada pelo ID do utilizador atual e define um novo ID
 * como sendo o passado como argumento
 * 
 * @param h Histórico ao qual se pretende definir o ID do utilizador
 * @param user_id ID do utilizador que se pretende definir
 */
void set_user_id_history(History* h, char* user_id);

/**
 * @brief Retorna o ID da música de um histórico
 * 
 * Retorna uma cópia do ID da música de um histórico passado como argumento
 * 
 * @param h Histórico do qual se pretende obter o ID da música
 * @return char* (cópia do ID da música)
 */
char* get_music_id_history(History* h);

/**
 * @brief Define o ID da música de um histórico
 * 
 * Liberta a memória ocupada pelo ID da música atual e define um novo ID
 * como sendo o passado como argumento
 * 
 * @param h Histórico ao qual se pretende definir o ID da música
 * @param music_id ID da música que se pretende definir
 */
void set_music_id_history(History* h, char* music_id);

/**
 * @brief Retorna a duração de um históric
 * 
 * Retorna uma cópia do tempo de duração da audição de uma música 
 * de um histórico passado como argumento
 * 
 * @param h Histórico do qual se pretende obter a duração
 * @return char* (cópia da duração)
 */
char* get_duration_history(History* h);

/**
 * @brief Define a duração de um histórico
 * 
 * Liberta a memória ocupada pela duração atual e define uma nova duração
 * como sendo a passada como argumento
 * 
 * @param h Histórico ao qual se pretende definir a duração
 * @param duration Duração que se pretende definir
 */
void set_duration_history(History* h, char* duration);

/**
 * @brief Retorna a hora de um histórico
 * 
 * Função que retorna uma cópia da hora de um histórico
 * 
 * @param h Histórico do qual se pretende obter a hora
 * @return char* H
 */
char *get_hora_history(History *h);

/**
 * @brief Define a hora de um histórico
 * 
 * Função que liberta a memória ocupada pela hora atual de um histórico
 * e define uma nova hora
 * 
 * @param h Histórico ao qual se pretende definir a hora
 * @param hora Hora que se pretende definir
 */
void set_hora_history (History *h, char *hora);

/**
 * @brief Retorna a data de um histórico
 * 
 * Função que retorna uma cópia da data de um histórico
 * 
 * @param h Histórico do qual se pretende obter a data
 * @return char* Data
 */
char *get_data_history(History *h);

/**
 * @brief Define a data de um histórico
 * 
 * Função que liberta a memória ocupada pela data atual de um histórico
 * e define uma nova data
 * 
 * @param h Histórico ao qual se pretende definir a data
 * @param data Data que se pretende definir
 */
void set_data_history (History *h, char *data);

/**
 * @brief Retorna o ano de um histórico
 * 
 * Função que retorna uma cópia do ano de um histórico
 * 
 * @param h Histórico do qual se pretende obter o ano
 * @return int Ano
 */
int get_year_history (History *h);

/**
 * @brief Liberta a memória ocupada por um histórico
 * 
 * Liberta a memória ocupada por um histórico passado como argumento,
 * libertando também a memória ocupada por todos os seus campos
 * 
 * @param h Histórico que se pretende libertar
 */
void free_history(History* h);

/**
 * @brief Imprime um histórico
 * 
 * Imprime no terminal todos os campos de um histórico passado como argumento
 * 
 * @param h Histórico que se pretende imprimir
 */
void print_history(History* h);

/**
 * @brief Retorna uma cópia de um histórico
 * 
 * Retorna uma cópia de um histórico passado como argumento
 * 
 * @param h Histórico que se pretende copiar
 * @return History* (Cópia do histórico)
 */
History *copy_history (History *h);

#endif