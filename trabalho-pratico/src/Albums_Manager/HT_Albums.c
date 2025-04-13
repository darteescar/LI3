#include "Albums_Manager/HT_Albums.h"

/*------------------------------------------Estrutura---------------------------------------------*/

// Hash table de Albums

/*-------------------------------------Funções da HT de albums-------------------------------------*/

GHashTable *init_HT_Al () {
    g_hash_table_new_full(g_str_hash, g_str_equal, free_HT_Al_key, free_HT_Al_value ); // cuidado aqui
}

void free_HT_Al_value (void *album) {
    free_album((Album *)album); // cuidado aqui
}

void add_HT_Al_Al (Album *a, GHashTable *ht) {
    g_hash_table_insert(ht, get_album_id(a), a);
}

void free_HT_Al (GHashTable *ht) {
    g_hash_table_destroy(ht);
}

Album *search_HT_Al (GHashTable *ht, char *id) {
    return (Album *)g_hash_table_lookup(ht, id);
}  

void print_HT_Al (GHashTable *ht) {
    GHashTableIter iter;
    gpointer key, value;
    g_hash_table_iter_init(&iter, ht);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        print_album((Album *)value); // Imprime o album
    }
}

void free_HT_Al_key (void *key) {
    free((char *)key);
}
