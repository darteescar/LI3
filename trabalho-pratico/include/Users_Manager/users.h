/**
 * @file users.h
 * @author Grupo 25 de LI3
 * @brief Header file do módulo da estrutura User
 */
#ifndef USERS_H
#define USERS_H

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do User
typedef struct user User;

/**
 * @brief Inicializa um utilizador
 * 
 * Função que aloca memória para um utilizador e inicializa os seus campos
 * 
 * @return User* 
 */
User *init_user();

// Getters e Setters

//--------------------Username-----------------------------
/**
 * @brief Retorna o username do utilizador
 * 
 * Função que retorna a cópia do username de um determinado utilizador
 * 
 * @param user Utilizador
 * @return char* (Cópia do username) 
 */
char *get_username(User* user); 

/**
 * @brief Define o username do utilizador
 * 
 * Função que liberta a memória alocada para o username antigo 
 * e define o novo username passado como argumento
 * 
 * @param user Utilizador
 * @param username Novo username
 */
void set_username(User* user, char *username);

//--------------------Email-------------------
/**
 * @brief Retorna o email do utilizador
 * 
 * Função que retorna a cópia do email de um determinado utilizador
 * 
 * @param user Utilizador
 * @return char* (Cópia do email) 
 */
char *get_email(User* user);

/**
 * @brief Define o email do utilizador
 * 
 * Função que liberta a memória alocada para o email antigo 
 * e define o novo email passado como argumento
 * 
 * @param user Utilizador
 * @param email Novo email
 */
void set_email(User* user, char *email);

//-----------------------First Name----------------------------
/**
 * @brief Retorna o primeiro nome do utilizador
 * 
 * Função que retorna a cópia do primeiro nome de um determinado utilizador
 * 
 * @param user Utilizador
 * @return char* (Cópia do primeiro nome) 
 */
char *get_first_name(User* user);

/**
 * @brief Define o primeiro nome do utilizador
 * 
 * Função que liberta a memória alocada para o primeiro nome antigo 
 * e define o novo primeiro nome passado como argumento
 * 
 * @param user Utilizador
 * @param first_name Novo primeiro nome
 */
void set_first_name(User* user, char *first_name);

//---------------------------------Last Name----------------------------
/**
 * @brief Retorna o último nome do utilizador
 * 
 * Função que retorna a cópia do último nome de um determinado utilizador
 * 
 * @param user Utilizador
 * @return char* (Cópia do último nome) 
 */
char *get_last_name(User* user);

/**
 * @brief Define o último nome do utilizador
 * 
 * Função que liberta a memória alocada para o último nome antigo 
 * e define o novo último nome passado como argumento
 * 
 * @param user Utilizador
 * @param last_name Novo último nome
 */
void set_last_name(User* user, char *last_name);

//--------------------------Birth Date----------------------------
/**
 * @brief Retorna a data de nascimento do utilizador
 * 
 * Função que retorna a cópia da data de nascimento de um determinado utilizador
 * 
 * @param user Utilizador
 * @return char* (Cópia da data de nascimento) 
 */
char *get_birth_date(User* user);

/**
 * @brief Define a data de nascimento do utilizador
 * 
 * Função que liberta a memória alocada para a data de nascimento antiga 
 * e define a nova data de nascimento passada como argumento
 * 
 * @param user Utilizador
 * @param birth_date Nova data de nascimento
 */
void set_birth_date(User* user, char *birth_date);

//-----------------------------Country--------------------------------
/**
 * @brief Retorna o país do utilizador
 * 
 * Função que retorna a cópia do país de um determinado utilizador
 * 
 * @param user Utilizador
 * @return char* (Cópia do país) 
 */
char *get_country(User* user);

/**
 * @brief Define o país do utilizador
 * 
 * Função que liberta a memória alocada para o país antigo 
 * e define o novo país passado como argumento
 * 
 * @param user Utilizador
 * @param country Novo país
 */
void set_country(User* user, char *country);

//-----------------------------Subscription Type-------------------------
/**
 * @brief Retorna o tipo de subscrição do utilizador
 * 
 * Função que retorna a cópia do tipo de subscrição de um determinado utilizador
 * Pode ser normal ou premium
 * 
 * @param user Utilizador
 * @return char* (Cópia do tipo de subscrição)
 */
char *get_subscription_type(User* user); 

/**
 * @brief Define o tipo de subscrição do utilizador
 * 
 * Função que liberta a memória alocada para o tipo de subscrição antigo 
 * e define o novo tipo de subscrição passado como argumento
 * 
 * @param user Utilizador
 * @param subscription_type Novo tipo de subscrição
 */
void set_subscription_type(User* user, char *subscription_type); 

//----------------------------Liked Musics----------------------------
/**
 * @brief Retorna os ids das músicas que o utilizador gostou
 * 
 * Função que retorna a lista de ids das músicas que o utilizador gostou
 * 
 * @param user Utilizador
 * @return char** (Lista de ids das músicas que o utilizador gostou)
 */
char **get_liked_musics_id(User* user);

/**
 * @brief Define os ids das músicas que o utilizador gostou
 * 
 * Função que liberta a memória alocada para os ids das músicas que o utilizador gostou
 * e define a nova lista de ids passada como argumento
 * 
 * @param user Utilizador
 * @param liked_musics_id Nova lista de ids das músicas que o utilizador gostou
 */
void set_liked_musics_id(User* user, char **liked_musics_id);

//-------------------------Number of Liked Musics-------------------------
/**
 * @brief Retorna o número de músicas que o utilizador gostou
 * 
 * Função que retorna o número de músicas que o utilizador gostou
 * 
 * @param user Utilizador
 * @return int (Número de músicas que o utilizador gostou)
 */
int get_n_liked_musics(User* user);

/**
 * @brief Define o número de músicas que o utilizador gostou
 * 
 * Função que define o número de músicas que o utilizador gostou
 * 
 * @param user Utilizador
 * @param n_liked_musics Novo número de músicas que o utilizador gostou
 */
void set_n_liked_musics(User* user, int n_liked_musics);

/**
 * @brief Liberta um utilizador
 * 
 * Função que liberta a memória alocada para um utilizador
 * e todos os seus campos
 * 
 * @param user Utilizador
 */
void free_user(User *user);

/**
 * @brief Imprime um utilizador
 * 
 * Função que imprime no terminal todos os campos de um utilizador
 * 
 * @param user Utilizador
 */
void print_user (User *user);

/**
 * @brief Copia um utilizador
 * 
 * Função que copia todos os campos um utilizador
 * 
 * @param u Utilizador
 * @return User* (Cópia do utilizador)
 */
User* copy_user (User *u);

// Funções Auxiliares

/**
 * @brief Retorna a música que o utilizador gostou na posição x
 * 
 * Função que retorna a cópia do id da música que o utilizador gostou na posição x
 * 
 * @param user U
 * @param x Posição da música
 * @return const char* (Cópia do id da música)
 */
const char *get_x_liked_music(User *user, int x);

/**
 * @brief Retorna a musica que o utilizador gostou na posição x da lista de músicas gostadas
 * 
 * Função que retorna a música que o utilizador gostou na posição x da lista de músicas gostadas
 * 
 * @param user Utilizador
 * @param x Posição da música
 * @param n_liked Número de músicas gostadas 
 * @return char* (Cópia do id da música)
 */
char *get_UA_liked_musics_list(User *user, int x, int n_liked);

/**
 * @brief Retorna a idade do utilizador
 * 
 * Função que calcula a idade do utilizador a partir da data de nascimento
 * 
 * @param user Utilizador
 * @return int (Idade do utilizador)
 */
int get_age(User *user);

#endif