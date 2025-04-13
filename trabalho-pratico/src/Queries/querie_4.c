#include "Queries/querie_4.h"

struct top_semanal {
    char *artist_id;
    int vezes;
};

GHashTable *init_TOP_SEMANAL_INTERVALADO(Gestor *gestor) {
    return g_hash_table_new_full(g_str_hash, g_str_equal, g_free, free);
}

int get_TOP_SEMANAL_vezes(TOP_SEMANAL *top) {
    return top->vezes;
}

char *get_TOP_SEMANAL_artist_id(TOP_SEMANAL *top) {
    return strdup(top->artist_id);
}

void free_TOP_SEMANAL_INTERVALADO(GHashTable *tabela) {
    g_hash_table_destroy(tabela);
}

void add_TOP_SEMANAL_INTERVALADO(GHashTable *tabela, char *artist_id) {
    TOP_SEMANAL *top = g_hash_table_lookup(tabela, artist_id);
    if (top == NULL) {
        top = malloc(sizeof(TOP_SEMANAL));
        top->artist_id = strdup(artist_id);
        top->vezes = 1;
        g_hash_table_insert(tabela, top->artist_id, top);
    } else {
        top->vezes++;
    }
}

int calcula_n_semanas(char *semana_de_inicio, char *semana_de_fim) {
    int semana_inicio = 0, semana_fim = 0;
    int ano_inicio = 0, ano_fim = 0;
    sscanf(semana_de_inicio, "%d/%d", &semana_inicio, &ano_inicio);
    sscanf(semana_de_fim, "%d/%d", &semana_fim, &ano_fim);

    int n_semanas = 0;
    if (ano_inicio == ano_fim) {
        n_semanas = semana_fim - semana_inicio + 1;
    } else {
        int n_anos = ano_fim - ano_inicio;
        n_semanas = 52 - semana_inicio + 1 + semana_fim + 52 * (n_anos-1); // mais 2 porque a semana de inicio e a semana de fim contam
    }// acho que tenho de ver se o ano é bissexto ou não
    return n_semanas;
}

//---- ------------------------------------------------------------------------------
//                                 QUERIE 4
//--------------------------------------------------------------------------------

void fourth_querie (char *line, int cont, Gestor *gestor) {
    int flag = 0;
    char *data_de_inicio = malloc(sizeof(char) * 11);
    char *data_de_fim = malloc(sizeof(char) * 11);
    
    if (line[1] == 'S') {
        flag = 1;
        if (line[3] == '\0') {
            strncpy(data_de_inicio, "2018/06/01", 11);
            strncpy(data_de_fim, "2024/08/31", 11); // eu sei que nao é a melhor maneira de ter a data mais velha possivel pois apenas tive de consultar
        } else {
            sscanf(line + 3, "%10s %10s", data_de_inicio, data_de_fim);
        }
    } else {
        if (line[2] == '\0') {
            strncpy(data_de_inicio, "2018/06/01", 11);
            strncpy(data_de_fim, "2024/08/31", 11);
        } else {
            sscanf(line + 2, "%10s %10s", data_de_inicio, data_de_fim);
        }
    }

    // Inicializar a tabela que vai conter os artistas top semanalmente    
    GHashTable *top_semanal = init_TOP_SEMANAL_INTERVALADO(gestor);

    char *semana_de_inicio = calc_semana(data_de_inicio);
    char *semana_de_fim = calc_semana(data_de_fim);
    
    int *flag_se_for_adicionado_algo = malloc(sizeof(int)); // funciona como flag e como size do all top 10s
    *flag_se_for_adicionado_algo = 0;

    char **all_top_10s = encapsula_AT10_GP(gestor, semana_de_inicio, semana_de_fim, flag_se_for_adicionado_algo);

    if (*flag_se_for_adicionado_algo == 0) { // se nao foi encontrada atividade para as semanas pedidas
        char *filename = malloc(200);
        sprintf(filename, "resultados/command%d_output.txt", cont);
        FILE *output_file = fopen(filename, "w");
        if (output_file == NULL) {
            perror("Error opening output_file");
            free(data_de_inicio);
            free(data_de_fim);
            free(semana_de_inicio);
            free(semana_de_fim);
            free(filename);
            free(flag_se_for_adicionado_algo);
            free_TOP_SEMANAL_INTERVALADO(top_semanal);
            for (int i = 0; i < *flag_se_for_adicionado_algo; i++) {
                free(all_top_10s[i]);
            }
            free(all_top_10s);
            return;
        }
        fprintf(output_file, "\n");
        free(data_de_inicio);
        free(data_de_fim);
        free(semana_de_inicio);
        free(semana_de_fim);
        free(filename);
        for (int i = 0; i < *flag_se_for_adicionado_algo; i++) {
                free(all_top_10s[i]);
            }
        free(all_top_10s);
        free(flag_se_for_adicionado_algo);
        free_TOP_SEMANAL_INTERVALADO(top_semanal);
        return;
    }

    for ( int i = 0 ; i < *flag_se_for_adicionado_algo ; i ++ ) {
        add_TOP_SEMANAL_INTERVALADO(top_semanal, all_top_10s[i]);
    }

    int max = 0;
    char *artist_id_max = NULL; 

    GHashTableIter iter3;
    gpointer key3, value3;
    g_hash_table_iter_init(&iter3, top_semanal);
    while (g_hash_table_iter_next(&iter3, &key3, &value3)) {
        TOP_SEMANAL *top = (TOP_SEMANAL *)value3;
        char *artist_id = top->artist_id;
        int vezes = top->vezes;
        if (vezes > max) {
            max = vezes;
            artist_id_max = artist_id;
        }
        else if (vezes == max) {
            if (strcmp(artist_id, artist_id_max) < 0) {
                artist_id_max = artist_id;
            }
        }  
    }   
    char *filename = malloc(200);
    sprintf(filename, "resultados/command%d_output.txt", cont);
    FILE *output_file = fopen(filename, "w");
    if (output_file == NULL) {
        perror("Error opening output_file");
        free(data_de_inicio);
        free(data_de_fim);
        free(semana_de_inicio);
        free(semana_de_fim);
        free(filename);
        for (int i = 0; i < *flag_se_for_adicionado_algo; i++) {
                free(all_top_10s[i]);
            }
        free(all_top_10s);
        free(flag_se_for_adicionado_algo);
        free_TOP_SEMANAL_INTERVALADO(top_semanal);
        return;
    }
    Artist *artist = search_GP_HT_A(gestor, artist_id_max); // encapsulamento 
    char *type = get_artist_type(artist);
    if (flag == 0) {
        fprintf(output_file, "%s;%s;%d\n", artist_id_max, type, max);
    } else {
        fprintf(output_file, "%s=%s=%d\n", artist_id_max, type, max);
    }   

    free(type);
    free(filename);
    free(data_de_inicio);
    free(data_de_fim);
    free(semana_de_inicio);
    free(semana_de_fim);
    for (int i = 0; i < *flag_se_for_adicionado_algo; i++) {
        free(all_top_10s[i]);
    }
    free(all_top_10s);
    free(flag_se_for_adicionado_algo);
    free_artist(artist);
    free_TOP_SEMANAL_INTERVALADO(top_semanal);
    fclose(output_file);
}