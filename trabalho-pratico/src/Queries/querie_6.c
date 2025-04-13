#include "Queries/querie_6.h"

//----------------------------------------------------------------------------------
//                                 QUERIE 6
//----------------------------------------------------------------------------------

struct artist_list {
    char *artist_id;
    int time_listened;
    char **music_id;
    int n_musics;
    char flag;
};

char* get_ArtistList_artist_id(Artist_List *artist_list) {
    return strdup(artist_list->artist_id);
}

int get_ArtistList_time_listened(Artist_List *artist_list) {
    return artist_list->time_listened;
}

char** get_ArtistList_music_id(Artist_List *artist_list) {
    char **copy = (char **)malloc((artist_list->n_musics + 1) * sizeof(char *));
    for (int i = 0; i < artist_list->n_musics; i++) {
        copy[i] = strdup(artist_list->music_id[i]);
        if (copy[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(copy[j]);
            }
            free(copy);
            return NULL;
        }
    }
    copy[artist_list->n_musics] = NULL;

    return copy;
}

int get_ArtistList_n_musics(Artist_List *artist_list) {
    return artist_list->n_musics;
}

char get_ArtistList_flag(Artist_List *artist_list) {
    return artist_list->flag;
}

void set_ArtistList_flag(Artist_List *artist_list, char flag) {
    artist_list->flag = flag;
}

void print_artist_list (GHashTable *ht) {
    GHashTableIter iter;
    gpointer key, value;
    g_hash_table_iter_init(&iter, ht);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        Artist_List *artist_list = (Artist_List *) value;
        printf("Artist: %s\n", artist_list->artist_id);
        printf("Time listened: %d\n", artist_list->time_listened);
        printf("Musics listened: %d\n", artist_list->n_musics);
        for (int i = 0; i < artist_list->n_musics; i++) {
            printf("Music: %s\n", artist_list->music_id[i]);
        }
        printf("%c\n", artist_list->flag);
        putchar('\n');
    }
}

GHashTable *init_HT_Artist_List() {
    g_hash_table_new_full(g_str_hash, g_str_equal, free, (GDestroyNotify) free_HT_Artist_List_value);
}

void free_HT_Artist_List(GHashTable *ht) {
    g_hash_table_destroy(ht);
}

void free_HT_Artist_List_value(Artist_List *artist_list) {
    free(artist_list->artist_id);
    for ( int i = 0 ; i < artist_list->n_musics ; i++) {
        free(artist_list->music_id[i]);
    }
    free(artist_list->music_id);
    free(artist_list);
}

void add_artist_to_listened_artists(GHashTable *ht, char **artist_id, int n_artists, int *max_artist_n_listened, char *max_artist_id, int duration, char *music_id) {   
    for (int i = 0; i < n_artists; i++) {
     Artist_List *artist_list = g_hash_table_lookup(ht, artist_id[i]);
    if (artist_list == NULL) {
        artist_list = malloc(sizeof(struct artist_list));
        artist_list->artist_id = strdup(artist_id[i]);
        artist_list->time_listened = duration;
        artist_list->music_id = malloc(sizeof(char *));
        artist_list->music_id[0] = strdup(music_id);
        artist_list->n_musics = 1;
        artist_list->flag = 'a';
        g_hash_table_insert(ht, strdup(artist_id[i]), artist_list);
    } else {
        artist_list->n_musics++;
        artist_list->music_id = realloc(artist_list->music_id, artist_list->n_musics * sizeof(char *));
        artist_list->music_id[artist_list->n_musics - 1] = strdup(music_id);
        artist_list->time_listened += duration;
    }

    if (artist_list->time_listened > *max_artist_n_listened) {
        *max_artist_n_listened = artist_list->time_listened;
        strcpy(max_artist_id, artist_id[i]);
    }
    else if (artist_list->time_listened == *max_artist_n_listened) {
            if (strcmp(artist_id[i], max_artist_id) < 0) {
                strcpy(max_artist_id, artist_id[i]);
            }
        }
    }
}

struct music_list {
    char *music_id;
    int n_listened;
    struct music_list *next;
};

GHashTable *init_HT_Music_List() {
    g_hash_table_new_full(g_str_hash, g_str_equal, free, (GDestroyNotify) free_HT_Music_List_value);
}

void free_HT_Music_List(GHashTable *ht) {
    g_hash_table_destroy(ht);
}

void free_HT_Music_List_value(Music_List *music_list) {
    Music_List *current = music_list;
    Music_List *next;
    while (current != NULL) {
        next = current->next;
        free(current->music_id);
        free(current);
        current = next;
    }
}

void add_music_to_listened_musics(GHashTable *ht, char *music_id, int *num_musicas_ouvidas_sem_repeticao) {
    Music_List *music_list = g_hash_table_lookup(ht, music_id);
    if (music_list == NULL) {
        music_list = malloc(sizeof(struct music_list));
        music_list->music_id = strdup(music_id);
        music_list->n_listened = 1;
        music_list->next = NULL;
        *num_musicas_ouvidas_sem_repeticao += 1;
        g_hash_table_insert(ht, strdup(music_id), music_list);
    } else {
        music_list->n_listened++;
    }

    
}

void user_vazio_ou_inexistente(int cont) {
    char *filename = malloc(200);
    sprintf(filename, "resultados/command%d_output.txt", cont);
    FILE *output_file = fopen(filename, "a");
    if (output_file == NULL) {
        perror("Error opening user_file");
        return;
    }
    fprintf(output_file, "\n");
    fclose(output_file);
    free(filename);
    return;
}

bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int calcula_dia(char *data) {
    int ano = 0, mes = 0, dia = 0;

    sscanf(data, "%d/%d/%d", &ano, &mes, &dia);

    int dias_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (is_leap_year(ano)) {
        dias_por_mes[1] = 29;
    }

    // Calcula o dia do ano
    int total = 0;
    for (int i = 0; i < mes - 1; i++) {
        total += dias_por_mes[i];
    }
    total += dia;
    return total;
}

void reconstroi_data (int ano, int dia, char *data) {
    int dias_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (is_leap_year(ano)) {
        dias_por_mes[1] = 29;
    }

    int mes = 0;
    int dia_do_mes = 0;
    for (int i = 0; i < 12; i++) {
        if (dia <= dias_por_mes[i]) {
            mes = i + 1;
            dia_do_mes = dia;
            break;
        }
        dia -= dias_por_mes[i];
    }
    sprintf(data, "%02d/%02d/%02d", ano,mes,dia_do_mes);
}

struct genre_list {
    char *genre;
    int n_listened;
};

GHashTable *init_HT_Genre_List() {
    g_hash_table_new_full(g_str_hash, g_str_equal, free, (GDestroyNotify) free_HT_Genre_List_value);
}

void free_HT_Genre_List(GHashTable *ht) {
    g_hash_table_destroy(ht);
}

void free_HT_Genre_List_value(Genre_List *genre_list) {
    free(genre_list->genre);
    free(genre_list);
}

void add_genre_to_listened_genres(GHashTable *ht, char *genre, int *max_genre_n_listened, char *max_genre, int durationn) {    
    Genre_List *genre_list = g_hash_table_lookup(ht, genre);
        if (genre_list == NULL) {
            genre_list = malloc(sizeof(struct genre_list));
            genre_list->genre = strdup(genre);
            genre_list->n_listened = durationn;
            g_hash_table_insert(ht, strdup(genre), genre_list);
        } else {
            genre_list->n_listened += durationn;
        }

        if (genre_list->n_listened > *max_genre_n_listened) {
            *max_genre_n_listened = genre_list->n_listened;
            strcpy(max_genre, genre);
        }
        else if (genre_list->n_listened == *max_genre_n_listened) {
            if (strcmp(genre, max_genre) < 0) {
                strcpy(max_genre, genre);
            }
    }
}

struct album_list {
    char *album_id;
    int tempo_reproducao;
};

GHashTable *init_HT_Album_List() {
    g_hash_table_new_full(g_str_hash, g_str_equal, free, (GDestroyNotify) free_HT_Album_List_value);
}

void free_HT_Album_List(GHashTable *ht) {
    g_hash_table_destroy(ht);
}

void free_HT_Album_List_value(Album_List *album_list) {
    free(album_list->album_id);
    free(album_list);
}

void add_album_to_listened_albums(GHashTable *ht, char *album_id, int *max_album_n_listened, char *max_album_id, int durationn) {
    Album_List *album_list = g_hash_table_lookup(ht, album_id);
    if (album_list == NULL) {
        album_list = malloc(sizeof(struct album_list));
        album_list->album_id = strdup(album_id);
        album_list->tempo_reproducao = durationn;
        g_hash_table_insert(ht, strdup(album_id), album_list);
    } else {
        album_list->tempo_reproducao += durationn;
    }

    if (album_list->tempo_reproducao > *max_album_n_listened) {
        *max_album_n_listened = album_list->tempo_reproducao;
        strcpy(max_album_id, album_id);
    }
    else if (album_list->tempo_reproducao == *max_album_n_listened) {
        if (strcmp(album_id, max_album_id) < 0) {
            strcpy(max_album_id, album_id); // este desempate pode estar errado
        }
    }
}

void sixth_querie(char *line, int cont, Gestor *gestor) {
    int flag = 0;
    char user_id[9] = {0};
    int year = 0;
    int extra = -1;

    if (line[1] == 'S') {
        flag = 1;
        sscanf(line + 3, "%8s %d %d", user_id, &year, &extra);
    } else {
        sscanf(line + 2, "%8s %d %d", user_id, &year, &extra);
    }

    User *user = search_GP_HT_U(gestor, user_id);

    if (user == NULL) {
        user_vazio_ou_inexistente(cont);
        return;
    }

    GHashTable *al = init_HT_Artist_List();
    GHashTable *mucs = init_HT_Music_List();
    GHashTable *gen = init_HT_Genre_List();
    GHashTable *alb = init_HT_Album_List();

    GHashTable *aux = encapsula_LUS_GP(gestor, user_id); // copia da lista de user songs

    if (aux == NULL) {
        free_HT_Artist_List(al);
        free_HT_Music_List(mucs);
        free_HT_Genre_List(gen);
        free_HT_Album_List(alb);
        free_user(user);
        user_vazio_ou_inexistente(cont);
        return;
    }

    int flag_da_atividade_do_user = 0;
    
    // Primeira parte da query
    int temp_total_audc = 0;

    // Segunda parte da query
    int *num_musicas_ouvidas_sem_repeticao = malloc(sizeof(int));
    *num_musicas_ouvidas_sem_repeticao = 0;

    // Terceira parte da query
    char *max_artist_id = malloc(9 * sizeof(char));
    int *max_artist_n_listened = malloc(sizeof(int));
    *max_artist_n_listened = 0;
    
    // Quarta parte da query
    int musics_listened_per_day[366] = {0};

    // Quinta parte da query
    int *max_genre_n_listened = malloc(sizeof(int));
    *max_genre_n_listened = 0;
    char *max_genre = malloc(15 * sizeof(char));

    // Sexta parte da query
    int *max_album_n_listened = malloc(sizeof(int));
    *max_album_n_listened = 0;
    char *max_album_id = malloc(9 * sizeof(char));

    // Sétima parte da query
    int max_hora_que_costuma_ouvir_musica = 0;
    int hora_que_costuma_ouvir_musica = 0;
    int array_hora_que_costuma_ouvir_musica[24] = {0};
    
    GHashTableIter iter;
    gpointer key, value;
    g_hash_table_iter_init(&iter, aux);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        History *history = (History *) value;
        if ( get_year_history(history) == year ) {
            flag_da_atividade_do_user = 1;
            char *song_id = get_music_id_history(history);
            Music *music = search_GP_M(gestor, song_id);
            free(song_id);
            if (music != NULL && history != NULL) {
                
                // Primeira parte da query
                char *duration = get_duration_history(history);
                int durationn = duration_seg(duration);
                temp_total_audc += durationn;
                free(duration);
                
                // Segunda parte da query
                char *music_id = get_music_id_history(history);
                add_music_to_listened_musics(mucs, music_id, num_musicas_ouvidas_sem_repeticao);

                // Terceira parte da query
                char **artist_id = get_music_artist_id(music);
                int n_artists = get_music_n_artists(music);
                add_artist_to_listened_artists(al,artist_id, n_artists, max_artist_n_listened, max_artist_id, durationn ,music_id);
                for (int i = 0; i < n_artists; i++) {
                    free(artist_id[i]);
                }
                free(artist_id);
                free(music_id);

                // Quarta parte da query
                char *day = get_data_history(history);
                int dia = calcula_dia(day);
                musics_listened_per_day[dia]++;
                free(day);

                // Quinta parte da query
                char *genre = get_music_genre(music);
                add_genre_to_listened_genres(gen, genre, max_genre_n_listened, max_genre, durationn);
                free(genre);

                // Sexta parte da query
                char *album_id = get_music_album_id(music);
                add_album_to_listened_albums(alb, album_id, max_album_n_listened, max_album_id, durationn);
                free(album_id);

                // Sétima parte da query
                char *timestamp = get_hora_history(history);
                int hora, minuto, segundo;
                sscanf(timestamp, "%d:%d:%d", &hora, &minuto, &segundo);
                array_hora_que_costuma_ouvir_musica[hora] += durationn;
                if (array_hora_que_costuma_ouvir_musica[hora] == max_hora_que_costuma_ouvir_musica) {
                    if (hora < hora_que_costuma_ouvir_musica) {
                        hora_que_costuma_ouvir_musica = hora;
                    }
                }
                else if (array_hora_que_costuma_ouvir_musica[hora] > max_hora_que_costuma_ouvir_musica) {
                    max_hora_que_costuma_ouvir_musica = array_hora_que_costuma_ouvir_musica[hora];
                    hora_que_costuma_ouvir_musica = hora;
                }
                free(timestamp);
            }   
            else {
                free(num_musicas_ouvidas_sem_repeticao);
                free(max_artist_id);
                free(max_artist_n_listened);
                free(max_genre_n_listened);
                free(max_genre);
                free(max_album_n_listened);
                free(max_album_id);
                free_HT_Artist_List(al);
                free_HT_Music_List(mucs);
                free_HT_Genre_List(gen);
                free_HT_Album_List(alb);
                free_user(user);
                g_hash_table_destroy(aux);
                user_vazio_ou_inexistente(cont);
                return;
            }
            free_music(music);
        }
    }

    if (flag_da_atividade_do_user == 0) {
        free(num_musicas_ouvidas_sem_repeticao);
        free(max_artist_id);
        free(max_artist_n_listened);
        free(max_genre_n_listened);
        free(max_genre);
        free(max_album_n_listened);
        free(max_album_id);
        free_HT_Artist_List(al);
        free_HT_Music_List(mucs);
        free_HT_Genre_List(gen);
        free_HT_Album_List(alb);
        free_user(user);
        user_vazio_ou_inexistente(cont);
        g_hash_table_destroy(aux);
        return; 
    }

    char duration[16]; //size que garante que nao ha overflow
    int horas = temp_total_audc / 3600;
    int minutos = (temp_total_audc % 3600) / 60;
    int segundos = temp_total_audc % 60;
    sprintf(duration, "%02d:%02d:%02d", horas, minutos, segundos);

    char *filename = malloc(200);
    sprintf(filename, "resultados/command%d_output.txt", cont);
    FILE *output_file = fopen(filename, "w");
    if (output_file == NULL) {
        perror("Error opening output_file");
        free(filename);
        return;
    }
    int dia_max = 0;
    int max = 0;

    for ( int i = 0 ; i < 366 ; i++ ) {
        if (musics_listened_per_day[i] >= max) {
            max = musics_listened_per_day[i];
            dia_max = i;
        }
    }
    char data[11];
    reconstroi_data(year, dia_max, data);

    if (flag==0) fprintf(output_file, "%s;%d;%s;%s;%s;%s;%02d\n", duration, *num_musicas_ouvidas_sem_repeticao, max_artist_id, data, max_genre, max_album_id, hora_que_costuma_ouvir_musica);
    else fprintf(output_file,"%s=%d=%s=%s=%s=%s=%02d\n", duration, *num_musicas_ouvidas_sem_repeticao, max_artist_id, data, max_genre, max_album_id, hora_que_costuma_ouvir_musica);   

   
    int n_artistas = g_hash_table_size(al);
    if (extra != -1) {
        int n_vezes_que_vai_iterar;
        if (extra > n_artistas) {
            n_vezes_que_vai_iterar = n_artistas;
        } else {
            n_vezes_que_vai_iterar = extra;
        }
        for (int i = 0; i < n_vezes_que_vai_iterar; i++) {
            int max = 0;
            char *max_artist_id = NULL;
            int num_musics = 0;
            GHashTableIter iter;
            gpointer key, value;
            g_hash_table_iter_init(&iter, al);
            while (g_hash_table_iter_next(&iter, &key, &value)) {
                Artist_List *artist_list = (Artist_List *) value;
                if (artist_list->time_listened > max && artist_list->flag == 'a') {
                    max = artist_list->time_listened;
                    max_artist_id = strdup(artist_list->artist_id);
                    num_musics = artist_list->n_musics;
                    
                }
                else if (artist_list->time_listened == max && artist_list->flag == 'a') {
                    if (strcmp(artist_list->artist_id, max_artist_id) < 0) {
                        strcpy(max_artist_id, artist_list->artist_id);
                        num_musics = artist_list->n_musics;

                    }
                }
            }
            if (max_artist_id != NULL) {
             
                char duration[16]; //size que garante que nao ha overflow
                int horas = max / 3600;
                int minutos = (max % 3600) / 60;
                int segundos = max % 60;
                sprintf(duration, "%02d:%02d:%02d", horas, minutos, segundos);
                if (flag==0) fprintf(output_file, "%s;%d;%s\n", max_artist_id, num_musics, duration);
                else {
                    fprintf(output_file, "%s=%d=%s\n", max_artist_id, num_musics, duration);
                }
                Artist_List *artist_list_1 = g_hash_table_lookup(al, max_artist_id);
                artist_list_1->flag = 'b';
                free(max_artist_id);
            }
            max = 0;
        }
    }

    free(filename);
    free(num_musicas_ouvidas_sem_repeticao);
    free(max_artist_id);
    free(max_artist_n_listened);
    free(max_genre_n_listened);
    free(max_genre);
    free(max_album_n_listened);
    free(max_album_id);
    free_user(user);
    free_HT_Artist_List(al);
    free_HT_Music_List(mucs);
    free_HT_Genre_List(gen);
    free_HT_Album_List(alb);
    g_hash_table_destroy(aux);
    fclose(output_file);
}