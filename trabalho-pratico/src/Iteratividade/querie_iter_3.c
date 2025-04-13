#include "Iteratividade/querie_iter_3.h"

//----------------------------------------------------------------------------------
//                                 QUERIE 3
//----------------------------------------------------------------------------------

void third_querie_iter(int minIdade, int maxIdade , Gestor *gestor) {
    
    Genre_Count *acumulador_head = NULL;
    acumulador_head = encapsula_GC_GP(gestor, acumulador_head, minIdade, maxIdade);

    Genre_Count *aux = acumulador_head;

    if ( aux == NULL) {
        printf("Nunhum dado para apresentar.\n");

    } else {
        printf("Géneros musicais mais ouvidos na faixa etária [%d-%d]:\n", minIdade, maxIdade);
        while (aux != NULL) {
           printf("---> %s: %d\n", get_genre_GR(aux), get_count_GR(aux));
           aux = get_next_GR(aux);
        }
    }

    // Libera memória da lista acumuladora
    while (acumulador_head != NULL) {
        aux = acumulador_head;
        acumulador_head = get_next_GR(acumulador_head);
        free(get_genre_GR(aux));
        free(aux);
    }
}