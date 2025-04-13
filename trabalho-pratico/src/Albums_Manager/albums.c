#include "Albums_Manager/albums.h"

/*------------------------------------------Estrutura---------------------------------------------*/

// Estrutura do Album
struct album {
    char *id;
    char* title;
    char** artists_id;
    int n_artists;
    int year;
    char** producers;
    int n_producers;
};

/*--------------------------------------Funções dos Albums -----------------------------------------*/

// Inicializa um novo album
Album *init_album() {
    Album *album = (Album *) malloc(sizeof(Album));
    album->id = NULL;
    album->title = NULL;
    album->artists_id = NULL;
    album->year = 0;
    album->producers = NULL;
    album->n_artists = 0;
    album->n_producers = 0;
    return album;
}

// ID
// Retorna o id do album
char *get_album_id(Album *album) {
    return strdup(album->id);
}

// Define o id do album
void set_album_id(Album *album, char *id) {
    free(album->id);
    album->id = strdup(id);
}

// TITLE
// Retorna o título do album
char *get_album_title(Album *album) {
    return strdup(album->title);
}

// Define o título do album
void set_album_title(Album *album, char *title) {
    free(album->title);
    album->title = strdup(title);
}

// ARTISTS ID
// Retorna o id dos artistas do album
char **get_album_artists_id(Album *album) {
    return album->artists_id;
}

// Define o id dos artistas do album
void set_album_artists_id(Album *album, char **artists_id) { // ATENÇÃO: A função não liberta a memória alocada para os artistas
    
    free(album->artists_id);
    album->artists_id = artists_id;
}

// N ARTISTS
// Retorna o número de artistas do album
int get_album_n_artists(Album *album) {
    return album->n_artists;
}

// Define o número de artistas do album
void set_album_n_artists(Album *album, int n_artists) {
    album->n_artists = n_artists;
}

// YEAR
// Retorna o ano do album
int get_album_year(Album *album) {
    return album->year;
}

// Define o ano do album
void set_album_year(Album *album, int year) {
    album->year = year;
}

// PRODUCERS
// Retorna os produtores do album
char **get_album_producers(Album *album) {
    return album->producers;
}

// Define os produtores do album
void set_album_producers(Album *album, char **producers) {
    for(int i = 0; i < album->n_producers; i++) {
        free(album->producers[i]);
    }
    free(album->producers);
    album->producers = producers;
}

// N PRODUCERS
// Retorna o número de produtores do album
int get_album_n_producers(Album *album) {
    return album->n_producers;
}

// Define o número de produtores do album
void set_album_n_producers(Album *album, int n_producers) {
    album->n_producers = n_producers;
}

// Liberta a memória alocada para o album
void free_album(Album *artist) {
    free(artist->id);
    free(artist->title);
    for(int i = 0; i < artist->n_artists; i++) {
        free(artist->artists_id[i]);
    }
    free(artist->artists_id);
    for(int i = 0; i < artist->n_producers; i++) {
        free(artist->producers[i]);
    }
    free(artist->producers);
    free(artist);
}

// Imprime o album
void print_album(Album *artist){
    printf("ID: %s\n", artist->id);
    printf("Title: %s\n", artist->title);
    printf("Artists ID: ");
    for(int i = 0; i < artist->n_artists; i++) {
        printf("%s ", artist->artists_id[i]);
    }
    printf("\n");
    printf("Year: %d\n", artist->year);
    printf("Producers: ");
    for(int i = 0; i < artist->n_producers; i++) {
        printf("%s ", artist->producers[i]);
    }
    printf("\n");

}