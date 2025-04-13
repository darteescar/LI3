#include "History_Manager/history.h"

//------------------Estruturas------------------//

struct history{
    char *history_id;
    char* user_id;//
    char* music_id;//
    char* data;
    char* hora;
    char* duration;//
};

//------------------Funções do History------------------/

History* init_history(){
    History* h = malloc(sizeof(struct history));
    h->history_id = NULL;
    h->user_id = NULL;
    h->music_id = NULL;
    h->data = NULL;
    h->hora = NULL;
    h->duration = NULL;
    return h;
}

// Getters e Setters

// History ID
char* get_history_id(History* h){
    return strdup(h->history_id);
}

void set_history_id(History* h, char* history_id){
    free(h->history_id);
    h->history_id = strdup(history_id);
}
// User ID
char* get_user_id_history(History* h){
    return strdup(h->user_id);
}

void set_user_id_history(History* h, char* user_id){
    free(h->user_id);
    h->user_id = strdup(user_id);
}

// Music ID
char* get_music_id_history(History* h){
    return strdup(h->music_id);
}

void set_music_id_history(History* h, char* music_id){
    free(h->music_id);
    h->music_id = strdup(music_id);
}

// Duration
char* get_duration_history(History* h){
    return strdup(h->duration);
}

void set_duration_history(History* h, char* duration){
    free(h->duration);
    h->duration = strdup(duration);
}

// Hora
char *get_hora_history(History *h){
    return strdup(h->hora);
}

void set_hora_history (History *h, char *hora) {
    free(h->hora);
    h->hora = strdup(hora);
}

// Data
char *get_data_history(History *h) {
    return strdup(h->data);
}

void set_data_history (History *h, char *data) {
    free(h->data);
    h->data = strdup(data);
}

int get_year_history (History *h) {
    char *ano = get_data_history(h);
    
    int year;
    sscanf(ano, "%d", &year);
    free(ano);
    return year;
}

void free_history(History* h){
    free(h->history_id);
    free(h->user_id);
    free(h->music_id);
    free(h->data);
    free(h->hora);
    free(h->duration);
    free(h);
}

void print_history(History* h){
    printf("History ID: %s\n", h->history_id);
    printf("User ID: %s\n", h->user_id);
    printf("Music ID: %s\n", h->music_id);
    printf("Data: %s\n", h->data );
    printf("Hora: %s\n", h->hora );
    printf("Duration: %s\n", h->duration);
}

History *copy_history (History *h) {
    History *copy = init_history();
    char *history_id = get_history_id(h);
    set_history_id(copy, history_id);
    free(history_id);
    char *user_id = get_user_id_history(h);
    set_user_id_history(copy, user_id);
    free(user_id);
    char *music_id = get_music_id_history(h);
    set_music_id_history(copy, music_id);
    free(music_id);
    char *data = get_data_history(h);
    set_data_history(copy, data);
    free(data);
    char *hora = get_hora_history(h);
    set_hora_history(copy, hora);
    free(hora);
    char *duration = get_duration_history(h);
    set_duration_history(copy, duration);
    free(duration);
    return copy;
}