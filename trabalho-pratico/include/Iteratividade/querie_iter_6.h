/**
 * @file querie_iter_6.h
 * @author Grupo 25
 * @brief Header file do módulo da sexta query iterativa
 */
#ifndef QUERIE_ITER_6_H
#define QUERIE_ITER_6_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ficheiros
#include "general_manager.h"
#include "parser.h"

/**
 * @brief Função que trata da versão iterativa da sexta query
 * 
 * Função que imprime a resposta à sexta query interativa no terminal
 * A query 6 consiste em apresentar um resumo anual de um utilizador num certo ano
 * 
 * No terminal, é escrito o tempo total de audição do utilizador, o número de
 * músicas ouvidas, o artista mais ouvido, o dia em que reproduziu mais músicas, 
 * o género de música mais ouvido, o seu álbum favorito e a hora do dia em que costuma ouvir mais música
 * 
 * Pode ainda ser passado um argumento opcional numérico, N, 
 * sendo que em tal caso devem-se imprimir em linhas consecutivas os
 * N artistas mais ouvidos pelo utilizador nesse ano, 
 * 
 * @param line (Linha que contém o id do utilizador e o ano a pesquisar dados)
 * @param gestor (Gestor principal)
 */
void sixth_querie_iter(char *line, Gestor *gestor);

#endif