#include "Artists_Manager/HT_ArtTOP.h"
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct artista_top {
    char *id;
    int t_reproducao;
} Artist_Top;

GHashTable *criar_tabela_artista_top() {
    return g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
}

GHashTable *criar_tabela_principal() {
    return g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)g_hash_table_destroy);
}

char* calc_semana(char* date_str) {
    if (!date_str || strlen(date_str) != 10) {
        fprintf(stderr, "Formato de data inválido. Esperado: YYYY/MM/DD\n");
        return NULL;
    }

    int year = atoi(date_str);
    int month = atoi(date_str + 5);
    int day = atoi(date_str + 8);

    struct tm date = {0};
    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;

    if (mktime(&date) == -1) {
        fprintf(stderr, "Erro ao calcular a data. Verifique se a data é válida.\n");
        return NULL;
    }

    // Determinar o dia da semana do 1º de janeiro
    struct tm first_day = {0};
    first_day.tm_mday = 1;
    first_day.tm_mon = 0;
    first_day.tm_year = year - 1900;

    if (mktime(&first_day) == -1) {
        fprintf(stderr, "Erro ao calcular o primeiro dia do ano.\n");
        return NULL;
    }

    int first_day_of_week = first_day.tm_wday; // 0 = domingo, ..., 6 = sábado
    int day_of_year = date.tm_yday + 1;

    // Calcular a semana do ano
    int week_number;
    if (first_day_of_week == 0) {
        // Ano começa num domingo
        week_number = (day_of_year + 6) / 7;
    } else {
        // Ano começa noutro dia
        int offset = 7 - first_day_of_week; // Dias restantes até o próximo domingo
        if (day_of_year <= offset) {
            week_number = 1; // Está na primeira semana incompleta
        } else {
            week_number = (day_of_year - offset + 6) / 7 + 1;
        }
    }

    // Alocar memória para o resultado "00/0000"
    char* result = malloc(16 * sizeof(char)); // 8 caracteres + terminador
    if (!result) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return NULL;
    }

    snprintf(result, 16, "%02d/%04d", week_number, year);
    return result;
}

void add_HT_week_ArtTOP (GHashTable *tabela_principal, char **artist_id, int n_artists, char *data, int duration){
    char *semana = calc_semana(data);
    GHashTable *tabela_semana = g_hash_table_lookup(tabela_principal, semana);
    if (tabela_semana == NULL) {
        tabela_semana = criar_tabela_artista_top();
        g_hash_table_insert(tabela_principal, strdup(semana), tabela_semana);
        for ( int i = 0; i < n_artists ; i++ ) {
            Artist_Top *artista_top = malloc(sizeof(Artist_Top));
            artista_top->id = g_strdup(artist_id[i]);
            artista_top->t_reproducao = duration;
            g_hash_table_insert(tabela_semana, artista_top->id, artista_top);
        }
    }
    else {
        for ( int i = 0; i < n_artists ; i++ ) {
            Artist_Top *artista_top = g_hash_table_lookup(tabela_semana, artist_id[i]);
            if (artista_top == NULL) {
                artista_top = malloc(sizeof(Artist_Top));
                artista_top->id = g_strdup(artist_id[i]);
                artista_top->t_reproducao = duration;
                g_hash_table_insert(tabela_semana, artista_top->id, artista_top);
            } else {
                artista_top->t_reproducao += duration;
            }
        }
    }
    free(semana);
}

void liberar_artista_top(gpointer dados) {
    Artist_Top *artista_top = (Artist_Top *)dados;
    free(artista_top->id);
    free(artista_top);
}

void liberar_tabela_principal(GHashTable *tabela_principal) {
    g_hash_table_destroy(tabela_principal);
}

void print_HT_week_ArtTOP (GHashTable *tabela_principal) {
    GHashTableIter iter;
    gpointer key, value;
    g_hash_table_iter_init(&iter, tabela_principal);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        printf("Semana: %s\n", (char *)key);
        GHashTable *tabela_semana = (GHashTable *)value;
        GHashTableIter iter_semana;
        gpointer key_semana, value_semana;
        g_hash_table_iter_init(&iter_semana, tabela_semana);
        while (g_hash_table_iter_next(&iter_semana, &key_semana, &value_semana)) {
            Artist_Top *artista_top = (Artist_Top *)value_semana;
            printf("Artista: %s\n", artista_top->id);
            printf("Tempo de reprodução: %d\n", artista_top->t_reproducao);
        }
    }
}

char *get_artist_top_id (Artist_Top *artista_top) {
    return strdup(artista_top->id);
}

int get_artista_top_t_reproducao (Artist_Top *artista_top) {
    return artista_top->t_reproducao;
}

// ----------------------------- ALL_TOP_10s -----------------------------
//estrututa para guardar os artistas top 10 de cada semana

struct topentry {
    char *artist_id;
    int t_reproducao;
};

struct minheap {
    TopEntry *entries;
    int size;
    int capacity;
};

MinHeap* init_min_heap(int capacity) {
    MinHeap *heap = malloc(sizeof(MinHeap));
    heap->entries = malloc(sizeof(TopEntry) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(TopEntry *a, TopEntry *b) {
    TopEntry temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_down(MinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->entries[left].t_reproducao < heap->entries[smallest].t_reproducao)
        smallest = left;
    if (right < heap->size && heap->entries[right].t_reproducao < heap->entries[smallest].t_reproducao)
        smallest = right;

    if (smallest != index) {
        swap(&heap->entries[index], &heap->entries[smallest]);
        heapify_down(heap, smallest);
    }
}

void heapify_up(MinHeap *heap, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap->entries[index].t_reproducao < heap->entries[parent].t_reproducao) {
        swap(&heap->entries[index], &heap->entries[parent]);
        heapify_up(heap, parent);
    }
}

void insert_min_heap(MinHeap *heap, char *artist_id, int t_reproducao) {
    if (heap->size < heap->capacity) {
        heap->entries[heap->size].artist_id = strdup(artist_id);
        heap->entries[heap->size].t_reproducao = t_reproducao;
        heap->size++;
        heapify_up(heap, heap->size - 1);
    } else if (t_reproducao > heap->entries[0].t_reproducao) {
        // Substituir o menor elemento
        free(heap->entries[0].artist_id);
        heap->entries[0].artist_id = strdup(artist_id);
        heap->entries[0].t_reproducao = t_reproducao;
        heapify_down(heap, 0);
    }
}

void free_min_heap(MinHeap *heap) {
    for (int i = 0; i < heap->size; i++) {
        free(heap->entries[i].artist_id);
    }
    free(heap->entries);
    free(heap);
}

GHashTable *init_ALL_TOP_10s () {
    return g_hash_table_new_full(g_str_hash, g_str_equal, g_free, free_top_10s);
}

void free_ALL_TOP_10s (GHashTable *ALL_TOP_10s) {
    g_hash_table_destroy(ALL_TOP_10s);
}

void add_top_10 (GHashTable *ALL_TOP_10s, char *semana, MinHeap *heap) {
    MinHeap *heap_copy = init_min_heap(heap->capacity);
    for (int i = 0; i < heap->size; i++) {
        insert_min_heap(heap_copy, heap->entries[i].artist_id, heap->entries[i].t_reproducao);
    }
    g_hash_table_insert(ALL_TOP_10s, strdup(semana), heap_copy);
    free_min_heap(heap);
}

void free_top_10s(void *dados) {
    free_min_heap((MinHeap *)dados);
}

void *preenche_ALL_TOP_10s (GHashTable *tabela_principal, GHashTable *ALL_TOP_10s) {
    GHashTableIter iter;
    gpointer key, value;
    g_hash_table_iter_init(&iter, tabela_principal);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        MinHeap *heap = init_min_heap(10);
        GHashTable *tabela_semana = (GHashTable *)value;
        GHashTableIter iter_semana;
        gpointer key_semana, value_semana;
        g_hash_table_iter_init(&iter_semana, tabela_semana);
        while (g_hash_table_iter_next(&iter_semana, &key_semana, &value_semana)) {
            Artist_Top *artista_top = (Artist_Top *)value_semana;
            char *artist_id = get_artist_top_id(artista_top);
            int t_reproducao = get_artista_top_t_reproducao(artista_top);
            insert_min_heap(heap, artist_id, t_reproducao);
            free(artist_id);
        }
        add_top_10(ALL_TOP_10s, (char *)key, heap);
    }
}

int get_MinHeap_size(MinHeap *heap) {
    return heap->size;
}

char *get_MinHeap_artist_id (MinHeap *heap, int index) {
    return strdup(heap->entries[index].artist_id);
}

int semana_pertence_ao_intervalo_de_semanas_pedido(char *semana, char *semana_de_inicio, char *semana_de_fim) {
    int semana_inicio, semana_fim;
    int ano_inicio, ano_fim;
    int semana_atual, ano_atual;

    if (sscanf(semana_de_inicio, "%d/%d", &semana_inicio, &ano_inicio) != 2 ||
        sscanf(semana_de_fim, "%d/%d", &semana_fim, &ano_fim) != 2 ||
        sscanf(semana, "%d/%d", &semana_atual, &ano_atual) != 2) {
        // Parsing falhou
        return 0;
    }

    // Verificar intervalos
    if (ano_atual < ano_inicio || ano_atual > ano_fim) {
        return 0; // Ano fora do intervalo
    }

    if (ano_atual == ano_inicio && semana_atual < semana_inicio) {
        return 0; // Semana antes do início
    }

    if (ano_atual == ano_fim && semana_atual > semana_fim) {
        return 0; // Semana depois do fim
    }

    return 1; // Dentro do intervalo
}

char **encapsula_AT10(GHashTable *all_top_10_s, char *semana_de_inicio, char *semana_de_fim, int *flag_se_foi_adicionado_algo) {
    char **output = malloc(10 * sizeof(char *));
    if (output == NULL) {
        perror("Erro ao alocar memória para output");
        return NULL;
    }
    for (int i = 0; i < 10; i++) {
        output[i] = NULL;
    }
    int capacity = 10;

    GHashTableIter iter;
    gpointer key, value;
    g_hash_table_iter_init(&iter, all_top_10_s);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        char *semana_atual = (char *)key;
        if (semana_pertence_ao_intervalo_de_semanas_pedido(semana_atual, semana_de_inicio, semana_de_fim)) {
            MinHeap *top_10_artistas_dessa_semana = (MinHeap *)value;
            if (top_10_artistas_dessa_semana != NULL) {
                for (int i = 0; i < top_10_artistas_dessa_semana->size; i++) {
                    if (*flag_se_foi_adicionado_algo >= capacity) {
                        capacity *= 2;
                        char **temp = realloc(output, capacity * sizeof(char *));
                        if (temp == NULL) {
                            perror("Erro ao realocar memória para output");
                            return NULL;
                        }
                        output = temp;
                    }

                    char *artist_id = get_MinHeap_artist_id(top_10_artistas_dessa_semana, i);
                    output[*flag_se_foi_adicionado_algo] = strdup(artist_id);
                    if (output[*flag_se_foi_adicionado_algo] == NULL) {
                        perror("Erro ao alocar memória para artist_id");
                        return NULL;
                    }
                    free(artist_id);
                    (*flag_se_foi_adicionado_algo)++;
                }
            }
        }
    }

    return output;
}
