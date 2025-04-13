/**
 * @file albums_manager.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo do gestor de albums
 */
#ifndef ALBUMS_MANAGER_H
#define ALBUMS_MANAGER_H

// Ficheiros
#include "albums.h"
#include "HT_Albums.h"

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

// Estruturas dos Artistas
typedef struct albums_Manager Albums_Manager;

/**
 * @brief Inicializa o manager de albums
 * 
 * Inicializa o manager de albums alocando memória para a Hash Table dos albums
 * 
 * @return Albums_Manager* (Estrutura que contém a Hash Table dos albums)
 */
Albums_Manager *init_GAl();

/**
 * @brief Liberta a memória alocada para o manager de albums
 * 
 * Liberta a memória alocada para a Hash Table dos albums e para a estrutura do manager de albums
 * 
 * @param am Manager de albums
 */
void free_GAl(Albums_Manager *am);

/**
 * @brief Adiciona um album ao manager de albums
 * 
 * Adiciona um album à Hash Table dos albums do manager de albums
 * 
 * @param am Manager de albums
 * @param album Album a adicionar
 */
void add_GAl_Al(Albums_Manager *am, Album *album);

/**
 * @brief Procura um album na Hash Table dos albums
 * 
 * Procura um album na Hash Table dos albums do manager de albums
 * 
 * @param am Manager de albums
 * @param id Id do album a procurar
 * @return Album* (Album procurado)
 */
Album *search_GAl_Al (Albums_Manager *am, char *id);

#endif