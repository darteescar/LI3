/**
 * @file iteratividade.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo de iteratividade principal
 */
#ifndef ITERATIVIDADE_H
#define ITERATIVIDADE_H

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Ficheiros
#include "general_manager.h"
#include "parser.h"
#include "Queries/querie_1.h"
#include "Queries/querie_2.h"
#include "Queries/querie_3.h"
#include "Queries/querie_4.h"
#include "Queries/querie_5.h"
#include "Queries/querie_6.h"
#include "Iteratividade/querie_iter_1.h"
#include "Iteratividade/querie_iter_2.h"
#include "Iteratividade/querie_iter_3.h"
#include "Iteratividade/querie_iter_4.h"
#include "Iteratividade/querie_iter_5.h"
#include "Iteratividade/querie_iter_6.h"
#include "utilidades.h"

/**
 * @brief Função principal para o modo iterativo
 * 
 * Função que recebe um apontador para o gestor principal
 * e é responsável pelo programa em modo iterativo
 * 
 * @param gestor (Gestor principal)
 */
void iterativo(Gestor* gestor);


/**
 * @brief Função auxiliar para verificar qual a data mais recente
 * 
 * Função que recebe duas datas do tipo yyyy/mm/dd sob a forma de string
 * e verifica qual a data é a mais recente entre duas
 * 
 * @param data1 (Primeira data)
 * @param data2 (Segunda data)
 * 
 * @return int (1 se a data 1 for mais recente, 0 caso contrário)
 */
int is_more_recent(char* data1, char* data2);

#endif