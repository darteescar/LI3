#include "Iteratividade/querie_iter_2.h"

//----------------------------------------------------------------------------------
//                                 QUERIE 2
//----------------------------------------------------------------------------------

void second_querie_iter(char* country, int N, Gestor* gestor){

    printf("Top %d artistas com maior discografia:\n", N);
    printf("\n");

    if (N==0){
            printf("\n");
            return;
    }

    char *artists[N];
    char *countries[N];
    int discography[N];

    for (int i = 0; i < N; i++) {
        artists[i] = NULL;  // Inicializa o ponteiro com NULL
        countries[i] = NULL;  // Inicializa o ponteiro com NULL
        discography[i] = 0;  // Inicializa o contador com 0
    }

    if (country != NULL) {

        if (country_GP_TOP_exists(gestor, country) == 0) {
            printf("Não existem artistas desse país\n");
            return;
        }

        iter_GP_top(gestor, country, artists, countries, discography, N);

        for ( int i = 0 ; i < N ; i++ ){
            if ( artists[i] != NULL){
                Artist *a = search_GP_HT_A(gestor, artists[i]);
                char *name = get_artist_name(a);
                char *type = get_artist_type(a);
                char *country2 = get_artist_country(a);
                char *duration = duration_format(discography[i]);
                printf("---> Nome: %s\n", name);
                printf("---> Tipo de artista: %s\n", type);
                printf("---> Discografia total: %s\n", duration);
                printf("---> Nacionalidade: %s\n", country2);
                printf("\n");
                free(duration);
                free(name);
                free(type);
                free(country2);
                free_artist(a);
                }
        }
        for ( int i = 0 ; i < N ; i++ ){
            if (artists[i] != NULL) {
                free(artists[i]);
            }
        }
        return;
    } else {

        iter_GP_top_sem_pais(gestor, artists, countries, discography, N);

        for ( int i = 0 ; i < N ; i++ ){
            if (  artists[i] != NULL){
                Artist *a = search_GP_HT_A(gestor, artists[i]);
                char *name = get_artist_name(a);
                char *type = get_artist_type(a);
                char *country2 = get_artist_country(a);
                char *duration = duration_format(discography[i]);
                printf("---> Nome: %s\n", name);
                printf("---> Tipo de artista: %s\n", type);
                printf("---> Discografia total: %s\n", duration);
                printf("---> Nacionalidade: %s\n", country2);
                printf("\n");
                free(duration);
                free(name);
                free(type);
                free(country2);
                free_artist(a);
            }
        }
        for ( int i = 0 ; i < N ; i++ ){
            if (artists[i] != NULL) {
                free(artists[i]);
            }
        }
        return;
    }
}