/**
 * @file history_manager.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo do Gestor de Histórico
 */
#ifndef HISTORY_MANAGER_H
#define HISTORY_MANAGER_H

//Ficheiros
#include "history.h"
#include "HT_LUS.h"
#include "general_manager.h"

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

typedef struct history_Manager History_Manager;

/**
 * @brief Inicializa o Gestor de Histórico
 * 
 * Função que aloca memória para o Gestor de Histórico,
 * alocando memória para a Hash Table dos Históricos e para 
 * a Hash Table das Listas de Utilizadores
 * 
 * @return History_Manager* 
 */
History_Manager *init_GH();

/**
 * @brief Liberta a memória ocupada pelo Gestor de Histórico
 * 
 * Função que liberta a memória alocada para o Gestor de Histórico,
 * libertando também a memória alocada para a Hash Table dos Históricos
 * e para a Hash Table das Listas de Utilizadores
 * 
 * @param hm (Gestor de Histórico)
 */
void free_GH(History_Manager *hm);

/**
 * @brief Adiciona um Histórico ao Gestor de Histórico
 * 
 * Função que adiciona um Histórico passado como argumento
 * ao Gestor de Histórico
 * 
 * @param hm (Gestor de Histórico)
 * @param h (Histórico que se pretende adicionar)
 */
void add_GH_H(History_Manager *hm, History *h);

/**
 * @brief Retorna uma cópia da lista de históricos de um utilizador
 * 
 * Função que retorna uma cópia da lista de históricos de um utilizador, dado
 * a chave da hash table onde essa lista ligada está guardada, sendo essa chave o id do utilizador
 * 
 * @param hm (Gestor de Histórico)
 * @param user_id (Id do utilizador)    
 * @return LUS* (Lista de históricos de um utilizador)
 */
GHashTable *encapsula_LUS_GH (History_Manager *hm, char *id);

#endif