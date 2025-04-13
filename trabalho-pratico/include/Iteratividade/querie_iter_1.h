/**
 * @file querie_iter_1.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da primeira query iterativa
 */
#ifndef QUERIE_ITER_1_H
#define QUERIE_ITER_1_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ficheiros
#include "general_manager.h"
#include "parser.h"

/**
 * @brief Função que trata da versão iterativa da primeira query
 * 
 * Função que imprime nuo terminal a resposta à query 1
 * A query 1 consiste em listar o resumo de um utilizador ou de um artista, 
 * consoante o id fornecido.
 * 
 * A função recebe como argumentos o gestor principal e o id do utilizador ou artista
 * 
 * @param gestor (Gestor principal)
 * @param id (Id do utilizador ou artista)
 * 
 */
void first_querie_iter(Gestor* gestor, char* id);

#endif