#include "Iteratividade/querie_iter_5.h"

//----------------------------------------------------------------------------------
//                                 QUERIE 5
//----------------------------------------------------------------------------------



void fifth_querie_iter(char *id, int n, Gestor *gestor, int ***matriz, char ***array, int *tamanho_atual) {

    User *u = search_GP_HT_U(gestor, id);
    if (!u) {
        printf("\n");
        return;
    }

    // Array de gêneros
    char *generos[] = {
        "Electronic", "Reggae", "Metal", "Hip Hop", "Country",
        "Blues", "Classical", "Rock", "Jazz", "Pop"
    };

    // Recomendações de utilizadores (adaptar conforme necessário)
    char **users_recomendados = recomendaUtilizadores(id, *matriz, *array, generos, *tamanho_atual, 10, n);

    // Imprimir resultados
    printf("Recomendações para %s:\n", id);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("---> %s\n", users_recomendados[i]);
        printf("\n");
    }
    free_user(u);
}