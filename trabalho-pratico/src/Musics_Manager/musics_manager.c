#include "Musics_Manager/musics_manager.h"
#include "Musics_Manager/TOP_Music.h"

/*------------------------------------------Estrutura---------------------------------------------*/

// Estrutura do Gestor de Músicas
struct musics_Manager {
    GHashTable *ht_music;
    GHashTable *top;
};

/*-------------------------------------Funções do Gestor de Músicas-------------------------------*/

// Inicializa o Gestor de Músicas
Musics_Manager *init_GM() {
    Musics_Manager *mm = malloc(sizeof(Musics_Manager));
    mm->ht_music = init_HT_M();
    mm->top = init_TOP();
    return mm;
}

// Liberta a memória alocada para o Gestor de Músicas (apenas a HT porque a lista TOP é libertada antes)
void free_GM(Musics_Manager *mm) {
    free_HT_M(mm->ht_music);
    free(mm);
}

// Imprime o Gestor de Músicas
void print_GM(Musics_Manager *mm) {
    printf("Music Manager:\n");
    //print_HT_M(mm->ht_music);
    print_TOP(mm->top);
}

// Função que adiciona uma música ao gestor de músicas
void add_GM_M(Musics_Manager *mm, Music *m) {
    add_HT_M(m, mm->ht_music);
}

Music* search_GM_M (Musics_Manager *mm, char *id) {
    return search_HT_M(mm->ht_music, id);
}

const int musica_existe_GM(Musics_Manager *mm, char *id) {
    return g_hash_table_contains(mm->ht_music, id);
}

void free_GM_TOP(Musics_Manager *mm) {
    free_TOP(mm->top);
}

int duration_seg3 (char* duration){
    char hour[3], min[3], sec[3];
    strncpy(hour, duration, 2);
    hour[2] = '\0';
    strncpy(min, duration + 3, 2);
    min[2] = '\0';
    strncpy(sec, duration + 6, 2);
    sec[2] = '\0';

    int hour_num = atoi(hour);
    int min_num = atoi(min);
    int sec_num = atoi(sec);

    return hour_num * 3600 + min_num * 60 + sec_num;
}

void add_GM_TOP_M (Musics_Manager *mm, Music *m, char *country, char *artist_id){
    char *music_duration = get_music_duration(m);
    int duration = duration_seg3(music_duration);
    add_TOP_M(mm->top, artist_id, country, duration);
    free(music_duration);
}

//----------Encapsulamento

void iter_GM_top(Musics_Manager *mm, char *country, char **artists, char **countries, int *discography, int N){
    iter_top(mm->top,country, artists, countries, discography, N);
}

void iter_GM_top_sem_pais(Musics_Manager *mm, char **artists, char **countries, int *discography, int N){
    iter_top_sem_pais(mm->top, artists, countries, discography, N);
}

void iterate_GM_HT_Musics(Musics_Manager *mm, void (*callback)(Music *m, void *user_data), void *user_data) {
    iterate_HT_M(mm->ht_music, callback, user_data);
}

int search_GM_get_music_n_artists (Musics_Manager *mm, char *music_id) {
    return search_HT_get_music_n_artists(mm->ht_music, music_id);
}

char **search_GM_get_music_artist_id (Musics_Manager *mm, char *music_id) {
    return search_HT_get_music_artist_id(mm->ht_music, music_id);
}

int country_GM_TOP_exists (Musics_Manager *mm, char *country) {
    return country_TOP_exists(mm->top, country);
}