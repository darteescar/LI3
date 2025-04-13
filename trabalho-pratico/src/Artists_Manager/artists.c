#include "Artists_Manager/artists.h"

/*------------------------------------------Estrutura---------------------------------------------*/

// Estrutura do Artista
struct artist {
    char *id;
    char *name;
    double recipe_per_stream; // nao pode ser float ? (ocupa menos memoria)
    char *country;
    char **id_constituent;
    int n_constituent;
    char *type;
    int n_albums_individual;
    double reproductions;
};

/*--------------------------------------Funções dos Artistas-----------------------------------------*/

// Inicializa um novo artista
Artist *init_artist() {
    Artist *artist = malloc(sizeof(Artist));
    artist->id = NULL;
    artist->name = NULL;
    artist->recipe_per_stream = 0;
    artist->country = NULL;
    artist->id_constituent = NULL;
    artist->n_constituent = 0;
    artist->type = NULL;
    artist->n_albums_individual = 0;
    artist->reproductions = 0;
    return artist;
}

// ID
// Retorna o id do artista
char *get_artist_id(Artist *artist) {
    return strdup(artist->id);
}
// Define o id do artista
void set_artist_id(Artist *artist, char *id) {
    free(artist->id);
    artist->id = strdup(id);
}

// NAME
// Retorna o nome do artista
char *get_artist_name(Artist *artist) {
    return strdup(artist->name);
}
// Define o nome do artista
void set_artist_name(Artist *artist, char *name) {
    free(artist->name);
    artist->name = strdup(name);
}

// RECIPE PER STREAM
// Retorna a receita por stream do artista
double get_artist_recipe_per_stream(Artist *artist) {
    return artist->recipe_per_stream;
}
// Define a receita por stream do artista
void set_artist_recipe_per_stream(Artist *artist, double recipe_per_stream) {
    artist->recipe_per_stream = recipe_per_stream;
}

// COUNTRY
// Retorna o país do artista
char *get_artist_country(Artist *artist) {
    return strdup(artist->country);
}
// Define o país do artista
void set_artist_country(Artist *artist, char *country) {
    free(artist->country);
    artist->country = strdup(country);
}

// ID CONSTITUENT
// Retorna o id dos músicos do artista
char **get_artist_id_constituent(Artist *artist) {
    char **liked_musics_id_passada = malloc(artist->n_constituent * sizeof(char *));
    for (int i = 0; i < artist->n_constituent; i++) {
        liked_musics_id_passada[i] = strdup(artist->id_constituent[i]);
    }
    return liked_musics_id_passada;
}
// Define o id dos músicos do artista
void set_artist_id_constituent(Artist *artist, char **id_constituent) {
    free(artist->id_constituent);
    artist->id_constituent = id_constituent;
}

// N CONSTITUENT
// Retorna o número de músicos do artista
int get_artist_n_constituent(Artist *artist) {
    return artist->n_constituent;
}
// Define o número de músicos do artista
void set_artist_n_constituent(Artist *artist, int n_constituent) {
    artist->n_constituent = n_constituent;
}

// TYPE
// Retorna o tipo do artista (solo, banda, etc)
char *get_artist_type(Artist *artist) {
    return strdup(artist->type);
}
// Define o tipo do artista (solo, banda, etc)
void set_artist_type(Artist *artist, char *type) {
    free(artist->type);
    artist->type = strdup(type);
}

// N ALBUMS INDIVIDUAL
// Retorna o número de álbuns individuais do artista
int get_artist_n_albums_individual(Artist *artist) {
    return artist->n_albums_individual;
}
// Define o número de álbuns individuais do artista
void set_artist_n_albums_individual(Artist *artist, int n_albums_individual) {
    artist->n_albums_individual = n_albums_individual;
}

// REPRODUCTIONS
// Retorna o número de reproduções do artista
double get_artist_reproductions(Artist *artist) {
    return artist->reproductions;
}
// Define o número de reproduções do artista
void set_artist_reproductions(Artist *artist, double reproductions) {
    artist->reproductions = reproductions;
}

// Liberta a memória alocada para o artista
void free_artist(Artist *artist) {
    free(artist->id);
    free(artist->name);
    free(artist->country);
    for(int i = 0; i < artist->n_constituent; i++) {
        free(artist->id_constituent[i]);
    }
    free(artist->id_constituent);
    free(artist->type);
    free(artist);
}

// Imprime o artista
void print_artist(Artist *artist){
    printf("ID: %s\n", artist->id);
    printf("Name: %s\n", artist->name);
    printf("Recipe per stream: %f\n", artist->recipe_per_stream);
    printf("Country: %s\n", artist->country);
    printf("N Constituent: %d\n", artist->n_constituent);
    for(int i = 0; i < artist->n_constituent; i++) {
        printf("Constituent %d: %s\n", i, artist->id_constituent[i]);
    }
    printf("Type: %s\n", artist->type); 
    printf("N Albums Individual: %d\n", artist->n_albums_individual);
    printf("Reproductions: %f\n", artist->reproductions);
    printf("\n");
}

Artist* copy_artist(Artist *a) {
    Artist *new = init_artist();
    char *id = get_artist_id(a);
    set_artist_id(new, id);
    char *name = get_artist_name(a);
    set_artist_name(new, name);
    double recipe_per_stream = get_artist_recipe_per_stream(a);
    set_artist_recipe_per_stream(new, recipe_per_stream);
    char *country = get_artist_country(a);
    set_artist_country(new, country);

    char **id_constituent = get_artist_id_constituent(a);
    char **new_id_constituent = malloc(get_artist_n_constituent(a) * sizeof(char *));
    for (int i = 0; i < get_artist_n_constituent(a); i++) {
        new_id_constituent[i] = strdup(id_constituent[i]);
    }
    set_artist_id_constituent(new, new_id_constituent);

    int n_constituent = get_artist_n_constituent(a);
    set_artist_n_constituent(new, n_constituent);
    char *type = get_artist_type(a);
    set_artist_type(new, type);
    int n_albums_individual = get_artist_n_albums_individual(a);
    set_artist_n_albums_individual(new, n_albums_individual);
    double reproductions = get_artist_reproductions(a);
    set_artist_reproductions(new, reproductions);

    free(id);
    free(name);
    free(country);
    free(type);
    for(int i = 0; i < n_constituent; i++) {
        free(id_constituent[i]);
    }
    free(id_constituent);   
    return new;
}