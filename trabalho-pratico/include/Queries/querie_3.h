/**
 * @file querie_3.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da terceira query
 */
#ifndef QUERIE_3_H
#define QUERIE_3_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ficheiros
#include "general_manager.h"

/**
 * @brief Resposta à query 3
 * 
 * Função que imprime num ficheiro de texto a resposta à query 3
 * A query 3 consiste em mostrar os géneros de música mais populares
 * numa determinada faxa etária
 * 
 * No ficheiro de output deverá ser impresso o nome do género
 * e o número de likes que esse género, tudo isto por ordem decrescente
 * Caso a faxa etária não seja válida, deverá ser impresso uma linha vazia
 * 
 * @param line Linha que contém a faxa etária e o identificador da query
 * @param cont Número para identificar o ficheiro de output
 * @param gestor Gestor de dados
 */
void third_querie( char *line, int cont, Gestor *gestor);

#endif