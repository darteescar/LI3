/**
 * @file users_manager.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo do Gestor de Users
 */
#ifndef USERS_MANAGER_H
#define USERS_MANAGER_H

// Ficheiros
#include "users.h"
#include "HT_User.h"
#include "GR_User.h"

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do User_Manager
typedef struct users_Manager Users_Manager;

/**
 * @brief Inicializa o Gestor de Users
 * 
 * Função que aloca memória para o Gestor de Users
 * e para as suas HashTables
 * 
 * @return Users_Manager* 
 */
Users_Manager *init_GU();

/**
 * @brief Liberta o Gestor de Users
 * 
 * Função que liberta a memória alocada para o Gestor de Users
 * e para as suas HashTables
 * 
 * @param um Gestor de Users
 */
void free_GU(Users_Manager *um);

/**
 * @brief Adiciona um utilizador ao Gestor de Users
 * 
 * Função que adiciona um utilizador ao Gestor de Users
 * 
 * @param um Gestor de Users
 * @param u Utilizador a adicionar
 */
void add_GU_HT_U (Users_Manager *um, User *u);

/**
 * @brief Incrementa o contador de um género
 * 
 * Função que incrementa o contador de um género na Hash Table de géneros
 * através da idade do utilizador
 * 
 * @param um Gestor de Users
 * @param genre Género da música
 * @param idade_ptr Idade do utilizador
 */
void add_GU_HT_GR_User_Songs (Users_Manager *um, char *genre, int *idade_ptr);

/**
 * @brief Retorna a Hash Table de utilizadores
 * 
 * Função que retorna a Hash Table de utilizadores
 * 
 * @param um Gestor de Users
 * @return GHashTable* (Hash Table de utilizadores)
 */
GHashTable *get_GU_HT_U(Users_Manager *um);

/**
 * @brief Imprime o Gestor de Users
 * 
 * Função que imprime no terminal o Gestor de Users
 * ou seja, a Hash Table de utilizadores e a Hash Table de géneros
 * 
 * @param um Gestor de Users
 */
void print_GU(Users_Manager *um);

/**
 * @brief Retorna a Hash Table de géneros
 * 
 * Função que retorna a Hash Table de géneros
 * 
 * @param um Gestor de Users
 * @return GHashTable* (Hash Table de géneros)
 */
GHashTable *get_GU_HT_GC(Users_Manager *um);

/**
 * @brief Procura um utilizador na Hash Table
 * 
 * Função que procura um utilizador na Hash Table dos utilizadores dado o seu username
 * 
 * @param um Gestor de Users
 * @param id Username do utilizador a procurar
 * @return User* Utilizador encontrado, NULL caso não exista
 */
User* search_GU_HT_U (Users_Manager *um, char *id);

/**
 * @brief Liberta a Hash Table de géneros
 * 
 * Função que liberta a memória alocada para a Hash Table de géneros
 * 
 * @param um Gestor de Users
 */
void free_GU_HT_GC(Users_Manager *um);

/**
 * @brief Guarda os resultados da query 3 em arreios
 * 
 * Função auxiliar usada na query 3 que guarda os resultados da query,
 * numa lisa ligada de géneros e suas respetivas contagens
 * e os imprimie em ficheiros de texto
 * 
 * @param um (Gestor de Users)
 * @param acumulador_head (Lista ligada onde se irão guardar os géneros e as suas contagens)
 * @param minIdade (Idade mínima)
 * @param maxIdade (Idade máxima)
 * @return Genre_Count* (Lista ligada de géneros e suas contagens)
 */
Genre_Count* encapsula_GC_GU (Users_Manager *um, Genre_Count *acumulador_head, int minIdade, int maxIdade);

#endif