/**
 * @file HT_Albums.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da Hash Table dos Albums
 */
#ifndef HT_ARTIST_H
#define HT_ARTIST_H

//Ficheiros
#include "albums.h"

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

/**
 * @brief Inicializa a Hash Table dos Albums
 * 
 * @return GHashTable* (Hash Table dos Albums)
 */
GHashTable *init_HT_Al ();

/**
 * @brief Função que liberta a memória de um album
 * 
 * @param album Album a ser libertado
 */
void free_HT_Al_value (void *album);

/**
 * @brief Adiciona um album à Hash Table
 * 
 * Função que adiciona um album à Hash Table dos albums
 * 
 * @param a Album a ser adicionado
 * @param ht HashTable dos albums
 */
void add_HT_Al_Al (Album *a, GHashTable *ht);

/**
 * @brief Função que liberta a memória da Hash Table dos albums
 * 
 * @param ht HashTable dos albums
 */
void free_HT_Al (GHashTable *ht);

/**
 * @brief Procura um album na Hash Table
 * 
 * Função que procura um album na Hash Table dos albums
 * 
 * @param ht Hash Table dos albums
 * @param id id do album a ser procurado
 * @return Album* (Album procurado, NULL caso não exista)
 */
Album *search_HT_Al (GHashTable *ht, char *id);

/**
 * @brief Imprime a Hash Table dos albums
 * 
 * Função que imprime a Hash Table dos albums
 * 
 * @param ht Hash Table dos albums
 */
void print_HT_Al (GHashTable *ht);

/**
 * @brief Função que liberta a memória de uma key
 * 
 * @param key Key a ser libertada
 */
void free_HT_Al_key (void *key);

#endif