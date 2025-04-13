#include "Users_Manager/users.h"

/*------------------------------------------Estrutura---------------------------------------------*/

// Estrutura do User
struct user {
    char *username;
    char *email;
    char *first_name;
    char *last_name;
    char *birth_date;
    char *country;
    char *subscription_type;
    char **liked_musics_id;
    int n_liked_musics;
};

/*-------------------------------------Funções dos Users----------------------------------*/

// Inicializa um novo utilizador
User *init_user(){
    User *u = malloc(sizeof(struct user));
    u->username = NULL;
    u->email = NULL;
    u->first_name = NULL;
    u->last_name = NULL;
    u->birth_date = NULL;
    u->country = NULL;
    u->subscription_type = NULL;
    u->liked_musics_id = NULL;
    u->n_liked_musics = 0;
    return u;
}

// Getters e Setters

// Username
// Retorna o username do utilizador
char *get_username(User* user) {
    return strdup(user->username);
}
// Define o username do utilizador
void set_username(User* user, char *username) {
    free(user->username);
    user->username = strdup(username);
}

// Email
// Retorna o email do utilizador
char *get_email(User* user) {
    return strdup(user->email);
}
// Define o email do utilizador
void set_email(User* user, char *email) {
    free(user->email);
    user->email = strdup(email);
}

// First Name
// Retorna o primeiro nome do utilizador
char *get_first_name(User* user) {
    return strdup(user->first_name);
}
// Define o primeiro nome do utilizador
void set_first_name(User* user, char *first_name) {
    free(user->first_name);
    user->first_name = strdup(first_name);
}

// Last Name
// Retorna o último nome do utilizador
char *get_last_name(User* user) {
    return strdup(user->last_name);
}
// Define o último nome do utilizador
void set_last_name(User* user, char *last_name) {
    free(user->last_name);
    user->last_name = strdup(last_name);
}

// Birth Date
// Retorna a data de nascimento do utilizador
char *get_birth_date(User* user) {
    return strdup(user->birth_date);
}
// Define a data de nascimento do utilizador
void set_birth_date(User* user, char *birth_date) {
    free(user->birth_date);
    user->birth_date = strdup(birth_date);
}

// Country
// Retorna o país do utilizador
char *get_country(User* user) {
    return strdup(user->country);
}
// Define o país do utilizador
void set_country(User* user, char *country) {
    free(user->country);
    user->country = strdup(country);
}

// Subscription Type
// Retorna o tipo de subscrição do utilizador
char *get_subscription_type(User* user) {
    return strdup(user->subscription_type);
}
// Define o tipo de subscrição do utilizador
void set_subscription_type(User* user, char *subscription_type) {
    free(user->subscription_type);
    user->subscription_type = strdup(subscription_type);
}

// Liked Musics
// Retorna os ids das músicas que o utilizador gostou
char **get_liked_musics_id(User* user) {
    char **liked_musics_id_passada = malloc(user->n_liked_musics * sizeof(char *));
    for (int i = 0; i < user->n_liked_musics; i++) {
        liked_musics_id_passada[i] = strdup(user->liked_musics_id[i]);
    }
    return liked_musics_id_passada;
}
// Define os ids das músicas que o utilizador gostou
void set_liked_musics_id(User* user, char **liked_musics_id) {
    free(user->liked_musics_id);
    user->liked_musics_id = liked_musics_id;
}

// Number of Liked Musics
// Retorna o número de músicas que o utilizador gostou
int get_n_liked_musics(User* user) {
    return user->n_liked_musics;
}
// Define o número de músicas que o utilizador gostou
void set_n_liked_musics(User* user, int n_liked_musics) {
    user->n_liked_musics = n_liked_musics;
}

// Liberta a memória alocada para o utilizador
void free_user(User *user) {
    free(user->username);
    free(user->email);
    free(user->first_name);
    free(user->last_name);
    free(user->birth_date);
    free(user->country);
    free(user->subscription_type);
    for(int i = 0; i < user->n_liked_musics; i++) {
        free(user->liked_musics_id[i]);
    }
    free(user->liked_musics_id);
    free(user);
}

// Printa o utilizador
void print_user (User *user) {
    printf("Username: %s\n", user->username);
    printf("Email: %s\n", user->email);
    printf("First Name: %s\n", user->first_name);
    printf("Last Name: %s\n", user->last_name);
    printf("Birth Date: %s\n", user->birth_date);
    printf("Country: %s\n", user->country);
    printf("Subscription Type: %s\n", user->subscription_type);
    printf("Liked Musics: ");
    for(int i = 0; i < user->n_liked_musics; i++) {
        printf("%s ", user->liked_musics_id[i]);
    }
    printf("\n");
}

User* copy_user (User *u) {
    User *new = init_user();
    char *username = get_username(u);
    set_username(new, username);
    char *email = get_email(u);
    set_email(new, email);
    char *first_name = get_first_name(u);
    set_first_name(new, first_name);
    char *last_name = get_last_name(u);
    set_last_name(new, last_name);
    char *birth_date = get_birth_date(u);
    set_birth_date(new, birth_date);
    char *country = get_country(u);
    set_country(new, country);
    char *subscription_type = get_subscription_type(u);
    set_subscription_type(new, subscription_type);
    int n_liked_musics = get_n_liked_musics(u);
    set_n_liked_musics(new, n_liked_musics);

    char **liked_musics_id = get_liked_musics_id(u);
    char **new_liked_musics_id = malloc(get_n_liked_musics(u) * sizeof(char *));
    for (int i = 0; i < get_n_liked_musics(u); i++) {
        new_liked_musics_id[i] = strdup(liked_musics_id[i]);
    }
    set_liked_musics_id(new, new_liked_musics_id);

    free(username);
    free(email);
    free(first_name);
    free(last_name);
    free(birth_date);
    free(country);
    free(subscription_type);
    for ( int i = 0; i < get_n_liked_musics(u); i++) {
        free(liked_musics_id[i]);
    }
    free(liked_musics_id);
    return new;
}

// Funções Auxiliares

// Retorna a música que o utilizador gostou na posição x (sem strdup desnecessário)
const char *get_x_liked_music(User *user, int x) {
    return user->liked_musics_id[x];
}

// Retorna a lista de músicas que o utilizador gostou
char *get_UA_liked_musics_list(User *user, int x, int n_liked) {
    char *aux = NULL;
    const char *musica = get_x_liked_music(user, x);
    
    if (x == 0) {
        aux = malloc(9);
        if (aux != NULL) {
            strncpy(aux, musica + 3, 8);
            aux[8] = '\0';
        }
    } else if (x == n_liked - 1) {
        aux = malloc(9);
        if (aux != NULL) {
            strncpy(aux, musica, 8);
            aux[8] = '\0';
        }
    } else {
        aux = strdup(musica);
    }
    return aux;
}

int get_age(User* u){
    char* birth_date = get_birth_date(u);
    char year[5], month[3], day[3];
    strncpy(year, birth_date, 4);
    year[4] = '\0';
    strncpy(month, birth_date + 5, 2);
    month[2] = '\0';
    strncpy(day, birth_date + 8, 2);
    day[2] = '\0';

    int year_num = atoi(year);
    int month_num = atoi(month);
    int day_num = atoi(day);

    int age = 2024 - year_num;

    if (month_num > 9 || (month_num == 9 && day_num > 9)){
        age--;
    }
    free(birth_date);
    return age;
}