#include "Musics_Manager/TOP_Music.h"

struct artist_discografia {
    char *id;
    int t_reproducao;
};

GHashTable *init_TOP() {
    return g_hash_table_new_full(g_str_hash, g_str_equal, free, free_ARTIST_COUNTRY_TOP);
}

void free_ARTIST_COUNTRY_TOP(void *table) {
    GHashTable *country_top = (GHashTable *)table;
    g_hash_table_destroy(country_top);
}

GHashTable *init_artists_country() {
    return g_hash_table_new_full(g_str_hash, g_str_equal, free, free_ARTIST_DISCOGRAFIA);
}

void free_ARTIST_DISCOGRAFIA (void *adisc) {
    Artist_Discografia *ad = (Artist_Discografia *) adisc;
    free(ad->id);
    free(ad);
}

void free_TOP (GHashTable *country_top) {
    g_hash_table_destroy(country_top);
}

void add_TOP_M (GHashTable *top, char *artists_id, char *country, int duration) {
    GHashTable *country_top = g_hash_table_lookup(top, country);
    if (country_top == NULL) {
        GHashTable *country_top = init_artists_country();
        g_hash_table_insert(top, strdup(country), country_top);

        Artist_Discografia *artista_top = malloc(sizeof(Artist_Discografia));
        artista_top->id = strdup(artists_id);
        artista_top->t_reproducao = duration;
        g_hash_table_insert(country_top, strdup(artists_id), artista_top);
    }
    else {
        Artist_Discografia *artista_top = g_hash_table_lookup(country_top, artists_id);
        if (artista_top == NULL) {
            artista_top = malloc(sizeof(Artist_Discografia));
            artista_top->id = strdup(artists_id);
            artista_top->t_reproducao = duration;
            g_hash_table_insert(country_top, strdup(artists_id), artista_top);
        } else {
            artista_top->t_reproducao += duration;
        }
    }
}

void print_TOP (GHashTable *top) {
    GHashTableIter iter;
    gpointer key, value;
    g_hash_table_iter_init(&iter, top);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        char *country = (char *) key;
        GHashTable *country_top = (GHashTable *) value;
        printf("Country: %s\n", country);
        GHashTableIter iter2;
        gpointer key2, value2;
        g_hash_table_iter_init(&iter2, country_top);
        while (g_hash_table_iter_next(&iter2, &key2, &value2)) {
            Artist_Discografia *artista_top = (Artist_Discografia *) value2;
            printf("Artist: %s\n", artista_top->id);
            printf("Total Reproductions: %d\n", artista_top->t_reproducao);
        }
    }
}

int get_Artist_Discografia_t_reproducao(Artist_Discografia *ad) {
    return ad->t_reproducao;
}

char *get_Artist_Discografia_id(Artist_Discografia *ad) {
    return strdup(ad->id);
}

//------Encapsulamento  

int country_TOP_exists (GHashTable *top, char *country) {
    return g_hash_table_contains(top, country);
}

void iter_top(GHashTable *top, char *country, char **artists, char **countries, int *discography, int N) {
    GHashTable *country_artists = g_hash_table_lookup(top, country);
    if (country_artists == NULL) return;
    GHashTableIter iter;
    gpointer key, value;
    g_hash_table_iter_init(&iter, country_artists);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        Artist_Discografia *at = (Artist_Discografia*) value;
        int t_reproducao = get_Artist_Discografia_t_reproducao(at);
        char *artist = get_Artist_Discografia_id(at);
        for (int i = 0; i < N; i++) {
            if (discography[i] < t_reproducao) {
                for (int j = N-1; j > i; j--) {
                    discography[j] = discography[j-1];
                    artists[j] = artists[j-1];
                    countries[j] = countries[j-1];
                }
                discography[i] = t_reproducao;
                artists[i] = strdup(artist);
                countries[i] = country;
                break;
            }
        } 
        free(artist);
    }
}

void iter_top_sem_pais(GHashTable *top, char **artists, char **countries, int *discography, int N) {
    GHashTableIter iter;
    gpointer key, value;
    g_hash_table_iter_init(&iter, top);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        if (value != NULL ) {
            GHashTable *tabela_país = (GHashTable *)value;
            GHashTableIter iter2;
            gpointer key2, value2;
            g_hash_table_iter_init(&iter2, tabela_país);
            while (g_hash_table_iter_next(&iter2, &key2, &value2)) {
                if (value2 != NULL) {
                    Artist_Discografia *at = (Artist_Discografia*) value2;
                    int t_reproducao = get_Artist_Discografia_t_reproducao(at);
                    char *artist = get_Artist_Discografia_id(at);
                    for (int i = 0; i < N; i++) {
                        if (discography[i] < t_reproducao) {
                            for (int j = N-1; j > i; j--) {
                                discography[j] = discography[j-1];
                                artists[j] = artists[j-1];
                                countries[j] = countries[j-1];
                            }
                            discography[i] = t_reproducao;
                            artists[i] = strdup(artist);
                            countries[i] = key;
                            break;
                        }  
                    }
                    free(artist);
                }
            }
        }
    }
}