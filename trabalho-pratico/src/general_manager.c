#include "general_manager.h"

//----------------------------------------------------------------------------------
//                                 ESTRUTURA DO GESTOR
//----------------------------------------------------------------------------------

struct gestor {
    Users_Manager *users;
    Musics_Manager *musics;
    Artists_Manager *artists;
    Albums_Manager *albums;
    History_Manager *history;
};

//----------------------------------------------------------------------------------
//                                  GESTOR PRINCIPAL
//----------------------------------------------------------------------------------

// Inicializa o Gestor
Gestor *init_GP() {
    Gestor *g = malloc(sizeof(Gestor));
    g->users = init_GU();
    g->musics = init_GM();
    g->artists = init_GA();
    g->albums = init_GAl();
    g->history = init_GH();
    return g;
}

// Imprime o Gestor
void print_GP(Gestor *g) {
    //printf("Gestor:\n");
    //print_GU(g->users);
    //print_GM(g->musics);
    //print_GA(g->artists);   
    //print_GH(g->history);
}

// Libertar memória do Gestor
void free_GP(Gestor *g) {
    free_GU(g->users);
    free_GM(g->musics);
    free_GA(g->artists);
    free_GAl(g->albums);
    free_GH(g->history);
    free(g);
}

//----------------------------------------------------------------------------------
//                                  MÚSICAS
//----------------------------------------------------------------------------------

void add_GP_M(Gestor *g, Music *m) {
    add_GM_M(g->musics, m);
}

void free_GP_TOP(Gestor *g) { // ta feito
    free_GM_TOP(g->musics);
}

void iter_GP_top(Gestor *g, char* country, char**artists ,char**countries, int *discography, int N) {
    iter_GM_top(g->musics, country, artists, countries, discography, N);
}

void iter_GP_top_sem_pais(Gestor *g, char**artists ,char**countries, int *discography, int N) {
    iter_GM_top_sem_pais(g->musics, artists, countries, discography, N);
}

void preenche_GP_TOP(Gestor *g) {
    iterate_GM_HT_Musics(g->musics, (void (*)(Music *, void *))process_music_for_TOP, g);
}

int country_GP_TOP_exists (Gestor *g, char *country) {
    return country_GM_TOP_exists(g->musics, country);
}

Music* search_GP_M (Gestor *g, char *id) {
    return search_GM_M(g->musics, id);
}

const int musica_existe_GP(Gestor *g, char *id) {
    return musica_existe_GM(g->musics, id);
}

int search_GP_get_music_n_artists(Gestor *g, char *music_id) {
    return search_GM_get_music_n_artists(g->musics, music_id);
}

char **search_GP_get_music_artist_id(Gestor *g, char *music_id) {
    return search_GM_get_music_artist_id(g->musics, music_id);
}

void process_music_for_TOP(Music *m, Gestor *g) {
    char **artist_id = get_music_artist_id(m);
    int n_artists = get_music_n_artists(m);

    for (int i = 0; i < n_artists; i++) {
        Artist *a = search_GP_HT_A(g, artist_id[i]);
        if (a != NULL) {
            char *country = get_artist_country(a);
            add_GM_TOP_M(g->musics, m, country, artist_id[i]);
            free(country);
            free_artist(a);
        }
    }

    for (int i = 0; i < n_artists; i++) {
        free(artist_id[i]);
    }
    free(artist_id);
}

//----------------------------------------------------------------------------------
//                                UTILIZADORES
//----------------------------------------------------------------------------------

void add_GP_U (Gestor *g, User *u) {
    add_GU_HT_U(g->users, u);
    
    int idade = get_age(u);

    char **likes = get_liked_musics_id(u);
    int x = get_n_liked_musics(u);
    for ( int i = 0; i < x; i++) {
        char *like = get_UA_liked_musics_list(u, i,x);
        Music *m = search_GP_M(g, like);
        if (m != NULL) {
    
            int *idade_ptr = malloc(sizeof(int));
            *idade_ptr = idade;
            char *genre = get_music_genre(m);
            add_GU_HT_GR_User_Songs(g->users, genre, idade_ptr);
            free(genre);
            free_music(m);
        }
        free(like);
    }
    for ( int i = 0; i < x; i++) {
        free(likes[i]);
    }
    free(likes);
}

void free_GP_HT_GC(Gestor *g) {
    free_GU_HT_GC(g->users);
}

Genre_Count* encapsula_GC_GP (Gestor *gestor, Genre_Count *acumulador_head, int minIdade, int maxIdade) {
    return encapsula_GC_GU(gestor->users, acumulador_head, minIdade, maxIdade);
}

GHashTable *get_GP_HT_U(Gestor *g){
    return get_GU_HT_U(g->users);
}

User* search_GP_HT_U (Gestor *g,char *id) {
    return search_GU_HT_U(g->users,id);
}

//----------------------------------------------------------------------------------
//                                  ARTISTAS
//----------------------------------------------------------------------------------

void add_GP_A (Gestor *g, Artist *a) {
    add_GA_A(g->artists, a);
}

void free_GP_tabela_principal(Gestor *g){
    free_GA_tabela_principal(g->artists);
}

void preenche_GP_ALL_TOP_10s(Gestor *g) {
    preenche_GA_ALL_TOP_10s(g->artists);
}

char **encapsula_AT10_GP (Gestor *g, char *semana_de_inicio, char *semana_de_fim, int *flag_se_for_adicionado_algo) {
    return encapsula_AT10_GA(g->artists, semana_de_inicio, semana_de_fim, flag_se_for_adicionado_algo);
}

void free_GP_ALL_TOP_10s(Gestor *g) {
    free_GA_ALL_TOP_10s(g->artists);
}

Artist *search_GP_HT_A (Gestor *gestor, char *id) {
    return search_GA_A (gestor->artists, id);
}
//----------------------------------------------------------------------------------
//                                  ALBUNS
//----------------------------------------------------------------------------------

void add_GP_Al (Gestor *g, Album *a) {
    add_GAl_Al(g->albums, a);
    char** artists_id = get_album_artists_id(a);
    int n_artists = get_album_n_artists(a);
    for(int i = 0; i < n_artists; i++) {
        increment_GA_artist_n_albums(g->artists, artists_id[i]);
    }
}

Album *search_GP_Al (Gestor *g, char *id) {
    return search_GAl_Al(g->albums, id);
}

//----------------------------------------------------------------------------------
//                                  HISTORY
//----------------------------------------------------------------------------------

void add_GP_H (Gestor *g, History *h) {
    add_GH_H(g->history, h);
    char *music_id = get_music_id_history(h);
    const int m = musica_existe_GP(g, music_id);
    if (m) {
        int n_artists = search_GP_get_music_n_artists(g, music_id);
        char **artists_id = search_GP_get_music_artist_id(g, music_id);
        increment_GA_artist_reproductions(g->artists, artists_id, n_artists);

        char *data = get_data_history(h);
        char *duration = get_duration_history(h);
        int duration1 = duration_seg3(duration);
        add_GA_HT_ArtTOP(g->artists, artists_id, n_artists, data, duration1);
        free(data);
        free(duration);
        for ( int i = 0; i < n_artists; i++) {
            free(artists_id[i]);
        }
        free(artists_id);
    }
    free(music_id);
}

GHashTable *encapsula_LUS_GP (Gestor *gestor, char *user_id) {
    return encapsula_LUS_GH(gestor->history, user_id);
}
