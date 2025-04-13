#include "Users_Manager/HT_User.h"

/*------------------------------------------Estrutura---------------------------------------------*/

// Hash Table dos utilizadores

/*-------------------------------------Funções da HT de Users-------------------------------------*/

// Inicialização da HT dos utilizadores
GHashTable *init_HT_U() {
    return g_hash_table_new_full(g_str_hash, g_str_equal, free_HT_U_key, free_HT_U_value); // cuidado aqui
}

// Libertar a Memória TODA da HT dos utilizadores
void free_HT_U(GHashTable *table) {
    g_hash_table_destroy(table);
}

// Liberta a memória de um username (de tipo void * para ser usada na hash table)
void free_HT_U_key(void *username) {
    free((char *)username);
}

// Liberta a memória de um User (de tipo void * para ser usada na hash table)
void free_HT_U_value(void *User) {
    free_user(User); // cuidado aqui
}

// Adicionar um utilizador à HT
void add_HT_U(GHashTable *table, User *u) {
    g_hash_table_insert(table, get_username(u), u);
}

// Obter um utilizador da HT pelo username (retorna NULL se não existir)
User *search_HT_U(GHashTable *table, char *username) {
    if (g_hash_table_contains(table, username)) {
        return copy_user((User *)g_hash_table_lookup(table, username));
    }
    else return NULL;
}

// Print da hash table dos utilizadores TODA
void print_HT_U(GHashTable *table) { 
    GHashTableIter iter;
    gpointer key, value;
    g_hash_table_iter_init(&iter, table);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        print_user((User *)value); // Imprime o user
    }
}