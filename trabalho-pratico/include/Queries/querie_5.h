/**
 * @file querie_5.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da quinta query
 */
#ifndef QUERIE_5_H
#define QUERIE_5_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ficheiros
#include "general_manager.h"

/**
 * @brief Resposta à query 5
 * 
 * Função que imprime num ficheiro de texto a resposta à query 5
 * A query 5 consiste em listar N utilizadores com o gostos parecidos a um dado utilizador
 * 
 * Para tal, é tida em conta uma matriz de gostos dos utilizadores, onde cada linha corresponde a um utilizador
 * e um array de utilizadores, onde cada posição corresponde ao id de um utilizador
 * (o id do utilizador na posição i da matriz é o id na posição i do array)
 * 
 * Estas estruturas passam por um recomendador que devolve
 * os N utilizadores mais parecidos com o utilizador dado
 * 
 * @param line Linha que contém o id do utilizador os N utilizadores a listar e o identificador da query
 * @param cont Número para identificar o ficheiro de output
 * @param gestor Gestor de dados
 * @param matriz Matriz de gostos dos utilizadores
 * @param array Array de utilizadores
 * @param tamanho_atual Tamnho atual do array e da matriz (número de linhas)
 */
void fifth_querie(char *line, int cont, Gestor *gestor, int ***matriz, char ***array, int *tamanho_atual);

/**
 * @brief Função que dado o id de um user, adiciona os seus gostos à matriz e o seu id ao array
 * 
 * Função que dado o id de um user, adiciona os seus gostos 
 * à matriz e o seu id ao array e altera o tamnho atual,
 * e recebe como argumento o gestor principal e apontadores 
 * para a matriz, o array, o tamanho atual e o id do user
 * 
 * @param gestor (Gestor principal)
 * @param matriz (Apontador para Matriz de gostos dos utilizadores)
 * @param array (Apontador para o array de users)
 * @param linha (Apontador para a linha atual da matriz(int))
 * @param tamanho_atual (Apontador para o tamanho atual(int)) 
 * @param username (Id do user)
 * 
 */
void faz_matriz_e_array2(Gestor *gestor, int ***matriz, char ***array, int *linha, int *tamanho_atual, char *username);

/**
 * @brief Função que preenche a matriz e o array com os dados dos utilizadores
 * 
 * Função que preenche a matriz e o array com os dados dos utilizadores
 * iterando sobre a hashtable de users e chamando a função faz_matriz_e_array2
 * para cada user, recebendi como argumento o gestor principal e apontadores
 * para a matriz, o array e o tamanho atual
 * 
 * @param gestor (Gestor principal)
 * @param matriz (Apontador para Matriz de gostos dos utilizadores)
 * @param array (Apontador para o array de users)
 * @param tamanho_atual (Apontador para o tamanho atual(int))
 * 
 */
void faz_matriz_array_aux (Gestor *gestor, int ***matriz, char ***array, int *tamanho_atual);

/**
 * @brief Função que liberta a memória alocada para a matriz e o array
 * 
 * Função que liberta a memória alocada para a matriz e o array usados
 * na querie 5
 * 
 * @param matriz (Matriz de gostos dos utilizadores)
 * @param array (Array de users)
 * @param tamanho_atual (Tamanho atual do array)
 * 
 */
void free_matriz_array(int **matriz, char **array, int tamanho);

#endif