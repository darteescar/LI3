#include "Queries/querie_3.h"


//----------------------------------------------------------------------------------
//                                 QUERIE 3
//----------------------------------------------------------------------------------

void third_querie(char *line, int cont, Gestor *gestor) {

    int flag = 0;
    if (line[1]=='S') flag=1;

    // Parser do caracter inicial da query
    char *n1 = strsep(&line, " ");

    // Parser do Min Idade e Max Idade
    int minIdade = atoi(strsep(&line, " "));
    int maxIdade = atoi(strsep(&line, "\0"));

    Genre_Count *acumulador_head = NULL;

    acumulador_head = encapsula_GC_GP(gestor, acumulador_head, minIdade, maxIdade);

    Genre_Count *aux = acumulador_head;

    char *filename = malloc(200);
    sprintf(filename, "resultados/command%d_output.txt", cont);
    FILE *output_file = fopen(filename, "w");
    if (output_file == NULL) {
        perror("Error opening output_file");
        free(filename);
        return;
    }

    if ( aux == NULL) {
        fprintf(output_file, "\n");
        fclose(output_file);
        free(filename);
    } else {
        while (aux != NULL) {
          if (flag==0) fprintf(output_file, "%s;%d\n", get_genre_GR(aux), get_count_GR(aux));
          else fprintf(output_file, "%s=%d\n", get_genre_GR(aux), get_count_GR(aux));
          aux = get_next_GR(aux);
        }
        fclose(output_file);
        free(filename);
    }

    // Libera memória da lista acumuladora
    while (acumulador_head != NULL) {
        aux = acumulador_head;
        acumulador_head = get_next_GR(acumulador_head);
        free(get_genre_GR(aux));
        free(aux);
    }
}
