#include "Queries/querie_2.h"

//----------------------------------------------------------------------------------
//                                 QUERIE 2
//----------------------------------------------------------------------------------

//funcao que converte a duracao de uma musica de segundos para hh:mm:ss
char* duration_format(int duration){
    int hours = duration / 3600;
    int minutes = (duration % 3600) / 60;
    int seconds = duration % 60;

    char* duration_str = malloc(20);
    sprintf(duration_str, "%02d:%02d:%02d", hours, minutes, seconds);

    return duration_str;
}

void second_querie(char* line, int cont, Gestor* gestor){
    int flag = 0;
    if (line[1]=='S') flag=1;

    if (flag==0){
       line += 2;
    } else {
        line += 3;
    }

    char n[5];
    int indice = 0;
    while (isdigit(*line)) {
        n[indice] = *line;
        indice++;
        line++;
    }
    n[indice] = '\0';
    int N = atoi(n);

    char* country = NULL;
    if (*line == ' ') {
        line+=2;
        line[strlen(line)-2] = '\0';
        country = line;
    }

    if (N==0){
            char* filename = malloc(200);

            sprintf(filename, "resultados/command%d_output.txt", cont);

            FILE *output_file = fopen(filename, "a");

            if(output_file == NULL){
                 perror("Error opening user_file");
                 return;
            }

            fprintf(output_file, "\n");
            fclose(output_file);
            free(filename);
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
            char* filename = malloc(200);
            sprintf(filename, "resultados/command%d_output.txt", cont);
            FILE *output_file = fopen(filename, "a");
            if(output_file == NULL){
                perror("Error opening user_file");
                return;
            }
            fprintf(output_file, "\n");
            fclose(output_file);
            free(filename);
            return;
        }

        iter_GP_top(gestor, country, artists, countries, discography, N);

        char* filename = malloc(200);
        sprintf(filename, "resultados/command%d_output.txt", cont);
        FILE *output_file = fopen(filename, "a");
        if(output_file == NULL){
            perror("Error opening user_file");
            return;
        }
        if (flag == 1) {
            for ( int i = 0 ; i < N ; i++ ){
                if ( artists[i] != NULL){
                    Artist *a = search_GP_HT_A(gestor, artists[i]);
                    char *name = get_artist_name(a);
                    char *type = get_artist_type(a);
                    char *duration = duration_format(discography[i]);
                    fprintf(output_file, "%s=%s=%s=%s\n", name, type, duration, country);
                    free(duration);
                    free(name);
                    free(type);
                    free_artist(a);
                }
            }
        } else {
            for ( int i = 0 ; i < N ; i++ ){
                if ( artists[i] != NULL ){
                    Artist *a = search_GP_HT_A(gestor, artists[i]);
                    char *name = get_artist_name(a);
                    char *type = get_artist_type(a);
                    char *duration = duration_format(discography[i]);
                    fprintf(output_file, "%s;%s;%s;%s\n", name, type, duration,country);
                    free(duration);
                    free(name);
                    free(type);
                    free_artist(a);
                }
            }
        }
        for ( int i = 0 ; i < N ; i++ ){
            if (artists[i] != NULL) {
                free(artists[i]);
            }
        }
        fclose(output_file);
        free(filename);
        return;
    } else {

        iter_GP_top_sem_pais(gestor, artists, countries, discography, N);

        char* filename = malloc(200);
        sprintf(filename, "resultados/command%d_output.txt", cont);
        FILE *output_file = fopen(filename, "a");
        if(output_file == NULL){
            perror("Error opening user_file");
            return;
        }
        if (flag == 1) {
            for ( int i = 0 ; i < N ; i++ ){
                if (  artists[i] != NULL){
                    Artist *a = search_GP_HT_A(gestor, artists[i]);
                    char *name = get_artist_name(a);
                    char *type = get_artist_type(a);
                    char *country = get_artist_country(a);
                    char *duration = duration_format(discography[i]);
                    fprintf(output_file, "%s=%s=%s=%s\n", name, type, duration, country);
                    free(duration);
                    free(name);
                    free(country);
                    free(type);
                    free_artist(a);
                }
            } 
        } else {
            for ( int i = 0 ; i < N ; i++ ){
                if (  artists[i] != NULL){
                    Artist *a = search_GP_HT_A(gestor, artists[i]);
                    char *name = get_artist_name(a);
                    char *type = get_artist_type(a);
                    char *country = get_artist_country(a);
                    char *duration = duration_format(discography[i]);
                    fprintf(output_file, "%s;%s;%s;%s\n", name, type, duration, country);
                    free(duration);
                    free(name);
                    free(country);
                    free(type);
                    free_artist(a);
                }
            }
        }
        for ( int i = 0 ; i < N ; i++ ){
            if (artists[i] != NULL) {
                free(artists[i]);
            }
        }
        fclose(output_file);
        free(filename);
        return;
    }
}