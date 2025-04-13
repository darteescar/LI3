/**
 * @file querie_iter_5.h
 * @author Grupo 25
 * @brief Header file do módulo da quinta query iterativa
 */
#ifndef QUERIE_ITER_5_H
#define QUERIE_ITER_5_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ficheiros
#include "general_manager.h"
#include "parser.h"

/**
 * @brief Função que trata da versão iterativa da quinta query
 * 
 * Função que imprime no terminal a resposta à query 5
 * A query 5 consiste em listar N utilizadores com o gostos parecidos a um dado utilizador
 * 
 * Para tal, é tida em conta uma matriz de gostos dos utilizadores, onde cada linha corresponde a um utilizador
 * e um array de utilizadores, onde cada posição corresponde ao id de um utilizador
 * (o id do utilizador na posição i da matriz é o id na posição i do array)
 * 
 * Estas estruturas passam por um recomendador que devolve
 * os N utilizadores mais parecidos com o utilizador dado
 * 
 * @param id (Id do utilizador)
 * @param n (Número de recomendações a mostrar)
 * @param gestor (Gestor principal)
 * @param matriz (Matriz de de gostos dos utilizadores)
 * @param array (Array de users)
 * @param tamanho_atual (Tamanho atual do array e da matriz (número de linhas))
 */
void fifth_querie_iter(char *id, int n, Gestor *gestor, int ***matriz, char ***array, int *tamanho_atual);

#endif