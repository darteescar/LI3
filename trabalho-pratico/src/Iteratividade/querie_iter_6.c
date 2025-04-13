#include "Iteratividade/querie_iter_6.h"

//----------------------------------------------------------------------------------
//                                 QUERIE 6
//----------------------------------------------------------------------------------

void sixth_querie_iter(char *line, Gestor *gestor) {
    char user_id[9] = {0};
    int year = 0;
    int extra = -1;

    sscanf(line + 2, "%8s %d %d", user_id, &year, &extra);

    User *user = search_GP_HT_U(gestor, user_id);

    GHashTable *al = init_HT_Artist_List();
    GHashTable *mucs = init_HT_Music_List();
    GHashTable *gen = init_HT_Genre_List();
    GHashTable *alb = init_HT_Album_List();

    GHashTable *aux = encapsula_LUS_GP(gestor, user_id);

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
        if (get_year_history(history)== year) {
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
                printf("Sem informação para mostrar!\n");
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
        g_hash_table_destroy(aux);
        printf("Sem informação para mostrar!\n");
        return;
    }

    char duration[16]; //size que garante que nao ha overflow
    int horas = temp_total_audc / 3600;
    int minutos = (temp_total_audc % 3600) / 60;
    int segundos = temp_total_audc % 60;
    sprintf(duration, "%02d:%02d:%02d", horas, minutos, segundos);

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

    printf("Resumo do utilizador %s no ano %d:\n", user_id, year);
    printf("---> Duração total: %s\n", duration);
    printf("---> Número de músicas distintas ouvidas: %d\n", *num_musicas_ouvidas_sem_repeticao);
    printf("---> Artista que mais ouviu: %s\n", max_artist_id);
    printf("---> Data em que mais ouviu música: %s\n", data);
    printf("---> Género que mais ouviu: %s\n", max_genre);
    printf("---> Álbum que mais ouviu: %s\n", max_album_id);
    printf("---> Hora a que costuma ouvir música: %02d\n", hora_que_costuma_ouvir_musica);


    int n_artistas = g_hash_table_size(al);
    if (extra != -1) {
        int n_vezes_que_vai_iterar;
        if (extra > n_artistas) {
            n_vezes_que_vai_iterar = n_artistas;
        } else {
            n_vezes_que_vai_iterar = extra;
        }
        if (n_vezes_que_vai_iterar > 0) {
            printf("\n");
            printf("Artistas que mais ouviu este ano:\n");
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
                if (get_ArtistList_time_listened(artist_list) > max && get_ArtistList_flag(artist_list) == 'a') {
                    max = get_ArtistList_time_listened(artist_list);
                    max_artist_id = get_ArtistList_artist_id(artist_list);
                    num_musics = get_ArtistList_n_musics(artist_list);
                    
                }
                else if (get_ArtistList_time_listened(artist_list) == max && get_ArtistList_flag(artist_list) == 'a') {
                    char* aux_artist_id = get_ArtistList_artist_id(artist_list);
                    if (strcmp(aux_artist_id, max_artist_id) < 0) {
                        strcpy(max_artist_id, aux_artist_id);
                        free(aux_artist_id);
                        num_musics = get_ArtistList_n_musics(artist_list);

                    }
                }
            }
            if (max_artist_id != NULL) {
             
                char duration[16]; //size que garante que nao ha overflow
                int horas = max / 3600;
                int minutos = (max % 3600) / 60;
                int segundos = max % 60;
                sprintf(duration, "%02d:%02d:%02d", horas, minutos, segundos);
                printf("---> id: %s\n", max_artist_id);
                printf("---> Número de músicas distintas ouvidas: %d\n", num_musics);
                printf("---> Duração total: %s\n", duration);
                printf("\n");
                Artist_List *artist_list_1 = g_hash_table_lookup(al, max_artist_id);
                set_ArtistList_flag(artist_list_1, 'b');
                free(max_artist_id);
            }
            max = 0;
        }
    }

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
    // free(filename); nao falta isto ?

}