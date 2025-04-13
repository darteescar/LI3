/**
 * @file utilidades.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo de utilidades
 */
#ifndef UTILIDADES_H
#define UTILIDADES_H

// Bibliotecas
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ficheiros
#include "general_manager.h"

/**
 * @brief Função para registrar uma linha inválida no arquivo de erros correspondente
 * 
 * Função que recebe o caminho para um ficheiro e uma string 
 * e regista essa string no fundo desse ficheiro
 * Usada para registar as linhas inválidas dos ficheiros CSV
 * 
 * @param filename (Caminho do ficheiro de erros)
 * @param line (Linha inválida no formato de string)
 */ 
void store_invalid_line(const char *filename, const char *line);

/**
 * @brief Função para obter o caminho completo do ficheiro csv
 * 
 * Função que recebe um caminho para uma pasta e o nome de um ficheiro da pasta 
 * e concatena o caminho da pasta com o nome do ficheiro
 * 
 * @param folder (Caminho da pasta)
 * @param file_name (Nome do ficheiro)
 * 
 * @return char* (Caminho completo do ficheiro)
 */
char *get_file_path(const char *folder, const char *file_name);

/**
 * @brief Função para verificar se uma string representa um número válido
 * 
 * Função que recebe uma string 
 * e verifica se a string representa um número válido
 * 
 * @param num (String a ser verificada)
 * 
 * @return int (1 se for um número válido, 0 caso contrário)
 */
int valida_numero(char *num);

/**
 * @brief Função para validar datas no formato yyyy/mm/dd
 * 
 * Função que valida uma data no formato yyyy/mm/dd e
 * retorna um inteiro que indica se a data é válida ou não
 * 
 * @param date (Data a ser validada)
 * 
 * @return int (1 se a data for válida, 0 caso contrário)
 */
int valida_data(char *date);

/**
 * @brief Função para validar períodos de tempo no formato hh:mm:ss
 * 
 * Função que valida um período de tempo no formato hh:mm:ss e
 * retorna um inteiro que indica se o período de tempo é válido ou não
 * 
 * @param duration (Duração/Período de tempo a ser validada)
 * 
 * @return int (1 se a data for válida, 0 caso contrário)
 */
int valida_duration(char *duration);

/**
 * @brief Função para validar um email
 * 
 * Função que valida um email, sob a forma de string, garantindo
 * que o email tem o formato correto e
 * retorna um inteiro que indica se o email é válido ou não
 * 
 * @param email (Email a ser validado)
 * 
 * @return int (1 se a data for válida, 0 caso contrário)
 */
int valida_email(char *email);

/**
 * @brief Função para validar o tipo de subscrição de um utilizador
 * 
 * Função que valida o tipo de subscrição de um utilizador
 * A função recebe uma string que representa o tipo de subscrição
 * A subscrição pode ser "normal" ou "premium"
 * 
 * @param subscription_type (Tipo de subscrição, na forma de string, a ser validado)
 * 
 * @return int (1 se a data for válida, 0 caso contrário)
 */
int valida_subscription_type (const char *subscription_type);

/**
 * @brief Função para validar o campo "id_constituent" de um artista
 * 
 * Função para validar se o tipo de artista condiz com o número de constituintes do campo "id_constituent" do artista
 * O campo id_constituent de um artista individual não poderá ter elementos
 * O campo id_constituent de um artista grupo deverá ter pelo menos um elemento
 * 
 * @param type Tipo do artista
 * @param n_constituent Número de artistas do campo "id_constituent"
 * 
 * @return int (1 se a data for válida, 0 caso contrário)
 */
int valida_artist_n_constituent(const char *type, int n_constituent);

/** 
 * @brief Função para validar campos do tipo listas
 * 
 * Função para validar se os campos dos ficheiros CSV do tipo lista começam 
 * com os caracteres "[ e terminam com os caracteres "]
 * 
 * @param lista (Campo do tipo lista a ser validado)
 * 
 * @return int (1 se a data for válida, 0 caso contrário)
 */
int valida_listas (char* lista);

/** 
 * @brief Função para validar campos do tipo listas(caso particular dos users)
 * 
 * Função para validar se os campos dos ficheiros CSV do tipo lista 
 * começam com os caracteres "[ e terminam com os caracteres "]
 * 
 * @param lista (Campo do tipo lista a ser validado)
 * 
 * @return int (1 se a data for válida, 0 caso contrário)
 */
int valida_listas_User (char* lista);

/**
 * @brief Função para verificar se o campo type do artista é do tipo individual
 * 
 * Função que verifica se o campo type do artista é do tipo individual
 * A string recebida é inválida se não for do tipo individual
 * 
 * @param type (Tipo do artista no formato de string)
 * 
 * @return int (1 se a data for válida, 0 caso contrário)
 */
int verifica_type_individual(const char* type);

/**
 * @brief Função para verificar se o campo type do artista é do tipo grupo
 * 
 * Função que verifica se o campo type do artista é do tipo grupo
 * A string recebida é inválida se não for do tipo grupo
 * 
 * @param type (Tipo do artista no formato de string)
 * 
 * @return int (1 se a data for válida, 0 caso contrário)
 */
int verifica_type_group(const char* type);

/**
 * @brief Função para validar o campo type do artista
 * 
 * Função que valida o campo type do artista usando 
 * as funções verifica_type_individual e verifica_type_group
 * 
 * @param type (Tipo do artista no formato de string)
 * 
 * @return int (1 se a data for válida, 0 caso contrário)
 */
int valida_artist_type(const char* type);

/**
 * @brief Função para verificar se um id está na hashtable de músicas
 * 
 * Função que verifica se o id de uma música está na hashtable de músicas
 * Se o id estiver presente, a lista é válida
 * Função auxiliar da função valida_listas_music_ids
 * 
 * @param id (Id a ser procurado)
 * @param gestor (Gestor principal)
 * 
 * @return int (1 se o id estiver na hashtable, 0 caso contrário)
 */
int esta_na_HT_ids_M (char* id, Gestor *gestor);

/**
 * @brief Função para validar listas de ids de músicas
 * 
 * Função que recebe uma lista de ids de músicas e verifica se todos os ids estão presentes na hashtable de músicas
 * Se todos os ids estiverem presentes, a lista é válida
 * 
 * @param lista (Lista de ids de músicas)
 * @param n_listas (Número de ids na lista)
 * @param gestor (Gestor principal)
 * 
 * @return int (1 se a lista for válida, 0 caso contrário)
 */
int valida_listas_music_ids(char** lista, int n_listas, Gestor *gestor);

/**
 * @brief Função para verificar se um id está na hashtable de artistas
 * 
 * Função que verifica se o id de um artista está na hashtable de artistas
 * Se o id estiver presente, a lista é válida
 * Função auxiliar da função valida_listas_artist_ids
 * 
 * @param id (Id a ser procurado)
 * @param gestor (Gestor principal)
 * 
 * @return int (1 se o id estiver na hashtable, 0 caso contrário)
 */
int esta_na_HT_ids_A (char* id, Gestor *gestor);

/**
 * @brief Função para validar listas de ids de artistas
 * 
 * Função que recebe uma lista de ids de artistas e verifica se todos os ids estão presentes na hashtable de artistas
 * Se todos os ids estiverem presentes, a lista é válida
 * 
 * @param lista (Lista de ids de artistas)
 * @param n_listas (Número de ids na lista)
 * @param gestor (Gestor principal)
 * 
 * @return int (1 se a lista for válida, 0 caso contrário)
 */
int valida_listas_artist_ids(char** lista, int n_listas, Gestor *gestor);

/**
 * @brief Função que verifica se a plataforma é do tipo mobile
 * 
 * Função para verificar se o campo plataforma de um histórico é do tipo mobile
 * Se o campo for do tipo mobile, a plataforma é válida
 * Função auxiliar da função valida_plataform
 * 
 * @param type (Campo plataforma no formato de string)
 * 
 * @return int (1 se o campo for válido, 0 caso contrário)
 */
int verifica_type_mobile(const char* type);

/** 
 * @brief Função para verificar se a plataforma é do tipo desktop
 * 
 * Função para verificar se o campo plataforma de um histórico é do tipo desktop
 * Se o campo for do tipo desktop, a plataforma é válida
 * Função auxiliar da função valida_plataform
 * 
 * @param type (Campo plataforma no formato de string)
 * 
 * @return int (1 se o campo for válido, 0 caso contrário)
 */
int verifica_type_desktop(const char* type);

/**
 * @brief Função para validar uma plataforma
 * 
 * Função que verifica se a plataforma é válida
 * Se a plataforma é do tipo mobile ou desktop, a plataforma é válida
 * 
 * @param type (Plataforma a ser validada)
 * 
 * @return int (1 se a plataforma for válida, 0 caso contrário)
 */
int valida_plataform(const char* type);

/**
 * @brief Função para validar um id de um album
 * 
 * Função que verfique se um id de um album existe na hashtable de albums
 * Se o id existir, o id é válido
 * 
 * @param id (Id do album a ser validado)
 * 
 * @return int (1 se o id for válido, 0 caso contrário)
 */
int valida_album_id(Gestor* g, char* id);

/**
 * @brief Função para validar um utilizador
 * 
 * Função que recebe um utilizador e valida vários dos seus campos
 * Se todos os campos forem válidos, o utilizador é válido
 * 
 * @param u (Utilizador a ser validado)
 * @param gestor (Gestor principal)
 * 
 * @return int (1 se o utilizador for válido, 0 caso contrário)
 */
int valida_user (User *u, Gestor *gestor);

/**
 * @brief Função para validar uma música
 * 
 * Função que recebe uma música e valida vários dos seus campos
 * Se todos os campos forem válidos, a música é válida
 * 
 * @param m (Música a ser validada)
 * @param gestor (Gestor principal)
 * 
 * @return int (1 se a música for válida, 0 caso contrário)
 */
int valida_music (Music *m,Gestor* gestor);

/**
 * @brief Função para validar um artista
 * 
 * Função que recebe um artista e valida certos campos do artista
 * Se esses campos forem válidos, o artista é válido
 * 
 * @param a (Artista a ser validado)
 * 
 * @return int (1 se o artista for válido, 0 caso contrário)
 */
int valida_artist (Artist *a);

/**
 * @brief Função para validar um histórico
 * 
 * Função que recebe um histórico e o valida
 * 
 * @param platform (Plataforma do histórico a ser validada)
 * 
 * @return int (1 se o histórico for válido, 0 caso contrário)
 */
int valida_history (char *platform);

/**
 * @brief Função para comparar os outputs obtidos com os outputs esperados
 * 
 * Função que recebe os caminhos dos ficheiros de output obtido e esperado e compara-os
 * Recebe também um apontador para uma flag(int) onde se registra a
 * primeira linha onde os outputs são diferentes
 * Função auxiliar da função compare_outputs_teste
 * 
 * @param output_file (Caminho do ficheiro de output obtido)
 * @param expected_output_file (Caminho do ficheiro de output esperado)
 * @param flag (Flag para indicar se os outputs são iguais)
 * 
 * @return int (1 se os outputs forem iguais, 0 caso contrário)
 */
int compare_outputs(char* output_file, char* expected_output_file, int* flag);

/**
 * @brief Função para comparar os outputs obtidos com os outputs esperados
 * 
 * Função que recebe o caminho da pasta onde estão os ficheiros com o output esperado ,e o número 
 * ficheiros a comparar, e compara-os com os ficheiros de output obtidos 
 * usando a função compare_outputs
 * 
 * @param path_folder (Caminho da pasta onde estão os ficheiros de output)
 * @param cont (Número de ficheiros de output)
 */
void compare_outputs_teste (char* path_folder, int cont);

/**
 * @brief Converte a duração de uma música num inteiro
 * 
 * Função que converte a string da duração de uma música com o formato hh:mm:ss num inteiro, 
 * neste caso para segundos
 * 
 * @param duration (Duração da música)
 * @return int (Duração da música em segundos)
 */
int duration_seg (char* duration);

#endif