#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Users_Manager/GR_User.h"

struct genre_count {
    char *genre;
    int count;
    struct genre_count *next;
};

GHashTable *init_HT_GR () {
    return g_hash_table_new_full(g_int_hash, g_int_equal, free, (GDestroyNotify) free_HT_GR_value);
}

void free_HT_GR (GHashTable *table) {
    g_hash_table_destroy(table);
}

void free_HT_GR_value(Genre_Count *gc) {
    while (gc != NULL) {
        Genre_Count *aux = gc;
        gc = gc->next;
        free(aux->genre);
        free(aux);
    }
}

int increment_GR (Genre_Count *gc, char *genre) {
    Genre_Count *aux = gc;
    while (aux != NULL) {
        if (strcmp(aux->genre,genre) == 0) {
            aux->count++;
            return 1;
        }
        aux = aux->next;
    }
    return 0;
}

Genre_Count* add_GR_genre (Genre_Count *gc, char *genre) {
    Genre_Count *new = malloc(sizeof(Genre_Count));
    new->genre = strdup(genre);
    new->count = 1;
    new->next = gc;
    return new;
}

void add_HT_GR_User_Songs(GHashTable *table, char *genre, int *idade_ptr) {

    Genre_Count *gc = g_hash_table_lookup(table, idade_ptr);

    if (gc == NULL) {
            gc = malloc(sizeof(Genre_Count));
            gc->genre = strdup(genre);
            gc->count = 1;
            gc->next = NULL;
            g_hash_table_insert(table, idade_ptr, gc);
            idade_ptr = NULL;
    } else {
        if (increment_GR(gc, genre) == 0) {
            Genre_Count *aux = gc;
            while (aux->next != NULL) {
                aux = aux->next;
            }
            Genre_Count *new_node = malloc(sizeof(Genre_Count));
            new_node->genre = strdup(genre);
            new_node->count = 1;
            new_node->next = NULL;
            aux->next = new_node;
        }
    }
    if (idade_ptr != NULL) {
        free(idade_ptr);
    }
}

void print_HT_GR (GHashTable *table) {
    GHashTableIter iter;
    gpointer key, value;
    g_hash_table_iter_init(&iter, table);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        printf("Idade: %d\n", *(int *)key);
        Genre_Count *gc = (Genre_Count *)value;
        while (gc != NULL) {
            printf("Genre: %s Count: %d\n", gc->genre, gc->count);
            gc = gc->next;
        }
    }
}

void ordena_GR_LL (Genre_Count *gr) {
    Genre_Count *aux = gr;
    Genre_Count *aux2 = gr;
    while (aux != NULL) {
        aux2 = aux;
        while (aux2 != NULL) {
            if (aux->count < aux2->count) {
                int count = aux->count;
                char *genre = aux->genre;
                aux->count = aux2->count;
                aux->genre = aux2->genre;
                aux2->count = count;
                aux2->genre = genre;
            }
            if (aux->count == aux2->count) {
                if (strcmp(aux->genre, aux2->genre) > 0) {
                    int count = aux->count;
                    char *genre = aux->genre;
                    aux->count = aux2->count;
                    aux->genre = aux2->genre;
                    aux2->count = count;
                    aux2->genre = genre;
                }
            }
            aux2 = aux2->next;
        }
        aux = aux->next;
    }
}

Genre_Count* get_next_GR (Genre_Count *gr) {
    return gr->next;
}

void update_next_GR (Genre_Count *gr, Genre_Count *next) {
    gr->next = next;
}

void add_count_GR (Genre_Count *gr, int count) {
    gr->count += count;
}

char *get_genre_GR (Genre_Count *gr) {
    return gr->genre;
}

int get_count_GR (Genre_Count *gr) {
    return gr->count;
}

Genre_Count* create_GR (char *genre, int count) {
    Genre_Count *new = malloc(sizeof(Genre_Count));
    new->genre = strdup(genre);
    new->count = count;
    new->next = NULL;
    return new;
}

Genre_Count* encapsula_GC (GHashTable *table, Genre_Count *acumulador_head, int minIdade, int maxIdade) {

    for (int x = minIdade; x <= maxIdade; x++) {
        Genre_Count *current = g_hash_table_lookup(table, &x);
        while (current != NULL) {
            Genre_Count *aux = acumulador_head;
            Genre_Count *prev = NULL;
            while (aux != NULL && strcmp(get_genre_GR(aux), get_genre_GR(current)) != 0) {
                prev = aux;
                aux = get_next_GR(aux);
            }
            if (aux == NULL) {
                Genre_Count *new_node = create_GR(get_genre_GR(current), get_count_GR(current));
                if (prev == NULL) {
                    acumulador_head = new_node;
                } else {
                    update_next_GR(prev, new_node);
                }
            } else {
                add_count_GR(aux, get_count_GR(current));
            }
            current = get_next_GR(current);
        }
    }
    Genre_Count *aux = acumulador_head;
    ordena_GR_LL(aux);
    return acumulador_head;
}