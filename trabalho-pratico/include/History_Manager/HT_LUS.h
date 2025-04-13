/**
 * @file HT_LUS.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da Hash Table de Listened Users Songs
 */
#ifndef HT_LUS_H
#define HT_LUS_H

// Ficheiros
#include "history.h"

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

/**
 * @brief Inicializa a Hash Table de Listened Users Songs
 * 
 * Função que aloca memória para a Hash Table de Listened Users Songs
 * 
 * @return GHashTable* 
 */
GHashTable *init_HT_LUS ();

/**
 * @brief Liberta a Hash Table de Listened Users Songs
 * 
 * Função que liberta a memória alocada para a Hash Table de Listened Users Songs
 * 
 * @param table (Hash Table de Listened Users Songs)
 */
void free_HT_LUS (GHashTable *table);

/**
 * @brief Inicializa a Hash Table de históricos de um utilizador
 * 
 * Função que aloca memória para a Hash Table de históricos de um utilizador
 * 
 * @return GHashTable* Hash Table de históricos de um utilizador
 */
GHashTable *init_HT_history ();

/**
 * @brief Liberta a Hash Table de históricos de um utilizador
 * 
 * Função que liberta a memória alocada para a Hash Table de históricos de um utilizador
 * 
 * @param table (Hash Table de históricos de um utilizador)
 */
void free_HT_history (GHashTable *table);

/**
 * @brief Liberta a Hash Table de Listened Users Songs
 * 
 * Função que liberta a memória alocada para a Hash Table de Listened Users Songs
 * 
 * @param table Hash Table de Listened Users Songs
 */
void free_HT_LUS (GHashTable *table);

/**
 * @brief Adiciona um histórico à Hash Table de Listened Users Songs
 * 
 * Função que adiciona um histórico à Hash Table de Listened Users Songs
 * 
 * @param table Hash Table de Listened Users Songs
 * @param h Histórico
 */
void add_HT_LUS (GHashTable *table, History *h);

/**
 * @brief Procura a Hash Table de históricos de um utilizador
 * 
 * Função que procura a Hash Table de históricos de um utilizador
 * 
 * @param table Hash Table de Listened Users Songs
 * @param user_id User ID
 * @return GHashTable* Hash Table de históricos de um utilizador
 */
GHashTable *search_HT_LUS (GHashTable *table, char *user_id);

/**
 * @brief Encapsula a Hash Table de Listened Users Songs
 * 
 * Função que encapsula a Hash Table de Listened Users Songs,
 * fazendo uma cópia de uma Hash Table de históricos de um utilizador
 * 
 * @param table Hash Table de Listened Users Songs
 * @param user_id User ID
 * @return GHashTable* Uma cópia da Hash Table de históricos de um utilizador
 */
GHashTable *encapsula_LUS (GHashTable *table, char *user_id);

/**
 * @brief Faz uma cópia da Hash Table de históricos de um utilizador
 * 
 * Função que faz uma cópia da Hash Table de históricos de um utilizador
 * 
 * @param table Hash Table de históricos de um utilizador
 * @return GHashTable* Cópia da Hash Table de históricos de um utilizador
 */
GHashTable *copy_LUS (GHashTable *table);

#endif