#include "Users_Manager/users_manager.h"

/*------------------------------------------Estrutura---------------------------------------------*/

// Estrutura do User_Manager
struct users_Manager {
    GHashTable *users;
    GHashTable *ht_genre_count;
};

/*-------------------------------------Funções do Gestor de Users----------------------------------*/

Users_Manager *init_GU() {
    Users_Manager *um = malloc(sizeof(Users_Manager));
    if (um != NULL) {
        um->users = init_HT_U();
        um->ht_genre_count = init_HT_GR();
    }
    return um;
}

void free_GU(Users_Manager *um) {
    free_HT_U(um->users);
    free(um);
}

void add_GU_HT_U (Users_Manager *um, User *u) {
    add_HT_U(um->users, u);
}

void add_GU_HT_GR_User_Songs (Users_Manager *um, char *genre, int *idade_ptr) {
    add_HT_GR_User_Songs(um->ht_genre_count, genre, idade_ptr);
}

GHashTable *get_GU_HT_U(Users_Manager *um) {
    return um->users;
}

void print_GU(Users_Manager *um) {
    //print_HT_U(um->users);
    //print_HT_GR(um->ht_genre_count);
}

GHashTable *get_GU_HT_GC(Users_Manager *um) {
    return um->ht_genre_count;
}

User* search_GU_HT_U (Users_Manager *um, char *id) {
    return search_HT_U(um->users, id);
}

void free_GU_HT_GC(Users_Manager *um) {
    free_HT_GR(um->ht_genre_count);
}

Genre_Count* encapsula_GC_GU (Users_Manager *um, Genre_Count *acumulador_head, int minIdade, int maxIdade) {
    return encapsula_GC(um->ht_genre_count, acumulador_head, minIdade, maxIdade);
}