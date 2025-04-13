#include "Iteratividade/querie_iter_1.h"

//----------------------------------------------------------------------------------
//                                  QUERIE 1
//----------------------------------------------------------------------------------

void first_querie_iter(Gestor *gestor, char *id){

    if (id[0] == 'U') {
        User *u = search_GP_HT_U (gestor,id); // tem de dar free
        if (u==NULL){
                printf("Usuário não existente no data set!\n");
                return;
        }

        char *email = get_email(u);
        char *first_name = get_first_name(u);
        char *last_name = get_last_name(u);
        char *country = get_country(u);
        char *id = get_username(u);

        printf("Resumo do utilizador %s:\n", id);
        printf("---> Email: %s\n", email);
        printf("---> Nome: %s\n", first_name);
        printf("---> Sobrenome: %s\n", last_name);
        printf("---> Idade: %d\n", get_age(u));
        printf("---> País onde a conta foi registrada: %s\n", country);

        free(email);
        free(first_name);
        free(last_name);
        free(country);
        free(id);
        free_user(u);
    } else {
        Artist *a = search_GP_HT_A (gestor,id); // tem de ser copia
        if (a == NULL){
                printf("Artista não existente no data set!\n");
                return;
        }

        char *name = get_artist_name(a);
        char *type = get_artist_type(a);
        char *country = get_artist_country(a);
        int num_albuns_individual = get_artist_n_albums_individual(a);
        double total = get_artist_reproductions(a);
        char* id = get_artist_id(a);

        printf("Resumo do artista %s:\n", id);
        printf("---> Nome: %s\n", name);
        printf("---> Tipo de artista: %s\n", type);
        printf("---> Nacionalidade: %s\n", country);
        printf("---> Número de albuns individuais: %d\n", num_albuns_individual);
        printf("---> Receita total: %.2f\n", total);

        free(name);
        free(type);
        free(country);
        free(id);
        free_artist(a);
        
    }

}