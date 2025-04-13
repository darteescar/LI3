#include "Queries/querie_5.h"


//----------------------------------------------------------------------------------
//                                 QUERIE 5
//----------------------------------------------------------------------------------

void free_matriz_array(int **matriz, char **array, int tamanho) {
    // Libera cada linha da matriz
    for (int i = 0; i < tamanho; i++) {
        free(matriz[i]);
    }
    free(matriz);

    for (int i = 0; i < tamanho; i++) {
        free(array[i]);
    }
    free(array);
}

void faz_matriz_array_aux (Gestor *gestor, int ***matriz, char ***array, int *tamanho_atual) {
    GHashTable *ht_u = get_GP_HT_U(gestor); // encapsulamento
    GHashTableIter iter;
    gpointer key, value;
    int linha = 0;

    g_hash_table_iter_init(&iter, ht_u);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        char *username = (char *) key;
        faz_matriz_e_array2(gestor, matriz, array, &linha, tamanho_atual, username);
    }
}

void faz_matriz_e_array2(Gestor* gestor, int*** matriz, char*** array, int* linha, int* tamanho_atual, char* username) {

    // Redimensionamento dinâmico, se necessário
    if (*linha >= *tamanho_atual) {
        *tamanho_atual += 1; // Expande em blocos de 1
        *matriz = realloc(*matriz, *tamanho_atual * sizeof(int*));
        *array = realloc(*array, *tamanho_atual * sizeof(char*));

        if (!(*matriz) || !(*array)) {
            perror("Erro ao realocar matriz ou array");
            exit(EXIT_FAILURE);
        }
    }

    // Alocação para a linha atual
    (*matriz)[*linha] = calloc(10, sizeof(int));
    if (!(*matriz)[*linha]) {
        perror("Erro ao alocar memória para matriz[*linha]");
        exit(EXIT_FAILURE);
    }

    (*array)[*linha] = malloc(20 * sizeof(char));
    if (!(*array)[*linha]) {
        perror("Erro ao alocar memória para array[*linha]");
        exit(EXIT_FAILURE);
    }
    strcpy((*array)[*linha], username);

    // Preenchimento dos dados
    GHashTable *lus = encapsula_LUS_GP(gestor, username); //era melhor se tivesse callback
    
    if (lus == NULL) {
        (*linha)++;
        return; // Linha permanece inicializada com zeros
    }


    GHashTableIter iter;
    gpointer key, value;
    g_hash_table_iter_init(&iter, lus);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        History *lus = (History *) value;
        char *music_id = get_music_id_history(lus);
        Music *m = search_GP_M(gestor, music_id);
        char *genre = get_music_genre(m);
        free(music_id);

        if (strcmp(genre, "Electronic") == 0) {
            (*matriz)[*linha][0]++;
        } else if (strcmp(genre, "Reggae") == 0) {
            (*matriz)[*linha][1]++;
        } else if (strcmp(genre, "Metal") == 0) {
            (*matriz)[*linha][2]++;
        } else if (strcmp(genre, "Hip Hop") == 0) {
            (*matriz)[*linha][3]++;
        } else if (strcmp(genre, "Country") == 0) {
            (*matriz)[*linha][4]++;
        } else if (strcmp(genre, "Blues") == 0) {
            (*matriz)[*linha][5]++;
        } else if (strcmp(genre, "Classical") == 0) {
            (*matriz)[*linha][6]++;
        } else if (strcmp(genre, "Rock") == 0) {
            (*matriz)[*linha][7]++;
        } else if (strcmp(genre, "Jazz") == 0) {
            (*matriz)[*linha][8]++;
        } else if (strcmp(genre, "Pop") == 0) {
            (*matriz)[*linha][9]++;
        }
        free(genre);
        free_music(m);
    }
    g_hash_table_destroy(lus);
    (*linha)++;
}

void fifth_querie(char *line, int cont, Gestor *gestor, int ***matriz, char ***array, int *tamanho_atual) {
    // Determinar flag
    int flag = (line[1] == 'S') ? 1 : 0;

    if (flag == 0) {
        line += 2;
    } else {
        line += 3;
    }

    // Separar componentes da linha
    char* id = strsep(&line, " ");
    int n = atoi(strsep(&line, "\0"));

    User *u = search_GP_HT_U(gestor, id);

    if (!u || n == 0) {
        char *filename = malloc(200);
        sprintf(filename, "resultados/command%d_output.txt", cont);
        FILE *output_file = fopen(filename, "w");
        if (!output_file) {
            perror("Erro ao abrir arquivo de saída");
            return;
        }
        fprintf(output_file,"\n");
        free(filename);
        fclose(output_file);
        if (n==0 && u){free_user(u);}
        return;
    }

    // Array de gêneros
    char *generos[] = {
        "Electronic", "Reggae", "Metal", "Hip Hop", "Country",
        "Blues", "Classical", "Rock", "Jazz", "Pop"
    };

    // Recomendações de utilizadores (adaptar conforme necessário)
    char **users_recomendados = recomendaUtilizadores(id, *matriz, *array, generos, *tamanho_atual, 10, n);

    // Salvar resultados
    char *filename = malloc(200);
    sprintf(filename, "resultados/command%d_output.txt", cont);
    FILE *output_file = fopen(filename, "w");
    if (!output_file) {
        perror("Erro ao abrir arquivo de saída");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(output_file, "%s\n", users_recomendados[i]);
    }
    free(users_recomendados);
    free(filename);
    fclose(output_file);
    free_user(u);
}
