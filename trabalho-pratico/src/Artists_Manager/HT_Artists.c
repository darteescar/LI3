#include "Artists_Manager/HT_Artists.h"

/*------------------------------------------Estrutura---------------------------------------------*/

// Hash table de Artistas

/*-------------------------------------Funções da HT de artistas-------------------------------------*/

GHashTable *init_HT_A () {
    g_hash_table_new_full(g_str_hash, g_str_equal, g_free, free_HT_A_value );
}

void free_HT_A_value (void *Artist) {
    free_artist(Artist);
}

void add_HT_A (Artist *a, GHashTable *ht) {
    g_hash_table_insert(ht, get_artist_id(a), a);
}

void free_HT_A (GHashTable *ht) {
    g_hash_table_destroy(ht);
}

Artist *search_HT_A (GHashTable *ht, char *id) {
    if (g_hash_table_contains(ht, id)) {
        return copy_artist((Artist *)g_hash_table_lookup(ht, id));
    }
    else return NULL;
}

void print_HT_A (GHashTable *ht) {
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

void increment_HT_A_artist_n_albums(GHashTable *ht, char *artist_id) {
    Artist *a = search_HT_A(ht, artist_id);
    if (a) {
        set_artist_n_albums_individual(a, get_artist_n_albums_individual(a) + 1);
        char *id = get_artist_id(a);
        g_hash_table_insert(ht, id, a);
    }
}

int e_individual(char * type){
    //printf("type: %s\n", type);
    return(type[0] == 'i' || type[0] == 'I'
        && type[1] == 'n' || type[1] == 'N'
        && type[2] == 'd' || type[2] == 'D'
        && type[3] == 'i' || type[3] == 'I'
        && type[4] == 'v' || type[4] == 'V'
        && type[5] == 'i' || type[5] == 'I'
        && type[6] == 'd' || type[6] == 'D'
        && type[7] == 'u' || type[7] == 'U'
        && type[8] == 'a' || type[8] == 'A'
        && type[9] == 'l' || type[9] == 'L');
}

int e_group(char * type){
    //printf("type: %s\n", type);
    return(type[0] == 'g' || type[0] == 'G'
        && type[1] == 'r' || type[1] == 'R'
        && type[2] == 'o' || type[2] == 'O'
        && type[3] == 'u' || type[3] == 'U'
        && type[4] == 'p' || type[4] == 'P');
}

void increment_HT_A_artist_reproductions (GHashTable *am, char **artists_id, int n_artists) {
    if (artists_id) {
        //printf("n_artists: %d\n", n_artists);
        for(int i = 0; i < n_artists; i++) {
            Artist *a = search_HT_A(am,artists_id[i]); // tem de ser copia
            if (a) {
                double reproductions = get_artist_reproductions(a);
                double recipe = get_artist_recipe_per_stream(a);
                
                set_artist_reproductions(a, reproductions + recipe);
                char *id = get_artist_id(a);
                g_hash_table_insert(am, id, a);
            }
            char *type = get_artist_type(a);
            if(e_group(type)){
                char** constituintes = get_artist_id_constituent(a);
                int n_constituintes = get_artist_n_constituent(a);
                for(int j = 0; j < n_constituintes; j++){
                    Artist *a1 = search_HT_A(am,constituintes[j]); // tem de ser copia
                    char *type1 = get_artist_type(a1);
                    if (e_individual(type1)) {
                        double reproductions = get_artist_reproductions(a1);
                        double recipe = get_artist_recipe_per_stream(a);
                        double total = recipe/(double)n_constituintes;
                        set_artist_reproductions(a1, reproductions + total);
                        char *id = get_artist_id(a1);
                        g_hash_table_insert(am, id, a1);
                    }
                    free(type1);
                }
                for ( int i = 0; i < n_constituintes; i++) {
                    free(constituintes[i]);
                }
                free(constituintes);
            }
            free(type);
        }
    }
}