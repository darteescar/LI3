#include "Artists_Manager/artists_manager.h"

/*------------------------------------------Estrutura---------------------------------------------*/

struct artists_Manager {
    GHashTable *artists;
    GHashTable *art_top;
    GHashTable *all_top_10s;
};

/*-------------------------------------Funções do Gestor dos Artistas-------------------------------*/

// Inicializa o Gestor de Artistas
Artists_Manager *init_GA() {
    Artists_Manager *am = malloc(sizeof(Artists_Manager));
    am->artists = init_HT_A();
    am->art_top = criar_tabela_principal();
    am->all_top_10s = init_ALL_TOP_10s();
    return am;
}

// Liberta a memória alocada para o Gestor de Artistas
void free_GA(Artists_Manager *am) {
    free_HT_A(am->artists);
    free(am);
}

// Função que adiciona um artista ao gestor de artistas
void add_GA_A(Artists_Manager *am, Artist *artist ) {
    add_HT_A(artist, am->artists);
}

// Função que imprime o gestor de artistas
void print_GA(Artists_Manager *am) {
    print_HT_A(am->artists);
    print_HT_week_ArtTOP(am->art_top);
}

Artist *search_GA_A (Artists_Manager *am, char *id) {
    return search_HT_A(am->artists, id);
}

void increment_GA_artist_n_albums (Artists_Manager *am, char *id) {
    increment_HT_A_artist_n_albums(am->artists, id);
}

void increment_GA_artist_reproductions (Artists_Manager *am, char **artists_id, int n_artists) {
    increment_HT_A_artist_reproductions (am->artists, artists_id, n_artists);
}

void add_GA_HT_ArtTOP (Artists_Manager *am, char **artists_id, int n_artists, char *data, int duration) {
    add_HT_week_ArtTOP(am->art_top, artists_id, n_artists, data, duration);
}

void free_GA_tabela_principal (Artists_Manager *am) {
    liberar_tabela_principal(am->art_top);
}

void free_GA_ALL_TOP_10s (Artists_Manager *am) {
    free_ALL_TOP_10s(am->all_top_10s);
}

void preenche_GA_ALL_TOP_10s (Artists_Manager *am) {
    preenche_ALL_TOP_10s(am->art_top, am->all_top_10s);
}

char **encapsula_AT10_GA(Artists_Manager *AM, char *semana_de_inicio, char *semana_de_fim, int *flag_se_for_adicionado_algo){
    return encapsula_AT10(AM->all_top_10s, semana_de_inicio, semana_de_fim, flag_se_for_adicionado_algo);
}