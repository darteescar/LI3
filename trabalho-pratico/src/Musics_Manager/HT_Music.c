#include "Musics_Manager/HT_Music.h"

/*------------------------------------------Estrutura---------------------------------------------*/

// Hash table de Músicas

/*-------------------------------------Funções da HT de músicas-------------------------------------*/

// Inicializa a hash table
GHashTable *init_HT_M() {
    g_hash_table_new_full(g_str_hash, g_str_equal, g_free, free_HT_M_value);
}

// Liberta a memória de uma Música (de tipo void * para ser usada na hash table)
void free_HT_M_value (void *Music) {
    free_music(Music);
}

// Adiciona uma música à hash table
void add_HT_M (Music *m, GHashTable *ht) {
    g_hash_table_insert(ht, get_music_id(m), m);
}

// Liberta a memória alocada para a hash table
void free_HT_M(GHashTable *ht) {
    g_hash_table_destroy(ht);
}

// Retorna a música procurando pelo id
Music *search_HT_M(GHashTable *ht, char *id) {
    if (g_hash_table_contains(ht, id)) {
        return copy_music((Music *)g_hash_table_lookup(ht, id));
    }
    else return NULL;
}

// Imprime os ids das músicas
void print_HT_M(GHashTable *ht) {
    GHashTableIter iter;
    gpointer key, value;
    g_hash_table_iter_init(&iter, ht);
    int i = 0;
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        printf("%s\n", (char *) key);
        i++;
    }
    printf("Total: %d\n", i);
}

void iterate_HT_M(GHashTable *ht, void (*callback)(Music *m, void *user_data), void *user_data) {
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init(&iter, ht);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        Music *m = (Music *)value;
        callback(m, user_data); // Chama o callback com a música e os dados adicionais
    }
}

int search_HT_get_music_n_artists (GHashTable *ht, char *music_id) {
    return get_music_n_artists(g_hash_table_lookup(ht, music_id));
}

char **search_HT_get_music_artist_id (GHashTable *ht, char *music_id) {
    return get_music_artist_id(g_hash_table_lookup(ht, music_id));
}