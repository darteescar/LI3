#include "Musics_Manager/musics.h"

/*------------------------------------------Estrutura---------------------------------------------*/

//Estrutura da Música
struct music{
    char* id;
    char* title;
    char** artist_id;
    int n_artists;
    char* album_id;
    char* duration;
    char* genre;
    int year;
    char* lyrics;
};

/*--------------------------------------Funções das Músicas-----------------------------------------*/

//Inicializa uma nova música
Music *init_music(){
    Music *music = malloc(sizeof(Music));
    music->id = NULL;
    music->title = NULL;
    music->artist_id = NULL;
    music->n_artists = 0;
    music->album_id = NULL;
    music->duration = NULL;
    music->genre = NULL;
    music->year = 0;
    music->lyrics = NULL;
    return music;
}

// ID
// Retorna o id da música
char *get_music_id(Music *music){
    return strdup(music->id);
}
// Define o id da música
void set_music_id(Music *music, char *id){
    free(music->id);
    music->id = strdup(id);
}

// TITLE
// Retorna o título da música
char *get_music_title(Music *music){
    return strdup(music->title);
}
// Define o título da música
void set_music_title(Music *music, char *title){
    free(music->title);
    music->title = strdup(title);
}

// ARTIST_ID
// Retorna o id dos artistas da música
char **get_music_artist_id(Music *music){
     char **liked_musics_id_passada = malloc(music->n_artists * sizeof(char *));
    for (int i = 0; i < music->n_artists; i++) {
        liked_musics_id_passada[i] = strdup(music->artist_id[i]);
    }
    return liked_musics_id_passada;
}
// Define o id dos artistas da música
void set_music_artist_id(Music *music, char **artist_id){
    free(music->artist_id);
    music->artist_id = artist_id;
}

// DURATION
// Retorna a duração da música
char *get_music_duration(Music *music){
    return strdup(music->duration);
}
// Define a duração da música
void set_music_duration(Music *music, char* duration){
    free(music->duration);
    music->duration = strdup(duration);
}

// GENRE
// Retorna o género da música
char *get_music_genre(Music *music){
    return strdup(music->genre);
}
// Define o género da música
void set_music_genre(Music *music, char *genre){
    free(music->genre);
    music->genre = strdup(genre);
}

// YEAR
// Retorna o ano da música
int get_music_year(Music *music){
    return music->year;
}
// Define o ano da música
void set_music_year(Music *music, int year){
    music->year = year;
}

// LYRICS
// Retorna a letra da música
char *get_music_lyrics(Music *music){
    return strdup(music->lyrics);
}
// Define a letra da música
void set_music_lyrics(Music *music, char *lyrics){
    free(music->lyrics);
    music->lyrics = strdup(lyrics);
}

// N_ARTISTS
// Retorna o número de artistas da música
int get_music_n_artists(Music *music){
    return music->n_artists;
}
// Define o número de artistas da música
void set_music_n_artists(Music *music, int n_artists){
    music->n_artists = n_artists;
}

// ALBUM_ID
// Retorna o id do album à qual a música pertence
char *get_music_album_id(Music *music){
    return strdup(music->album_id);
}
// Define o id do album à qual a música pertence
void set_music_album_id(Music *music, char *album_id){
    free(music->album_id);
    music->album_id = strdup(album_id);
}

// Liberta a memória alocada para a música
void free_music (Music *music){
    free(music->id);
    free(music->title);
    for(int i = 0; i < music->n_artists; i++) {
        free(music->artist_id[i]);
    }
    free(music->album_id);
    free(music->artist_id);
    free(music->duration);
    free(music->genre);
    free(music->lyrics);
    free(music);
}

// Imprime a música
void print_music(Music *music){
    printf("ID: %s\n", music->id);
    printf("Title: %s\n", music->title);
    printf("Artists: ");
    for(int i = 0; i < music->n_artists; i++) {
        printf("%s ", music->artist_id[i]);
    }
    printf("\n");
    printf("Album: %s\n", music->album_id);
    printf("Duration: %s\n", music->duration);
    printf("Genre: %s\n", music->genre);
    printf("Year: %d\n", music->year);
    printf("Lyrics: %s\n", music->lyrics);
    printf("Number of artists: %d\n", music->n_artists);
    printf("\n");
}

Music *copy_music (Music *m) {
    Music *new = init_music();
    char *id = get_music_id(m);
    set_music_id(new, id);
    //char *title = get_music_title(m);
    //set_music_title(new, title);
    char **artist_id = get_music_artist_id(m);
    char **new_artist_id = malloc(get_music_n_artists(m) * sizeof(char *));
    for (int i = 0; i < get_music_n_artists(m); i++) {
        new_artist_id[i] = strdup(artist_id[i]);
    }
    set_music_artist_id(new, new_artist_id);
    char *album_id = get_music_album_id(m);
    set_music_album_id(new, album_id);
    char *duration = get_music_duration(m);
    set_music_duration(new, duration);
    char *genre = get_music_genre(m);
    set_music_genre(new, genre);
    int year = get_music_year(m);
    set_music_year(new, year);
    //char *lyrics = get_music_lyrics(m);
    //set_music_lyrics(new, lyrics);
    int n_artists = get_music_n_artists(m);
    set_music_n_artists(new, n_artists);
    free(id);
    //free(title);
    free(album_id);
    free(duration);
    free(genre);
    //free(lyrics);
    for ( int i = 0; i < get_music_n_artists(m); i++) {
        free(artist_id[i]);
    }
    free(artist_id);
    return new;
}