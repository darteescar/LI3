/**
 * @file parser.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo de parser
 */
#ifndef PARSER_H
#define PARSER_H

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ficheiros
#include "Artists_Manager/artists.h"
#include "Musics_Manager/musics.h"
#include "Users_Manager/users.h"
#include "Albums_Manager/albums.h"
#include "History_Manager/history.h"
#include "general_manager.h"
#include "Queries/querie_1.h"
#include "Queries/querie_2.h"
#include "Queries/querie_3.h"
#include "Queries/querie_4.h"
#include "Queries/querie_5.h"
#include "Queries/querie_6.h"
#include "utilidades.h"

/**
 * @brief Função responsáver pelo parser dos ficheiros CSV
 * 
 * Função que lê os ficheiro CSV na pasta especificada e chama as funções de parser
 * individuais para cada tipo de ficheiro CSV
 * preenchendo as estruturas de dados do gestor com os dados lidos nos ficheiros CSV e 
 * guardando as linhas inválidas em ficheiro de erros
 * 
 * @param path (Caminho para a pasta que contém os ficheiros CSV)
 * 
 * @return Gestor* (Gestor principal)
 */
void parser_csv(char *path, Gestor* gestor);

/**
 * @brief Função responsável pelo parser do ficheiro de histórico
 * 
 * Função que recebe uma linha do ficheiro de histórico 
 * e a transforma numa estrutura de dados do tipo History
 * 
 * @param line (Linha do ficheiro de histórico)
 * @param platform (Plataforma, útil para a validação do histórico)
 * 
 * @return History* (Apontador para uma estrutura de dados do tipo History)
 */
History* parser_line_H(char* line, char *platform);

/**
 * @brief Função responsável pelo parser do ficheiro de álbuns
 * 
 * Função que recebe uma linha do ficheiro de álbuns
 * e a transforma numa estrutura de dados do tipo Album
 * 
 * @param line (Linha do ficheiro de álbuns)
 * 
 * @return Album* (Apontador para uma estrutura de dados do tipo Album)
 */
Album* parse_line_Al(char *line, int *flag);

/**
 * @brief Função responsável pelo parser do ficheiro de utilizadores
 * 
 * Função que recebe uma linha do ficheiro de utilizadores
 * e a transforma numa estrutura de dados do tipo User
 * 
 * @param line (Linha do ficheiro de utilizadores)
 * 
 * @return User* (Apontador para uma estrutura de dados do tipo User)
 */
User* parse_line_U(char *line);

/**
 * @brief Função responsável pelo parser do ficheiro de artistas
 * 
 * Função que recebe uma linha do ficheiro de artistas
 * e a transforma numa estrutura de dados do tipo Artist
 * 
 * @param line (Linha do ficheiro de artistas)
 * 
 * @return Artist* (Apontador para uma estrutura de dados do tipo Artist)
 */
Artist* parse_line_A(char *line, int *flag);

/**
 * @brief Função responsável pelo parser do ficheiro de músicas
 * 
 * Função que recebe uma linha do ficheiro de músicas
 * e a transforma numa estrutura de dados do tipo Music
 * 
 * @param line (Linha do ficheiro de músicas)
 * 
 * @return Music* (Apontador para uma estrutura de dados do tipo Music)
 */
Music* parse_line_M(char *line, int *flag);


/**
 * @brief Função responsável pela inicialização das estruturas de dados
 * 
 * Função que inicializa as estruturas de dados auxiliares para as queries
 * no momento do inicio da execução da respetiva query
 * 
 * @param gestor (Gestor principal)
 * @param num_q (Número de queries)
 * @param est_q (Estrutura de queries)
 */
void inicializa_estruturas(Gestor *gestor, int num_q, int est_q);

/**
 * @brief Função responsável pelo parser do ficheiro de queries
 * 
 * Função que lê o ficheiro de queries 
 * e chama as funções de queries para cada linha lida
 * 
 * @param path (Caminho para o ficheiro de queries)
 * 
 * @return Gestor* (Gestor principal)
 */
void parser_queries(char* path, Gestor* gestor);

#endif