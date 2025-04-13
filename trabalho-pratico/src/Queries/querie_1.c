#include "Queries/querie_1.h"


//----------------------------------------------------------------------------------
//                                  QUERIE 1
//----------------------------------------------------------------------------------

void first_querie(Gestor *gestor, char *line, int cont){
    int flag = 0;
    if (line[1]=='S') {flag=1;}

    if (flag==0){
        line+=2;
        line[8]='\0';
    } else {
        line+=3;
        line[8]='\0';
    }

    if (line[0] == 'U') {
        User *u = search_GP_HT_U (gestor,line); // tem de dar free
        if (u==NULL){
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
                free(u);
                return;
        }
        
        char* filename = malloc(200);
        sprintf(filename, "resultados/command%d_output.txt", cont);
        FILE *output_file = fopen(filename, "a");
        if(output_file == NULL){
            perror("Error opening user_file");
            return;
        }
        char *email = get_email(u);
        char *first_name = get_first_name(u);
        char *last_name = get_last_name(u);
        char *country = get_country(u);
        if (flag==0) fprintf(output_file, "%s;%s;%s;%d;%s\n", email, first_name, last_name ,get_age(u) ,country );
        else fprintf(output_file, "%s=%s=%s=%d=%s\n", email, first_name, last_name ,get_age(u) ,country );
        fclose(output_file);
        free(filename);
        free(email);
        free(first_name);
        free(last_name);
        free(country);
        free_user(u);
    } else {
        Artist *a = search_GP_HT_A (gestor,line); // tem de ser copia
        if (a == NULL){
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
        
        char* filename = malloc(200);
        sprintf(filename, "resultados/command%d_output.txt", cont);
        FILE *output_file = fopen(filename, "a");
        if(output_file == NULL){
            perror("Error opening user_file");
            return;
        }
        char *name = get_artist_name(a);
        char *type = get_artist_type(a);
        char *country = get_artist_country(a);
        int num_albuns_individual = get_artist_n_albums_individual(a);
        double total = get_artist_reproductions(a);
        if (flag==0) fprintf(output_file, "%s;%s;%s;%d;%.2f\n", name, type, country, num_albuns_individual, total);
        else fprintf(output_file, "%s=%s=%s=%d=%.2f\n", name, type, country, num_albuns_individual, total);
        fclose(output_file);
        free(filename);
        free(name);
        free(type);
        free(country); 
        free_artist(a);  
    }
}