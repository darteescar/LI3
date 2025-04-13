/**
 * @file querie_1.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da primeira query
 */
#ifndef QUERIE_1_H
#define QUERIE_1_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ficheiros
#include "general_manager.h"

/**
 * @brief Resposta à query 1
 * 
 * Função que imprime num ficheiro de texto a resposta à query 1
 * A query 1 consiste em listar o resumo de um utilizador ou de um artista, 
 * consoante o id fornecido.
 * 
 * No caso do id não exista, no ficheiro deverá apenas estar uma linha vazia
 * Caso o id exista, se for de um utilizador, deverá ser impresso 
 * o email, primeiro e último nome,idade e país
 * Se for de um artista, deverá ser impresso o nome, o tipo, número de albuns
 * que participou, e a sua receita total
 * 
 * @param gestor Gestor de dados
 * @param line Linha qua contém o id e o identificador da query
 * @param cont Número para identificar o ficheiro de output
 */
void first_querie(Gestor *gestor, char *line, int cont);

#endif