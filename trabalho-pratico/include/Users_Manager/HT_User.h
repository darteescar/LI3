/**
 * @file HT_User.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da Hash Table dos utilizadores
 */
#ifndef HT_USER_H
#define HT_USER_H

// Ficheiros
#include "users.h"

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

/**
 * @brief Inicializa a Hash Table dos utilizadores
 * 
 * Função que aloca memória para a Hash Table dos utilizadores
 * 
 * @return GHashTable* 
 */
GHashTable *init_HT_U();

/**
 * @brief Liberta a Hash Table dos utilizadores
 * 
 * Função que liberta a memória alocada para a Hash Table dos utilizadores
 * 
 * @param table Hash Table dos utilizadores
 */
void free_HT_U(GHashTable *table);

/**
 * @brief Liberta o username de um utilizador
 * 
 * Função que liberta a memória alocada para o username de um utilizador
 * 
 * @param username Username do utilizador
 */
void free_HT_U_key(void *username);

/**
 * @brief Liberta um utilizador
 * 
 * Função que liberta a memória alocada para o utilizador 
 * e para os seus campos
 * 
 * @param User Utilizador
 */
void free_HT_U_value(void *User);

/**
 * @brief Adiciona um utilizador à Hash Table
 * 
 * Função que adiciona um utilizador à Hash Table dos utilizadores
 * 
 * @param table Hash Table dos utilizadores
 * @param u Utilizador a adicionar
 */
void add_HT_U(GHashTable *table, User *u);

/**
 * @brief Procura um utilizador na Hash Table
 * 
 * Função que procura um utilizador na Hash Table dos utilizadores
 * 
 * @param table Hash Table dos utilizadores
 * @param username Username do utilizador a procurar
 * @return User* Utilizador encontrado, NULL caso não exista
 */
User *search_HT_U(GHashTable *table, char *username);

/**
 * @brief Imprime a Hash Table dos utilizadores
 * 
 * Função que imprime no terminal a Hash Table dos utilizadores
 * para cada utilizador imprime os seus campos
 * 
 * @param table Hash Table dos utilizadores
 */
void print_HT_U(GHashTable *table);

#endif