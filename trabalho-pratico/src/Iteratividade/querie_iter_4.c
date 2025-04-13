#include "Iteratividade/querie_iter_4.h"

//----------------------------------------------------------------------------------
//                                 QUERIE 4
//----------------------------------------------------------------------------------

void fourth_querie_iter(char *data_de_inicio, char *data_de_fim, Gestor *gestor) {
    
    // Inicializar a tabela que vai conter os artistas top semanalmente    
    GHashTable *top_semanal = init_TOP_SEMANAL_INTERVALADO(gestor);

    char *semana_de_inicio = calc_semana(data_de_inicio);
    char *semana_de_fim = calc_semana(data_de_fim);

    int *flag_se_for_adicionado_algo = malloc(sizeof(int)); // funciona como flag e como size do all top 10s
    *flag_se_for_adicionado_algo = 0;

    char **all_top_10s = encapsula_AT10_GP(gestor, semana_de_inicio, semana_de_fim, flag_se_for_adicionado_algo);

    if (flag_se_for_adicionado_algo == 0) { // se nao foi encontrada atividade para as semanas pedidas
        printf("Nehuma atividade!\n");
        free(semana_de_inicio);
        free(semana_de_fim);
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
        char *artist_id = get_TOP_SEMANAL_artist_id(top);
        int vezes = get_TOP_SEMANAL_vezes(top);
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

    Artist *artist = search_GP_HT_A(gestor, artist_id_max); // encapsulamento 
    char *type = get_artist_type(artist);
    printf("Artista que esteve mais vezes no top 10 semanal: \n");
    printf("---> id: %s\n", artist_id_max);
    printf("---> Tipo: %s\n", type);
    printf("---> Número de vezes no Top: %d\n", max);
    printf("\n");  

    free(type);
    free(semana_de_inicio);
    free(semana_de_fim);
    free(flag_se_for_adicionado_algo);
    free_artist(artist);
    free_TOP_SEMANAL_INTERVALADO(top_semanal);

}
